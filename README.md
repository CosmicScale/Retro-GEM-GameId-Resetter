# Retro GEM GameId Resetter for PlayStation 2

When using the Retro GEM with a special build of OPL that supports Game ID, the Game ID remains persistent when you quit the game (L1 + L2 + R1 + R2 + SELECT + START) and return to the OSD. It is only cleared when OPL is launched again or the console is powered off. This little app fixes that problem. With "Retro GEM GameId Resetter", when you quit a game, the Game ID is reset, and the Retro GEM settings are returned to global.

This is designed to be a companion app to my OPL build that not only supports Game ID for PS2 games but also PS1 games and any homebrew app launched with OPL. It also supports Game ID when games are launched with OPL-Launcher (https://github.com/ps2homebrew/OPL-Launcher) via the HDD-OSD or PSBBN. You can find my build of OPL [here](https://github.com/CosmicScale/Open-PS2-Loader-Retro-GEM).

## Instructions

1. Put the compiled `BOOT.ELF` file in a folder titled "BOOT" on a PS2 memory card in slot 0 or slot 1.
2. In OPL, go to "Settings" and set the "IGR Path" to `mc0:/BOOT/BOOT.ELF` for slot 0 or `mc1:/BOOT/BOOT.ELF` for slot 1.

## Notes

It is necessary to name the file and place it in this location for compatibility with Popstarter for PS1 games. If you are using FreeMCBoot in its default configuration, then uLaunchELF (ULE) will be in the BOOT folder also titled `BOOT.ELF`. You can rename this file to anything you like and then update the links to it using the "Free MCBoot Configurator".

## Credits

Written by CosmicScale. Uses code based on the AppCakeLtd gameid-with-gem fork of Open-PS2-Loader (https://github.com/AppCakeLtd/Open-PS2-Loader/tree/gameid-with-gem).
