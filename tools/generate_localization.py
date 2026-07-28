#!/usr/bin/env python3
"""Regenerate the runtime English/Vietnamese string tables.

Vietnamese text lives in the normal source files. The English text is read from
the commit before "[ADD] Runtime English And Vietnamese Localization", so after
editing Vietnamese text run, from the repository root:

    python3 tools/generate_localization.py

It rewrites src/localization_generated.c, data/localization_strings.inc,
data/localization.s and the export blocks at the end of the translated files.
"""
import argparse
import collections
import pathlib
import re
import subprocess


ROOT = pathlib.Path(__file__).resolve().parents[1]
C_BEGIN = "// BEGIN GENERATED LOCALIZATION EXPORTS"
C_END = "// END GENERATED LOCALIZATION EXPORTS"
ASM_BEGIN = "@ BEGIN GENERATED LOCALIZATION EXPORTS"
ASM_END = "@ END GENERATED LOCALIZATION EXPORTS"
LOCALIZATION_COMMIT_SUBJECT = "[ADD] Runtime English And Vietnamese Localization"

ASM_STRING_RE = re.compile(
    r"(?ms)^(?P<label>[A-Za-z_][A-Za-z0-9_]*)(?P<sep>::|:)[ \t]*\n"
    r"(?P<body>(?:[ \t]*\.string[^\n]*\n)+)"
)
C_STRING_RE = re.compile(
    r"(?ms)^(?P<decl>[ \t]*(?:ALIGNED\([^\n)]+\)[ \t]+)?(?:static[ \t]+)?const[ \t]+u8[ \t]+"
    r"(?P<name>[A-Za-z_][A-Za-z0-9_]*)[ \t]*\[[^\]]*\][ \t]*=[ \t]*_\()"
    r"(?P<body>.*?)(?P<end>\);)"
)
C_STRING_TABLE_RE = re.compile(
    r"(?ms)^[ \t]*(?:static[ \t]+)?const[ \t]+u8[ \t]+"
    r"(?P<name>[A-Za-z_][A-Za-z0-9_]*)"
    r"(?P<dimensions>(?:[ \t]*\[[^\]]*\]){2,})[ \t]*=[ \t\r\n]*\{\n"
    r"(?P<body>.*?)^\};"
)
C_STRING_TABLE_ENTRY_RE = re.compile(
    r"(?ms)^[ \t]*\[(?P<index>[A-Za-z_][A-Za-z0-9_]*)\][ \t]*=[ \t]*_\("
    r"(?P<body>.*?)\)[ \t]*,?[ \t]*$"
)
CATEGORY_RE = re.compile(r"(?ms)\.categoryName[ \t]*=[ \t]*_\((?P<body>.*?)\),")
CONTROL_RE = re.compile(r"\{[^}]+\}|\\[npl]")
PLACEHOLDER_RE = re.compile(r"\{[^}]+\}")
LINE_CONTROL_RE = re.compile(r"\\[npl]")


