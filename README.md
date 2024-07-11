# Retro GEM Game ID Resetter for PlayStation 2

When using the Retro GEM with a special build of OPL that supports Game ID, the Game ID remains persistent when you quit the game (L1 + L2 + R1 + R2 + SELECT + START) and return to the OSD. It is only cleared when OPL is launched again or the console is powered off. This little app fixes that problem. With the "Retro GEM Game ID Resetter", when you quit a game, the Game ID is reset, and the Retro GEM settings are returned to global.

This is designed to be a companion app to my OPL build that not only supports Game ID for PS2 games but also PS1 games and any homebrew app launched with OPL. It also supports Game ID when games are launched with [OPL-Launcher](https://github.com/ps2homebrew/OPL-Launcher) via the HDD-OSD or PSBBN. You can find my build of OPL [here](https://github.com/CosmicScale/Open-PS2-Loader-Retro-GEM).

## Instructions

1. Put the `BOOT` folder on a PS2 memory card in memory card slot 0.
2. In OPL, go to `Settings` and set the `IGR Path` to `mc0:/BOOT/BOOT.ELF`.

## Notes

This application must be in a folder titled `BOOT` for compatibility with Popstarter and PS1 games. If you are using FreeMCBoot in its default configuration, then you will have the FreeMCBoot memory card in memory card slot 1, `LaunchELF` will be in the `BOOT` folder on this card, also titled `BOOT.ELF`. Make sure to update the links for `LaunchELF` using the "Free MCBoot Configurator" so that they all point to slot 1.

## Credits

Written by [CosmicScale](https://github.com/CosmicScale). Uses code based on the [AppCakeLtd gameid-with-gem fork of Open-PS2-Loader](https://github.com/AppCakeLtd/Open-PS2-Loader/tree/gameid-with-gem).