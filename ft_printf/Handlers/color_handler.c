
#include "printf.h"

typedef struct	s_style
{
	t_char	*style;
	t_char	*ansi_code;
}				t_style;

/* CODE:  \033[<code1>;<code2>m */

t_style table[] =
{
	{    "default",      "0"    },
	\
	{    "underlined",   "4"    },
	{    "bold",         "1"    },
	{    "italic",       "3"    },
	{    "inverted",     "7"    },
	{    "dim",          "2"    },
	{    "hidden",       "8"    },
	\
	{    "black",        "30"   },
	{    "white",        "97"   },
	\
	{    "red",          "91"   },
	{    "green",        "92"   },
	{    "blue",         "34"   },
	{    "yellow",       "93"   },
	{    "magenta",      "95"   },
	{    "cyan",         "36"   }
};

// /* BACKGROUND COLORS */

// t_dispatch background_colors[] =
// {
// 	{"black", ""},
// 	{"white", ""},
// 	{"red", ""},
// 	{"green", ""},
// 	{"blue", ""},
// 	{"yellow", ""},
// 	{"magenta", ""},
// 	{"cyan", ""}
// }




"Default"            "39"
"Black"              "30"
"Red"                "31"
"Green"              "32"
"Yellow"             "33"
"Blue"               "34"
"Magenta"            "35"
"Cyan"               "36"
"Light gray"         "37"
"Dark gray"          "90"
"Light red"          "91"
"Light green"        "92"
"Light yellow"       "93"
"Light blue"         "94"
"Light magenta"      "95"
"Light cyan"         "96"
"White"              "97"
