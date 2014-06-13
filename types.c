#include "types.h"

String sprintfSized (const char* fmt, ...)
{
    va_list ap;
    size_t str_size;
    char* str = NULL;

    va_start(ap, fmt);
        str_size = vsnprintf (str, 0, fmt, ap); /* Returns size of the string into str_size */
        str = malloc(str_size + 1);
        vsnprintf(str, str_size + 1, fmt, ap);  /* Reads into str with the right size */
    va_end(ap);

    return (String) str;
}

String fgetsSizing (FILE* stream)
{
	String read = NULL, buffer = NULL;
	size_t read_size = 2, old_size;

	if (read_size < 1) read_size = 1;
	read = malloc(read_size * sizeof(*read));

	if (!stream) return NULL;                           /* Invalid stream */
	if (!fgets(read, read_size, stream)) return NULL;   /* Can't read : EOF */
	if (read[strlen(read) - 1] == '\n')                 /* Initial reading buffer size is sufficient */
    {
        read[strlen(read) - 1] = '\0';
        return read;
    }

	do {                                                /* Double reading buffer size until sufficient */
		old_size = read_size;
		read_size *= 2;

		read = realloc(read, read_size * sizeof(*read));
		if (read == NULL) return NULL;                  /* Out of memory */

		buffer = &(read[old_size - 1]);
	} while ( fgets(buffer, old_size + 1, stream) && buffer[strlen(buffer) - 1] != '\n' );

	read[strlen(read) - 1] = '\0';
	puts("Sortie normale");
	return read;
}

String creerString (String texte)
{
    String s = NULL;
    s = malloc( strlen(texte) * sizeof(*s) );
    CHECK_NULL(s)

    if (texte == NULL) texte = "Default";
    strcpy(s, texte);

    return s;
}

void supprString (String s)
{
    free(s);
    s = 0;
}

void logError (const String message, Severity s, const String context, const char* appel)
{
    FILE *f_stderr = fopen("log_errors.log", "a");

    if (f_stderr == NULL)
    {
        if (s == FATAL) exit(EXIT_FAILURE);
        else logError (message, FATAL, CONTEXT, __func__);
    }

    fprintf(f_stderr, "[%s %s] %s\n\t%s\n\tFonction -> %s\n\tMessage  -> [%s] %s \n\n",
            __DATE__, __TIME__, severity_names[s], context, appel, message, strerror(errno));

    fclose(f_stderr);
}

void logInfo (const String message)
{
    FILE *f_stdout = fopen("log_infos.log", "a");
    CHECK_NULL(f_stdout)

    fprintf(f_stdout, "[%s %s] %s\n\n", __DATE__, __TIME__, message);

    fclose(f_stdout);
}

void logTrace (const char* fmt, ...)
{
    va_list ap;
    size_t trace_size;
    char* trace = NULL;
    FILE *f_trace = NULL;

    va_start(ap, fmt);
        trace_size = vsnprintf (trace, 0, fmt, ap);
        trace = malloc(trace_size + 1);
        vsnprintf(trace, trace_size + 1, fmt, ap);
    va_end(ap);

    f_trace = fopen("log_trace.log", "a");
    CHECK_NULL(f_trace)

    fprintf(f_trace, "[%s %s] %s\n\n", __DATE__, __TIME__, trace);

    fclose(f_trace);
    free(trace);
}
