/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static unsigned int borderpx  = 3;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static unsigned int gappih    = 18;       /* horiz inner gap between windows */
static unsigned int gappiv    = 18;       /* vert inner gap between windows */
static unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
static int vertpad            = 8;        /* vertical padding of bar */
static int sidepad            = 8;        /* horizontal padding of bar */
static char *fonts[]          = { "monospace:size=16", "Noto Color Emoji:antialias=true:autohint=true", "Sarasa Mono K:size=16:antialias=true:autohint=true" };
static char normfgcolor[]		= "#bbbbbb";
static char normbgcolor[]		= "#222222";
static char normbordercolor[]		= "#444444";
static char selfgcolor[]		= "#eeeeee";
static char selbgcolor[]		= "#005577";
static char selbordercolor[]		= "#770000";
static char statusfg[]			= "#ebdbb2";
static char statusbg[]			= "#282828";
static char statusborder[]		= "#1d2021";
static char tagnormfg[]			= "#ebdbb2";
static char tagnormbg[]			= "#282828";
static char tagnormborder[]		= "#1d2021";
static char tagselfg[]			= "#ebdbb2";
static char tagselbg[]			= "#005577";
static char tagselborder[]		= "#1d2021";
static char infonormfg[]		= "#ebdbb2";
static char infonormbg[]		= "#282828";
static char infonormborder[]		= "#1d2021";
static char infoselfg[]			= "#ebdbb2";
static char infoselbg[]			= "#005577";
static char infoselborder[]		= "#1d2021";
static char borderbar[]			= "#dd5555";
static const unsigned int baralpha = 0xe0; // 88% transparency (224/255 in decimal)
static const unsigned int borderalpha = OPAQUE;

static char *colors[][3] = {
       /*               fg           bg           border   */
	[SchemeNorm]  	 = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  	 = { selfgcolor,  selbgcolor,  selbordercolor  },
	[SchemeStatus]   = { statusfg, statusbg, statusborder  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsNorm] = { tagnormfg, tagnormbg, tagnormborder }, // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { tagselfg, tagselbg, tagselborder }, // Tagbar left selected {text,background,not used but cannot be empty}
	[SchemeInfoNorm] = { infonormfg, infonormbg, infonormborder }, // infobar middle  unselected {text,background,not used but cannot be empty}
	[SchemeInfoSel]  = { infoselfg, infoselbg, infoselborder }, // infobar middle  selected {text,background,not used but cannot be empty}
};

static const unsigned int alphas[][3]      = {
	/*			fg      bg        border     */
	[SchemeNorm]	 = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  	 = { OPAQUE, baralpha, borderalpha },
	[SchemeStatus]   = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeInfoNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeInfoSel]  = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
const char *spcmd3[] = {TERMINAL, "-n", "spbm", "-g", "120x30", "-e", "bm", "popup", NULL };
const char *spcmd4[] = {TERMINAL, "-n", "spkp", "-g", "120x40", "-e", "keepassxc", NULL };
const char *spcmd5[] = {TERMINAL, "-n", "sphist", "-g", "130x35", "-e", "hi", "popup", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
	{"spbm",	spcmd3},
	{"spkp",	spcmd4},
	{"sphist",	spcmd5},
};

