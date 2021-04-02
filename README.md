### Additions to luke's build

This is Luke's build of dwm with edits for my own [setup](https://github.com/BachoSeven/mydotFiles);
a part from keybindings and additional or different scratchpads/programs, I have added the following eye-candy patches:

- barpadding :)
- colorbar for colors in titles and tag indicators
- noborder (fixed for floating windows)
- borderbar
- alpha (bar transparency)
- cool autostart
- save floats (remembers floating windows' geometries)
- float rules
- gestures (for the touchpad)
- noborderfloatingfix
- tagothermonitor (bindings to move windows between monitors)
- grid mode (new layout)
- resizepoint (stabler and more intuitive resizing)

## FAQ

> What are the bindings?

This is suckless, mmmbud, the source code is the documentation! Check out [config.h](config.h).

Okay, okay, actually I keep a readme in `larbs.mom` for my whole system, including the binds here.
Press `super+F1` to view it in dwm (zathura is required for that binding).
I haven't kept `man dwm`/`dwm.1` updated though. PRs welcome on that, lol.

## Patches and features

- Clickable statusbar with my build of [dwmblocks](https://github.com/lukesmithxyz/dwmblocks).
- Reads xresources colors/variables (i.e. works with `pywal`, etc.).
- scratchpad: Accessible with mod+shift+enter.
- New layouts: bstack, fibonacci, deck, centered master and more. All bound to keys `super+(shift+)t/y/u/i`.
- True fullscreen (`super+f`) and prevents focus shifting.
- Windows can be made sticky (`super+s`).
- stacker: Move windows up the stack manually (`super-K/J`).
- shiftview: Cycle through tags (`super+g/;`).
- vanitygaps: Gaps allowed across all layouts.
- swallow patch: if a program run from a terminal would make it inoperable, it temporarily takes its place to save space.

## Installation for newbs

```
git clone https://github.com/LukeSmithxyz/dwm
cd dwm
sudo make install
```

Users of Arch-based distros can also install it from the AUR as [dwm-luke-git](https://aur.archlinux.org/packages/dwm-luke-git).

## Please install `libxft-bgra`!

This build of dwm does not block color emoji in the status/info bar, so you must install [libxft-bgra](https://aur.archlinux.org/packages/libxft-bgra/) from the AUR, which fixes a libxft color emoji rendering problem, otherwise dwm will crash upon trying to render one. Hopefully this fix will be in all libxft soon enough.
