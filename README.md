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

## List of keybindings
| Key | Function | Argument |
| :-: | :-: | :- |
|  j | ACTION##stack |  INC(+1) |
|  k | ACTION##stack |  INC(-1) |
|  v | ACTION##stack |  0 |
| Control + Escape | spawns | dunstctl history-pop |
| Control + space | spawns | dunstctl close |
| Control + Shift + space | spawns | dunstctl close-all |
| Control + Shift + period | spawns | dunstctl context |
| Super + grave | spawns | dmenuunicode |
| Super + Shift + grave | spawns | dmoji |
| Super + 0 | view |  ~0 |
| Super + Shift + 0 | tag |  ~0 |
| Super + minus | spawns | vol down 5; kill -44 $(pidof dwmblocks) |
| Super + Shift + minus | spawns | vol down 15; kill -44 $(pidof dwmblocks) |
| Super + equal | spawns | vol up 5; kill -44 $(pidof dwmblocks) |
| Super + Shift + equal | spawns | vol up 15; kill -44 $(pidof dwmblocks) |
| Super + BackSpace | spawns | remaps |
| Super + Shift + BackSpace | spawns | remaps intl |
| Super + Tab | view |   |
| Super + Shift + Tab | spawns | xdotool key Caps_Lock |
| Super + q | killclient |   |
| Super + Shift + q | spawns | sysact |
| Super + w | spawns | vieb |
| Super + n | spawns | $BROWSER |
| Super + Shift + w | spawns | killall -q nmtui-connect  +  +  st -e nmtui-connect |
| Super + e | spawns | TERMINAL -e neomutt; pkill -RTMIN+12 dwmblocks |
| Super + Shift + e | spawns | TERMINAL -e abook |
| Super + r | spawns | TERMINAL -e lf |
| Super + Shift + r | spawns | killall -q btm  +  +  st -c sysMon -e btm |
| Super + y | setlayout |  spiral  |
| Super + Shift + y | setlayout |  dwindle  |
| Super + t | setlayout |  tile  |
| Super + Shift + t | setlayout |  bstack  |
| Super + u | setlayout |  deck  |
| Super + Shift + u | setlayout |  monocle  |
| Super + i | setlayout |  centeredmaster  |
| Super + Shift + i | setlayout |  centeredfloatingmaster  |
| Super + o | incnmaster |  +1 |
| Super + Shift + o | incnmaster |  -1 |
| Super + p | spawns | mpc -q toggle; spot-cli -t |
| Super + Shift + p | spawns | mpc -q stop; pauseallmpv; spot-cli -s |
| Super + bracketleft | spawns | mpc -q seek -10; spot-cli --seek -10 |
| Super + Shift + bracketleft | spawns | mpc -q seek -60; spot-cli --seek -60 |
| Super + bracketright |spawns | mpc -q seek +10; spot-cli --seek +10 |
| Super + Shift + bracketright |spawns | mpc -q seek +60; spot-cli --seek +60 |
| Super + backslash | view |   |
| Super + Shift + backslash | setlayout |  grid  |
| Super + a | togglegaps |   |
| Super + Shift + a | defaultgaps |   |
| Super + s | togglesticky |   |
| Super + Shift + s | spawns | killall -q screenkey  +  +  screenkey & |
| Super + d | spawns | menu |
| Super + Shift + d | spawns | dscg |
| Super + f | togglefullscr |   |
| Super + Shift + f | setlayout |  float |
| Super + g | shiftview |  -1 |
| Super + Shift + g | shifttag |  -1 |
| Super + h | setmfact |  -0.05 |
| Super + Shift + h | togglescratch |  4 |
| Super + l | setmfact |  +0.05 |
| Super + Shift + l | spawns | dweb |
| Super + Shift + apostrophe | spawns | dweb-hist |
| Super + semicolon | shiftview |  1 |
| Super + Shift + semicolon | shifttag |  1 |
| Super + Return | spawns |  |
| Super + Shift + Return | togglescratch |  0 |
| Super + Control + Return | spawns | wezterm |
| Super + Mod1 + Return | spawns | tabbed -c -r 2 st -w id |
| Super + z | incrogaps |  +3 |
| Super + Shift + z | togglescratch |  3 |
| Super + x | incrogaps |  -3 |
| Super + Shift + x | spawns | togcomp |
| Super + Shift + c | togglescratch |  1 |
| Super + c | spawns | cb |
| Super + Mod1 + c | spawns | cqctl toggle |
| Super + b | togglebar |   |
| Super + Shift + b | togglescratch |  2 |
| Super + Shift + n | spawns | TERMINAL -e newsboat |
| Super + m | spawns | setsid -f st -c ncmpcpp -e ncmpcpp -s playlist -S visualizer; kunst --silent |
| Super + Shift + m | spawns | vol toggle; kill -44 $(pidof dwmblocks) |
| Super + comma | spawns | mpc -q prev; spot-cli -p |
| Super + Shift + comma | spawns | mpc -q seek 0%; spot-cli --set 0 |
| Super + period | spawns | mpc -q next; spot-cli -n |
| Super + Shift + period | spawns | mpc -q repeat |
| Super + Left | focusmon |  -1 |
| Super + Shift + Left | tagmon |  -1 |
| Super + Right | focusmon |  +1 |
| Super + Shift + Right | tagmon |  +1 |
| Super + Page_Up | shiftview |  -1 |
| Super + Shift + Page_Up | shifttag |  -1 |
| Super + Page_Down | shiftview |  +1 |
| Super + Shift + Page_Down | shifttag |  +1 |
| Super + Insert | spawns | notify-send \"📋 Clipboard contents:\" \"$(xclip -o -selection clipboard)\" |
| Super + F1 | spawns | mpc -q pause && mpc -q toggleoutput MPD && mpc -q toggleoutput MPD && mpc -q play |
| Super + F2 | spawns | btmenu |
| Super + F3 | spawns | displayselect |
| Super + F4 | spawns | TERMINAL -e pulsemixer; kill -44 $(pidof dwmblocks) |
| Super + F6 | spawns | torwrap |
| Super + F7 | spawns | qbtoggle |
| Super + F8 | spawns | mw -Y |
| Super + F9 | spawns | dmenumount |
| Super + F10 | spawns | dmenuumount |
| Super + F11 | spawns | camtoggle |
| Super + space | zoom |   |
| Super + Shift + space | togglefloating |   |
| Print | spawns | maim -u pic-full-$(date '+%y%m%d-%H%M-%S').png |
| Shift + Print | spawns | maimpick |
| Super + Print | spawns | dmenurecord |
| Super + Shift + Print | spawns | dmenurecord kill |
| Super + Delete | spawns | dmenurecord kill |
| AudioMute | spawns | vol toggle; kill -44 $(pidof dwmblocks) |
| AudioRaiseVolume | spawns | vol up 5; kill -44 $(pidof dwmblocks) |
| AudioLowerVolume | spawns | vol down 5; kill -44 $(pidof dwmblocks) |
| AudioPrev | spawns | mpc -q prev; spot-cli -p |
| AudioNext | spawns | mpc -q next; spot-cli -n |
| AudioPause | spawns | mpc -q pause; spot-cli --pause |
| AudioPlay | spawns | mpc -q play; spot-cli --play |
| AudioStop | spawns | mpc -q stop; spot-cli -s |
| PowerOff | spawns | sysact |
| ScreenSaver | spawns | br set 0 && slock & mpc -q pause; pauseallmpv |
| TouchpadToggle | spawns | touchpadtoggle |
| MonBrightnessUp | spawns | br inc 2 |
| MonBrightnessDown | spawns | br dec 2 |

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
