This is the build of dwm for my Arch [setup](https://github.com/BachoSeven/dotfiles);
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

### Other patches & features borrowed from luke's build:

- Clickable statusbar with [dwmblocks](https://github.com/bachoseven/dwmblocks).
- Reads xresources colors/variables (i.e. works with `pywal`, etc.).
- scratchpad: Accessible with mod+shift+enter.
- New layouts: bstack, fibonacci, deck, centered master and more. All bound to keys `super+(shift+)t/y/u/i`.
- True fullscreen (`super+f`) and prevents focus shifting.
- Windows can be made sticky (`super+s`).
- stacker: Move windows up the stack manually (`super-K/J`).
- shiftview: Cycle through tags (`super+g/;`).
- vanitygaps: Gaps allowed across all layouts.
- swallow patch: if a program run from a terminal would make it inoperable, it temporarily takes its place to save space.
