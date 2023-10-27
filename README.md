# Pokémon Emerald

This is a fork of the [matching decompilation](https://github.com/pret/pokeemerald) at [PRET](https://github.com/pret).

This fork tries to maintain vanilla compatibility whenever possible. It doesn't increase the size of any save data structure or the object event structure.

There are several branches, each with one main feature (and sometimes some extra stuff):

**followers** branch:
* [HGSS-style pokémon followers](https://bulbapedia.bulbagarden.net/wiki/Walking_Pok%C3%A9mon#Pok.C3.A9mon_HeartGold_and_SoulSilver) for all 386 pokémon, including emotes, the 28 Unown forms and a majority of follower messages.
* Dynamic overworld palettes & reflections compatible with vanilla berry trees.
* PID (but not legitimacy) preserving Pokémon nature-changing function
* Function to detect modern emulators/GBA hardware.

**icons** branch:
* Everything from the **followers** branch.
* All pokemon icons updated to Gen 6, based on [this repo](https://github.com/msikma/pokesprite/tree/master/icons/pokemon/regular)
* This includes compatibility with the PC, trade, contests, mail, Battle Dome. Examples:
![PC](https://i.imgur.com/wzwJfd1.png)
![Party](https://i.imgur.com/8hbE88t.png)
![Contest](https://i.imgur.com/S9mCEFL.png)
* Icons share palettes with front sprites, meaning that shiny pokemon will also have shiny icons!

**lighting** branch:
* Everything from the **followers** branch.
* Day/night shading compatible with weather.
* GSC-style window lights.
* WIP interframe-blended lamp lights at night, i.e in Rustboro.
* HGSS-style alpha-blended shadows for object events.

Additional branches  to mention:

* `followers-expanded-id` - like `followers`, but includes backwards-compatible 16-bit graphics IDs for object events.
* `lighting-expanded-id` - like the above but for `lighting`.

To set up the repository, see [INSTALL.md](INSTALL.md).

## FAQ
### Q: How do I mark certain colors in a palette as light-blended?
A: Create a `.pla` file in the same folder as the `.pal` with the same name.

In this file you can enter color indices [0,15]
on separate lines to mark those colors as being light-blended, i.e:

`06.pla:`
```
# A comment
0 # if color 0 is listed, uses it to blend with instead of the default!
1
9
10
```

You might have to `make mostlyclean` or change the `.pal` file to pick up the changes.

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).