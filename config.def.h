/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_black[]       = "#000000";
static const char col_gray[]        = "#cccccc";
static const char *colors[SchemeLast][3]      = {
	/*               fg         bg         border   */
       [SchemeNorm] = { col_black, col_gray,  col_black },
       [SchemeSel] =  { col_gray,  col_black, col_black },
};

/* tagging */
static const char *tags[] = { "J", "K", "L", ";", "U", "I", "O" };

static const Rule rules[1] = {};

/* layout(s) */
static const float mfact     = 0.5 ; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
        { MODKEY|ControlMask,           KEY,      view,           {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run",
                                  "-m", dmenumon,
                                  "-fn", dmenufont,
                                  "-nb", col_gray,
                                  "-nf", col_black,
                                  "-sb", col_black,
                                  "-sf", col_gray,
                                  NULL
                                };

static const char *termcmd[]  = { "gnome-terminal",
                                  NULL
                                };

static Key keys[] = {
	/* modifier                     key           function        argument */
	{ MODKEY|ControlMask,           XK_Return,    spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,           XK_p,         spawn,          {.v = dmenucmd } },
	{ MODKEY|ControlMask,           XK_c,         killclient,     {0} },
	{ MODKEY|ControlMask,           XK_q,         quit,           {0} },
	{ MODKEY,                       XK_backslash, zoom,           {0} },
	{ MODKEY,                       XK_k,         focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_l,         focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,         setmfact,       {.f = -0.02} },
	{ MODKEY,                       XK_semicolon, setmfact,       {.f = +0.02} },
	TAGKEYS(                        XK_j,                      0)
	TAGKEYS(                        XK_k,                      1)
	TAGKEYS(                        XK_l,                      2)
	TAGKEYS(                        XK_semicolon,              3)
	TAGKEYS(                        XK_u,                      4)
	TAGKEYS(                        XK_i,                      5)
	TAGKEYS(                        XK_o,                      6)
	TAGKEYS(                        XK_p,                      7)
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
