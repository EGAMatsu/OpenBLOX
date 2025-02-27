/*

    OpenBLOX Engine: Locale file
    @17:43 on 2024-02-26

*/

char *locale_codes[] = {
    "en",   // English
    "es",   // Spanish
    "tok",  // Toki Pona
    0
};
#define LOCALE_EN_ 0
#define LOCALE_ES_ 1
#define LOCALE_TOK 2

char *locale_names[] = {
    "English",
    "Español",
    "toki pona",
    0
};

// Hardcoded strings
char *strings_debug[][3] = {
    {"Current Language", "Idioma Actual", "toki li lon"},
    {"Current Platform", "Plataforma Actual", "ilo musi li lon"},
    0
};
#define STRING_CURRENT_LANGUAGE 0
#define STRING_CURRENT_PLATFORM 1

char *strings_lingo[][3] = {
    {"English", "Spanish", "Toki Pona"},
    {"Inglés", "Español", "Toki Pona"},
    {"toki Inli", "toki Epanja", "toki pona"},
    0
};
#define STRING_LANGUAGE_ENGLISH_ 0
#define STRING_LANGUAGE_SPANISH_ 1
#define STRING_LANGUAGE_TOKIPONA 2

char *strings_platform[][3] = {
    {"Nintendo DS", "Nintendo DS", "ilo Si Esu"},
    {"Nintendo DSi", "Nintendo DSi", "ilo Si Esu Ije"},
    {"PC", "Computadora", "ilo lipu"},
    0
};

#define STRING_PLATFORM_DS______ 0
#define STRING_PLATFORM_DSI_____ 1
#define STRING_PLATFORM_PC______ 2