static const char *const autostart[] = {
	TERMINAL, "-e", "welcome", NULL,
	TERMINAL, "-c", "sysMon", "-e", "btm", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "阮" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    		instance    	title			tags mask	isfloating isterminal noswallow  monitor  float x,y */
	{ TERMCLASS,		NULL,		NULL,			0,              0,		1,	0,	-1,	 	0,0},
	{ "Chromium",		NULL,		NULL,			1 << 0,         0,		0,	1,	-1,	 	0,0},
	{ "Vieb",		NULL,		NULL,			1 << 0,         0,		0,	1,	-1,	 	0,0},
	{ "sysMon",		NULL,		NULL,			1 << 1,		0,		1,	0,	-1,	 	0,0},
	{ "Scripting",		NULL,		NULL,			1 << 3,		0,		1,	0,	-1,	 	0,0},
	{ "SoulseekQt",		NULL,		NULL,			1 << 5,         0,		1,	0,	-1,	 	0,0},
	{ "ncspot",		NULL,   	NULL,			1 << 8,         0,		1,	0,	-1,	 	0,0},
	{ "Spotify",		NULL,		NULL,			1 << 8,         0,		0,	0,	-1,	 	0,0}, // this actualy works, thanks to https://github.com/dasJ/spotifywm
	{ "ncmpcpp",		NULL,   	NULL,			1 << 8,         0,		1,	0,	-1,	 	0,0},
	{ "Primephonic",	NULL,		NULL,			1 << 8,         0,		0,	1,	-1,	 	0,0},
	{ "Zathura",		NULL,   	NULL,			0,              0,		0,	1,	-1,	 	0,0},
	{ "copyq",		NULL,   	NULL,			0,              1,		0,	0,	-1,	 	0,0},
	{ "Dragon-drag-and-drop",NULL,		NULL,			0,              1,		0,	1,	-1,	 	100,100},
	{ NULL,			NULL,   	"Event Tester",   	0,		0,		0,	1,	-1,	 	0,0}, // Xev
        { NULL,			"Kunst",	NULL,             	1 << 8,         1,		0,	0,	-1,	 	0,0},
	{ NULL,			"spterm",	NULL,       	   	SPTAG(0),       1,		1,	0,	-1,	 	0,0},
	{ NULL,			"spcalc",	NULL,       	   	SPTAG(1),       1,		1,	0,	-1,	 	0,0},
	{ NULL,			"spbm",		NULL,       	   	SPTAG(2),       1,		1,	0,	-1,	 	0,0},
	{ NULL,			"spkp",		NULL,       	   	SPTAG(3),       1,		1,	0,	-1,	 	0,0},
	{ NULL,			"sphist",	NULL,       	   	SPTAG(4),       1,		1,	0,	-1,	 	0,0},
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "grid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",	spiral },		/* Deafult: Fibonacci spiral */
	{ "",	bstack },		/* Master on top, slaves on bottom */

 	{ "﬿",	tile },			/* Master on left, slaves on right */
	{ "侀",	dwindle },		/* Decreasing in size right and leftward */

	{ "",	deck },			/* Master on left, slaves in monocle-like mode on right */
 	{ "",	monocle },		/* All windows on top of eachother */

	{ "恵",	centeredmaster },		/* Master in middle, slaves on sides */
	{ "",	centeredfloatingmaster },	/* Same but master floats */

	{ "", grid },			/* Grid layout */
	{ "",	NULL },			/* no layout function means floating behavior */
	{ NULL, NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask|ShiftMask,    KEY,      tagprevmon,     {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "normfgcolor",	STRING, &normfgcolor},
		{ "normbgcolor",	STRING, &normbgcolor},
		{ "normbordercolor",	STRING, &normbordercolor},
		{ "selfgcolor",		STRING, &selfgcolor},
		{ "selbgcolor",		STRING, &selbgcolor},
		{ "selbordercolor",	STRING, &selbordercolor},
		{ "statusfg",		STRING, &statusfg},
		{ "statusbg",		STRING, &statusbg},
		{ "statusborder",	STRING, &statusborder},
		{ "tagnormfg",		STRING, &tagnormfg},
		{ "tagnormbg",		STRING, &tagnormbg},
		{ "tagnormborder",	STRING, &tagnormborder},
		{ "tagselfg",		STRING, &tagselfg},
		{ "tagselbg",		STRING, &tagselbg},
		{ "tagselborder",	STRING, &tagselborder},
		{ "infonormfg",		STRING, &infonormfg},
		{ "infonormbg",		STRING, &infonormbg},
		{ "infonormborder",	STRING, &infonormborder},
		{ "infoselfg",		STRING, &infoselfg},
		{ "infoselbg",		STRING, &infoselbg},
		{ "infoselborder",	STRING, &infoselborder},
		{ "borderbar",		STRING, &borderbar},
		{ "borderpx",		INTEGER, &borderpx },
		{ "snap",		INTEGER, &snap },
		{ "showbar",		INTEGER, &showbar },
		{ "topbar",		INTEGER, &topbar },
		{ "nmaster",		INTEGER, &nmaster },
		{ "resizehints",	INTEGER, &resizehints },
		{ "mfact",		FLOAT,	&mfact },
		{ "gappih",		INTEGER, &gappih },
		{ "gappiv",		INTEGER, &gappiv },
		{ "gappoh",		INTEGER, &gappoh },
		{ "gappov",		INTEGER, &gappov },
		{ "swallowfloating",	INTEGER, &swallowfloating },
		{ "smartgaps",		INTEGER, &smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	// { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, // This is used by keepassxc
	{ MODKEY,			XK_grave,	spawn,	SHCMD("dmenuunicode") },
	{ MODKEY|ShiftMask,		XK_grave,	spawn,	SHCMD("dmoji") },
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)
	{ MODKEY,			XK_0,		view,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY,			XK_minus,	spawn,		SHCMD("vol down 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("vol down 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_equal,	spawn,		SHCMD("vol up 5 kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_equal,	spawn,		SHCMD("vol up 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_BackSpace,	spawn,		SHCMD("remaps") },
	{ MODKEY|ShiftMask,		XK_BackSpace,	spawn,		SHCMD("remaps intl") },

	{ MODKEY,			XK_Tab,		view,		{0} },
	{ MODKEY|ShiftMask,		XK_Tab,		spawn,		SHCMD("xdotool key Caps_Lock") },
	{ MODKEY,			XK_q,		killclient,	{0} },
	{ MODKEY|ShiftMask,		XK_q,		spawn,		SHCMD("sysact") },
	{ MODKEY,			XK_w,		spawn,		SHCMD("vieb") },
	{ MODKEY,			XK_n,		spawn,		SHCMD("$BROWSER") },
	{ MODKEY|ShiftMask,		XK_w,		spawn,		SHCMD("killall nmtui-connect >/dev/null || st -e nmtui-connect") },
	{ MODKEY,			XK_e,		spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
	{ MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD(TERMINAL " -e  abook") },
	{ MODKEY,			XK_r,		spawn,		SHCMD(TERMINAL " -e lf") },
	{ MODKEY|ShiftMask,		XK_r,		spawn,		SHCMD("killall btm >/dev/null || st -c sysMon -e btm") },
	{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[2]} }, /* tile */
	{ MODKEY|ShiftMask,		XK_t,		setlayout,	{.v = &layouts[1]} }, /* bstack */
	{ MODKEY,			XK_y,		setlayout,	{.v = &layouts[0]} }, /* spiral */
	{ MODKEY|ShiftMask,		XK_y,		setlayout,	{.v = &layouts[3]} }, /* dwindle */
	{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[4]} }, /* deck */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[5]} }, /* monocle */
	{ MODKEY,			XK_i,		setlayout,	{.v = &layouts[6]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY,			XK_o,		incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY,			XK_p,		spawn,		SHCMD("spot-cli -t; mpc toggle") },
	{ MODKEY|ShiftMask,		XK_p,		spawn,		SHCMD("mpc stop ; pauseallmpv; spot-cli -s") },
	{ MODKEY,			XK_bracketleft,	spawn,		SHCMD("mpc seek -10; spot-cli --seek -10") },
	{ MODKEY|ShiftMask,		XK_bracketleft,	spawn,		SHCMD("mpc seek -60; spot-cli --seek -60") },
	{ MODKEY,			XK_bracketright,spawn,		SHCMD("mpc seek +10; spot-cli --seek +10") },
	{ MODKEY|ShiftMask,		XK_bracketright,spawn,		SHCMD("mpc seek +60; spot-cli --seek +60") },
	{ MODKEY,			XK_backslash,	view,		{0} },
	{ MODKEY|ShiftMask,		XK_backslash,	setlayout,	{.v = &layouts[8]} },

	{ MODKEY,			XK_a,		togglegaps,	{0} },
	{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	{0} },
	{ MODKEY,			XK_s,		togglesticky,	{0} },
	{ MODKEY|ShiftMask,		XK_s,		spawn,		SHCMD("killall screenkey >/dev/null || screenkey &") },
	{ MODKEY,			XK_d,		spawn,          SHCMD("menu") },
	{ MODKEY|ShiftMask,		XK_d,		spawn,		SHCMD("dscg") },
	{ MODKEY,			XK_f,		togglefullscr,	{0} },
	{ MODKEY|ShiftMask,		XK_f,		setlayout,	{.v = &layouts[9]} },
	{ MODKEY,			XK_g,		shiftview,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_g,		shifttag,	{ .i = -1 } },
	{ MODKEY,			XK_h,		setmfact,	{.f = -0.05} },
	{ MODKEY|ShiftMask,		XK_h,		togglescratch,	{.ui = 4} },
	/* J and K are automatically bound above in STACKKEYS */
	{ MODKEY,			XK_l,		setmfact,      	{.f = +0.05} },
	{ MODKEY,			XK_semicolon,	shiftview,	{ .i = 1 } },
	{ MODKEY|ShiftMask,		XK_semicolon,	shifttag,	{ .i = 1 } },
	// { MODKEY,			XK_apostrophe,	spawn,		SHCMD("") }, //
	// { MODKEY|ShiftMask,		XK_apostrophe,	spawn,		SHCMD("") }, //
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_Return,	togglescratch,	{.ui = 0} },
	{ MODKEY|Mod1Mask,		XK_Return,	spawn,		SHCMD("tabbed -c -r 2 st -w id") },

	{ MODKEY,			XK_z,		incrgaps,	{.i = +3 } },
	{ MODKEY|ShiftMask,		XK_z,		togglescratch,	{.ui = 3} },
	{ MODKEY,			XK_x,		incrgaps,	{.i = -3 } },
	{ MODKEY|ShiftMask,		XK_x,		spawn,		SHCMD("togcomp") },
	{ MODKEY|ShiftMask,		XK_c,		togglescratch,	{.ui = 1} },
	// { MODKEY,			XK_c,		spawn,		SHCMD("") }, // This is used by `copyq`
	/* V is automatically bound above in STACKKEYS */
	{ MODKEY,			XK_b,		togglebar,	{0} },
	{ MODKEY|ShiftMask,		XK_b,		togglescratch,	{.ui = 2} },
	{ MODKEY|ShiftMask,		XK_n,		spawn,		SHCMD(TERMINAL " -e newsboat") },
	{ MODKEY,			XK_m,		spawn,		SHCMD("setsid -f st -c ncmpcpp -e ncmpcpp; kunst --silent") },
	{ MODKEY|ShiftMask,		XK_m,		spawn,		SHCMD("vol toggle; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_comma,	spawn,		SHCMD("mpc prev; spot-cli -p >/dev/null") },
	{ MODKEY|ShiftMask,		XK_comma,	spawn,		SHCMD("mpc seek 0%; spot-cli --set 0") },
	{ MODKEY,			XK_period,	spawn,		SHCMD("mpc next; spot-cli -n >/dev/null") },
	{ MODKEY|ShiftMask,		XK_period,	spawn,		SHCMD("mpc repeat") },

	{ MODKEY,			XK_Left,	focusmon,	{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		{.i = -1 } },
	{ MODKEY,			XK_Right,	focusmon,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		{.i = +1 } },

	{ MODKEY,			XK_Page_Up,	shiftview,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	{ .i = -1 } },
	{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = +1 } },
	{ MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	{ .i = +1 } },
	{ MODKEY,			XK_Insert,	spawn,		SHCMD("notify-send \"📋 Clipboard contents:\" \"$(xclip -o -selection clipboard)\"") },

	{ MODKEY,			XK_F1,		spawn,		SHCMD("mpc pause && mpc toggleoutput MPD && mpc toggleoutput MPD && mpc play") },
	{ MODKEY,			XK_F2,		spawn,		SHCMD("connectHeadphones") },
	{ MODKEY,			XK_F3,		spawn,		SHCMD("displayselect") },
	{ MODKEY,			XK_F4,		spawn,		SHCMD(TERMINAL " -e ncpamixer; kill -44 $(pidof dwmblocks)") },
	// { MODKEY,			XK_F5,		spawn,		SHCMD(""), },
	{ MODKEY,			XK_F6,		spawn,		SHCMD("torwrap") },
	{ MODKEY,			XK_F7,		spawn,		SHCMD("td-toggle") },
	{ MODKEY,			XK_F8,		spawn,		SHCMD("mw -Y") },
	{ MODKEY,			XK_F9,		spawn,		SHCMD("dmenumount") },
	{ MODKEY,			XK_F10,		spawn,		SHCMD("dmenuumount") },
	{ MODKEY,			XK_F11,		spawn,		SHCMD("camtoggle") },
	// { MODKEY,			XK_F12,		spawn,		SHCMD(""), },
	{ MODKEY,			XK_space,	zoom,		{0} },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	{0} },

	{ 0,				XK_Print,	spawn,		SHCMD("maim -u pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,			XK_Print,	spawn,		SHCMD("maimpick") },
	{ MODKEY,			XK_Print,	spawn,		SHCMD("dmenurecord") },
	{ MODKEY|ShiftMask,		XK_Print,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Delete,	spawn,		SHCMD("dmenurecord kill") },

	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("vol toggle; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("vol up 5; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("vol down 5; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPrev,		spawn,		SHCMD("mpc prev; spot-cli -p >/dev/null") },
	{ 0, XF86XK_AudioNext,		spawn,		SHCMD("mpc next; spot-cli -n >/dev/null") },
	{ 0, XF86XK_AudioPause,		spawn,		SHCMD("mpc pause; spot-cli --pause") },
	{ 0, XF86XK_AudioPlay,		spawn,		SHCMD("mpc play; spot-cli --play") },
	{ 0, XF86XK_AudioStop,		spawn,		SHCMD("mpc stop; spot-cli -s") },
	// { 0, XF86XK_AudioRewind,	spawn,		SHCMD("mpc seek -10") },
	// { 0, XF86XK_AudioForward,	spawn,		SHCMD("mpc seek +10") },
	// { 0, XF86XK_AudioMedia,		spawn,		SHCMD(TERMINAL " -e ncmpcpp") },
	// { 0, XF86XK_AudioMicMute,	spawn,		SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, XF86XK_PowerOff,		spawn,		SHCMD("sysact") },
	// { 0, XF86XK_Calculator,		spawn,		SHCMD(TERMINAL " -e bc -lq") },
	// { 0, XF86XK_Sleep,		spawn,		SHCMD("sudo -A zzz") },
	// { 0, XF86XK_WWW,		spawn,		SHCMD("$BROWSER") },
	// { 0, XF86XK_DOS,		spawn,		SHCMD(TERMINAL) },
	// { 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	// { 0, XF86XK_TaskPane,		spawn,		SHCMD(TERMINAL " -e htop") },
	// { 0, XF86XK_Mail,		spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
	// { 0, XF86XK_MyComputer,		spawn,		SHCMD(TERMINAL " -e lf /") },
	/* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */
	// { 0, XF86XK_Launch1,		spawn,		SHCMD("xset dpms force off") },
	{ 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("touchpadtoggle") },
	// { 0, XF86XK_TouchpadOff,	spawn,		SHCMD("synclient TouchpadOff=1") },
	// { 0, XF86XK_TouchpadOn,		spawn,		SHCMD("synclient TouchpadOff=0") },
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("br inc 2") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("br dec 2") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};
