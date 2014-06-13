#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <stdarg.h>

    #define STRINGIFY(X) #X
    #define TO_STRING(X) STRINGIFY(X)

    #define CONTEXT "File     -> "__FILE__"\n\tLine     -> "TO_STRING(__LINE__)

    #define ENUM_SEVERITY(SELECTOR) \
        SELECTOR(TRACE, )           \
        SELECTOR(INFO, )            \
        SELECTOR(WARNING, Warning)  \
        SELECTOR(ERROR, Error)      \
        SELECTOR(FATAL, Fatal error)

    #define SEVERITY_ID(ENUM, STRING) ENUM,
    #define SEVERITY_NAME(ENUM, STRING) #STRING,

    typedef enum _boolean { FALSE, TRUE } Boolean;
    typedef enum _severity { ENUM_SEVERITY(SEVERITY_ID) UNDEFINED } Severity;
    typedef char* String;

    static const String severity_names[] = { ENUM_SEVERITY(SEVERITY_NAME) "Undefined" };

    #define CHECK_NULL(element)                                  \
        if ((element) == NULL) {                                 \
            logError ("Null element", FATAL, CONTEXT, __func__); \
            exit(EXIT_FAILURE);                                  \
        }

    String sprintfSized (const char* fmt, ...);
    String fgetsSizing (FILE* stream);

    String creerString (String texte);
    void supprString (String s);

    void logError (const String message, const Severity s, const String context, const char* appel);
    void logInfo (const String message);
    void logTrace (const char* fmt, ...);

#endif
