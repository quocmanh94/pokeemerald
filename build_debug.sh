#!/bin/bash

# Define IP
IP=$(ipconfig.exe | grep 'vEthernet (WSL)' -A4 | cut -d ":" -f 2 | tail -n1 | sed -e 's/\s*//g')
echo "Your IP address: $IP"

# Define the content for tasks.json
CONTENT_TASK=$(cat <<EOL
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "make debug",
            "type": "shell",
            "command": "\${workspaceFolder}/.vscode/commands.sh",
            "args": ["clean_and_build"],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": "\$gcc"
        },
        {
            "label": "stop emulation",
            "type": "shell",
            "command": "\${workspaceFolder}/.vscode/commands.sh",
            "args": ["stop_emulation"]
        }
    ]
}
EOL
)

# Write the content to tasks.json
echo "$CONTENT_TASK" > .vscode/tasks.json
echo "tasks.json created successfully!"

# Define the content for launch.json
CONTENT_LAUNCH=$(cat <<EOL
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "mGBA-debug",
            "type": "cppdbg",
            "request": "launch",
            "preLaunchTask": "make debug",
            "serverLaunchTimeout": 10000,
            "postDebugTask": "stop emulation",
            "program": "\${workspaceFolder}/pokeemerald_modern.elf",
            "args": [
                "target remote $IP:2345"
            ],
            "stopAtEntry": true,
            "cwd": "\${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "miDebuggerServerAddress": "$IP:2345",
            "debugServerArgs": "\${workspaceFolder}/pokeemerald_modern.elf",
            "serverStarted": "started",
            "linux": {
                "MIMode": "gdb",
                "miDebuggerPath": "/opt/devkitpro/devkitARM/bin/arm-none-eabi-gdb",
                "debugServerPath": "\${workspaceFolder}/.vscode/mgba.sh"
            }
        }
    ]
}
EOL
)

# Write the content to launch.json
echo "$CONTENT_LAUNCH" > .vscode/launch.json
echo "launch.json created successfully!"

# Define the content for tasks.json
CONTENT_CPP=$(cat <<EOL
{
    "version": 4,
    "configurations": [
        {
            "name": "GBA",
            "includePath": [
                "\${workspaceFolder}",
                "\${workspaceFolder}/include",
                "\${workspaceFolder}/gflib",
                "\${workspaceFolder}/tools/"
            ],
            "defines": [
                "DEBUG",
                "_DEBUG",
                "UNICODE",
                "_UNICODE",
                "DINFO",
                "_MSC_VER"
            ],
            "intelliSenseMode": "gcc-arm",
            "browse": {
                "path": [
                    "\${workspaceFolder}"
                ],
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": ""
            },
            "cStandard": "c99",
            "compilerPath": "/opt/devkitpro/devkitARM/bin/arm-none-eabi-gcc"
        }
    ]
}
EOL
)

# Write the content to c_cpp_properties.json
echo "$CONTENT_CPP" > .vscode/c_cpp_properties.json
echo "c_cpp_properties.json created successfully!"

# Write the content to commands.sh
cat > .vscode/commands.sh <<EOL
#!/bin/bash

case "\$1" in
    "clean_and_build")
        clear && make clean && make DINFO=1 modern -j\$(nproc)
        ;;
    "stop_emulation")
        powershell.exe -Command Stop-Process -Name mGBA -Force 2>/dev/null
        ;;
    *)
        echo "Unknown case!"
        ;;
esac
EOL

echo "commands.sh created successfully!"

# Write the content to mgba.sh
cat > .vscode/mgba.sh <<EOL
#!/bin/bash

(
	sleep 4
	echo "started"
)&

/mnt/c/mGBA/mGBA.exe \$1 -g # The path you have extracted mGBA in Windows
EOL

echo "mgba.sh created successfully!"

# chmod
chmod +x .vscode/commands.sh
chmod +x .vscode/mgba.sh