def run_git(*args):
    result = subprocess.run(
        ["git", *args],
        cwd=ROOT,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    if result.returncode != 0:
        raise RuntimeError(result.stderr.decode("utf-8", errors="replace"))
    return result.stdout.decode("utf-8")


def read_base_file(base_ref, path):
    result = subprocess.run(
        ["git", "show", f"{base_ref}:{path}"],
        cwd=ROOT,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,
    )
    if result.returncode != 0:
        return None
    return result.stdout.decode("utf-8")


def strip_generated_block(text, begin, end):
    pattern = re.compile(rf"\n?{re.escape(begin)}.*?{re.escape(end)}\n?", re.S)
    return pattern.sub("\n", text).rstrip() + "\n"


def strip_existing_generated_content(text):
    text = strip_generated_block(text, C_BEGIN, C_END)
    return strip_generated_block(text, ASM_BEGIN, ASM_END)


def write_text(path, text):
    full_path = ROOT / path
    full_path.parent.mkdir(parents=True, exist_ok=True)
    full_path.write_text(text, encoding="utf-8")


def controls(body):
    return collections.Counter(CONTROL_RE.findall(body))


def collect_entries(base_ref):
    changed_paths = run_git("diff", "--name-only", base_ref).splitlines()
    ignored = {
        "data/localization.s",
        "data/localization_strings.inc",
        "src/localization_generated.c",
        "tools/generate_localization.py",
    }
    asm_groups = []
    c_groups = []
    current_texts = {}
    placeholder_mismatches = []

    for path in changed_paths:
        if path in ignored:
            continue
        full_path = ROOT / path
        if not full_path.is_file():
            continue
        try:
            current = full_path.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            continue
        original = read_base_file(base_ref, path)
        if original is None:
            continue

        current = strip_existing_generated_content(current)
        current_texts[path] = current

        current_asm = {
            match.group("label"): match
            for match in ASM_STRING_RE.finditer(current)
            if not match.group("label").endswith("_English")
        }
        original_asm = {
            match.group("label"): match
            for match in ASM_STRING_RE.finditer(original)
        }
        asm_entries = []
        for label, match in current_asm.items():
            old_match = original_asm.get(label)
            if old_match is None or match.group("body") == old_match.group("body"):
                continue
            entry = {
                "path": path,
                "name": label,
                "position": match.start(),
                "vietnamese": match.group("body"),
                "english": old_match.group("body"),
            }
            asm_entries.append(entry)
            if controls(entry["vietnamese"]) != controls(entry["english"]):
                placeholder_mismatches.append(entry)
        if asm_entries:
            asm_groups.append((path, sorted(asm_entries, key=lambda item: item["position"])))

        current_c = {match.group("name"): match for match in C_STRING_RE.finditer(current)}
        original_c = {match.group("name"): match for match in C_STRING_RE.finditer(original)}
        c_entries = []
        for name, match in current_c.items():
            old_match = original_c.get(name)
            if old_match is None or match.group("body") == old_match.group("body"):
                continue
            entry = {
                "path": path,
                "name": name,
                "position": match.start(),
                "vietnamese": match.group("body"),
                "english": old_match.group("body"),
            }
            c_entries.append(entry)
            if controls(entry["vietnamese"]) != controls(entry["english"]):
                placeholder_mismatches.append(entry)

        current_tables = {match.group("name"): match for match in C_STRING_TABLE_RE.finditer(current)}
        original_tables = {match.group("name"): match for match in C_STRING_TABLE_RE.finditer(original)}
        for table_name, table_match in current_tables.items():
            old_table_match = original_tables.get(table_name)
            if old_table_match is None:
                continue
            current_entries = {
                match.group("index"): match
                for match in C_STRING_TABLE_ENTRY_RE.finditer(table_match.group("body"))
            }
            original_entries = {
                match.group("index"): match
                for match in C_STRING_TABLE_ENTRY_RE.finditer(old_table_match.group("body"))
            }
            for index, match in current_entries.items():
                old_match = original_entries.get(index)
                if old_match is None or match.group("body") == old_match.group("body"):
                    continue
                entry = {
                    "path": path,
                    "name": f"{table_name}_{index}",
                    "source": f"{table_name}[{index}]",
                    "position": table_match.start("body") + match.start(),
                    "vietnamese": match.group("body"),
                    "english": old_match.group("body"),
                }
                c_entries.append(entry)
                if controls(entry["vietnamese"]) != controls(entry["english"]):
                    placeholder_mismatches.append(entry)
        if c_entries:
            c_groups.append((path, sorted(c_entries, key=lambda item: item["position"])))

    asm_groups.sort(key=lambda item: item[0])
    c_groups.sort(key=lambda item: item[0])
    return current_texts, asm_groups, c_groups, placeholder_mismatches


def assign_ids(asm_groups, c_groups):
    for index, entry in enumerate(entry for _, group in asm_groups for entry in group):
        entry["id"] = f"A{index:05d}"
    for index, entry in enumerate(entry for _, group in c_groups for entry in group):
        entry["id"] = f"C{index:05d}"


def append_source_exports(current_texts, asm_groups, c_groups):
    asm_by_path = dict(asm_groups)
    c_by_path = dict(c_groups)
    for path in sorted(set(asm_by_path) | set(c_by_path)):
        text = current_texts[path].rstrip() + "\n"
        if path in asm_by_path:
            lines = ["", ASM_BEGIN]
            lines.extend(f"\t.global {entry['name']}" for entry in asm_by_path[path])
            lines.append(ASM_END)
            text += "\n".join(lines) + "\n"
        if path in c_by_path:
            lines = ["", C_BEGIN]
            lines.append("// These pointers expose file-local translated strings to the runtime resolver.")
            lines.extend(
                f"const u8 *const gLocalizationSource_{entry['id']} = {entry.get('source', entry['name'])};"
                for entry in c_by_path[path]
            )
            lines.append(C_END)
            text += "\n".join(lines) + "\n"
        write_text(path, text)


def generate_asm_bank(asm_groups):
    lines = [
        "@ This file is generated by tools/generate_localization.py.",
        "",
    ]
    for group_index, (_, entries) in enumerate(asm_groups):
        lines.append("\t.align 2")
        lines.append(f"gLocalizationAsmGroupPairs_{group_index:04d}:")
        for entry in entries:
            lines.append(f"\t.4byte {entry['name']}")
            lines.append(f"\t.4byte gLocalizationEnglish_{entry['id']}")
        lines.append("")

    lines.extend(["\t.align 2", "gLocalizationAsmGroups::"])
    for group_index, (_, entries) in enumerate(asm_groups):
        lines.append(f"\t.4byte gLocalizationAsmGroupPairs_{group_index:04d}")
        lines.append(f"\t.2byte {len(entries)}")
        lines.append("\t.2byte 0")
    lines.extend(["gLocalizationAsmGroupsEnd::", ""])

    for _, entries in asm_groups:
        for entry in entries:
            lines.append(f"gLocalizationEnglish_{entry['id']}:")
            lines.extend(entry["english"].rstrip().splitlines())
            lines.append("")

    write_text("data/localization_strings.inc", "\n".join(lines))
    write_text(
        "data/localization.s",
        "\t.include \"asm/macros.inc\"\n"
        "\t.include \"constants/constants.inc\"\n\n"
        "\t.section .rodata\n\n"
        "\t.include \"data/localization_strings.inc\"\n",
    )


def extract_category_bodies(base_ref):
    path = "src/data/pokemon/pokedex_entries.h"
    original = read_base_file(base_ref, path)
    if original is None:
        return []
    return [match.group("body") for match in CATEGORY_RE.finditer(original)]


def generate_c_bank(base_ref, c_groups):
    entries = [entry for _, group in c_groups for entry in group]
    lines = [
        "// This file is generated by tools/generate_localization.py.",
        "#include \"global.h\"",
        "#include \"localization.h\"",
        "",
    ]
    for entry in entries:
        lines.append(f"extern const u8 *const gLocalizationSource_{entry['id']};")
    lines.append("")
    for entry in entries:
        lines.append(f"static const u8 sLocalizationEnglish_{entry['id']}[] = _(")
        lines.extend(entry["english"].rstrip().splitlines())
        lines.append(");")
        lines.append("")

    for group_index, (_, group) in enumerate(c_groups):
        lines.append(f"static const struct LocalizationIndirectPair sLocalizationCGroupPairs_{group_index:04d}[] =")
        lines.append("{")
        for entry in group:
            lines.append(
                f"    {{&gLocalizationSource_{entry['id']}, sLocalizationEnglish_{entry['id']}}},"
            )
        lines.extend(["};", ""])

    lines.extend(["const struct LocalizationIndirectGroup gLocalizationCGroups[] =", "{"])
    for group_index, _ in enumerate(c_groups):
        lines.append(
            f"    {{sLocalizationCGroupPairs_{group_index:04d}, "
            f"ARRAY_COUNT(sLocalizationCGroupPairs_{group_index:04d})}},"
        )
    lines.extend(["};", "", "const u32 gLocalizationCGroupCount = ARRAY_COUNT(gLocalizationCGroups);", ""])

    categories = extract_category_bodies(base_ref)
    for index, body in enumerate(categories):
        lines.append(f"static const u8 sLocalizationCategoryEnglish_{index:03d}[] = _({body});")
    lines.extend(["", "const u8 *const gLocalizationPokedexCategoriesEnglish[] =", "{"])
    lines.extend(f"    sLocalizationCategoryEnglish_{index:03d}," for index in range(len(categories)))
    lines.extend(
        [
            "};",
            "",
            "const u32 gLocalizationPokedexCategoryCount = ARRAY_COUNT(gLocalizationPokedexCategoriesEnglish);",
            "",
        ]
    )
    write_text("src/localization_generated.c", "\n".join(lines))


def generate_report(report_path, asm_groups, c_groups, placeholder_mismatches):
    asm_count = sum(len(group) for _, group in asm_groups)
    c_count = sum(len(group) for _, group in c_groups)
    entries = [entry for _, group in asm_groups + c_groups for entry in group]
    variable_mismatches = [
        entry
        for entry in entries
        if collections.Counter(PLACEHOLDER_RE.findall(entry["vietnamese"]))
        != collections.Counter(PLACEHOLDER_RE.findall(entry["english"]))
    ]
    line_control_mismatches = [
        entry
        for entry in entries
        if collections.Counter(LINE_CONTROL_RE.findall(entry["vietnamese"]))
        != collections.Counter(LINE_CONTROL_RE.findall(entry["english"]))
    ]
    lines = [
        "# Runtime Localization Generation Audit",
        "",
        f"- ASM/script pairs: **{asm_count}** across **{len(asm_groups)}** files.",
        f"- C string pairs: **{c_count}** across **{len(c_groups)}** files.",
        f"- Variable placeholder differences: **{len(variable_mismatches)}**.",
        f"- Line-control differences (`\\n`, `\\l`, `\\p`): **{len(line_control_mismatches)}**.",
        "- Vietnamese source strings were not rewritten; only generated export blocks were appended.",
        "",
        "## Variable Placeholder Differences",
        "",
        "These entries require review but are intentionally not modified by the generator.",
        "",
    ]
    for entry in variable_mismatches:
        lines.append(f"- `{entry['path']}` `{entry['name']}`")
        lines.append(
            f"  - VI: `{dict(collections.Counter(PLACEHOLDER_RE.findall(entry['vietnamese'])))}`"
        )
        lines.append(
            f"  - EN: `{dict(collections.Counter(PLACEHOLDER_RE.findall(entry['english'])))}`"
        )
    write_text(report_path, "\n".join(lines) + "\n")


def find_english_base():
    # The English text is the tree just before the localization commit.
    commit = next(
        (
            line.split(" ", 1)[0]
            for line in run_git("log", "--format=%H %s", "HEAD").splitlines()
            if line.split(" ", 1)[1:] == [LOCALIZATION_COMMIT_SUBJECT]
        ),
        None,
    )
    if commit is None:
        raise SystemExit(f"Commit '{LOCALIZATION_COMMIT_SUBJECT}' not found; pass --base-ref.")
    return f"{commit}^"


def main():
    parser = argparse.ArgumentParser(
        description="Regenerate the English side of the runtime localization from git history."
    )
    parser.add_argument("--base-ref", help="Commit with the English text (default: parent of the localization commit)")
    parser.add_argument("--report", help="Optional path for a Markdown report of placeholder differences")
    args = parser.parse_args()
    base_ref = args.base_ref or find_english_base()

    current_texts, asm_groups, c_groups, mismatches = collect_entries(base_ref)
    assign_ids(asm_groups, c_groups)
    append_source_exports(current_texts, asm_groups, c_groups)
    generate_asm_bank(asm_groups)
    generate_c_bank(base_ref, c_groups)
    if args.report:
        generate_report(args.report, asm_groups, c_groups, mismatches)

    print(f"Generated {sum(len(group) for _, group in asm_groups)} ASM pairs")
    print(f"Generated {sum(len(group) for _, group in c_groups)} C pairs")
    print(f"Reported {len(mismatches)} placeholder/control-code differences")


if __name__ == "__main__":
    main()
