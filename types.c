/******************** #SOURCE **************************************************
 *	@name		types.c
 *	@header		types.h
 *	@desc		Generic functions and data not specific to PokEasy.
 *
 *	@function	$header
 *
 *	@global		$header
 *
 *	@depend		None
 *
 *	@stream		log_errors.log,
 *				log_infos.log,
 *				log_trace.log
 ******************************************************************************/

#include "types.h"

/******************** #FUNCTION ************************************************
 *	@name	sprintfSized
 *	@desc	sprintf replacement with dynamically calculated string length.
 *	@decl	types.h
 */
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

/******************** #FUNCTION ************************************************
 *	@name	fgetsSizing
 *	@desc	fgets replacement with dynamically calculated string length.
 *	@decl	types.h
 */
String fgetsSizing (FILE* stream)
{
	String read = NULL, buffer = NULL;
	size_t read_size = 2, old_size;

	if (read_size < 1) read_size = 1;
	read = malloc(read_size * sizeof(*read));

	if (!stream) return NULL;						   /* Invalid stream */
	if (!fgets(read, read_size, stream)) return NULL;   /* Can't read : EOF */
	if (read[strlen(read) - 1] == '\n')				 /* Initial reading buffer size is sufficient */
	{
		read[strlen(read) - 1] = '\0';
		return read;
	}

	do {												/* Double reading buffer size until sufficient */
		old_size = read_size;
		read_size *= 2;

		read = realloc(read, read_size * sizeof(*read));
		if (read == NULL) return NULL;				  /* Out of memory */

		buffer = &(read[old_size - 1]);
	} while ( fgets(buffer, old_size + 1, stream) && buffer[strlen(buffer) - 1] != '\n' );

	read[strlen(read) - 1] = '\0';
	return read;
}

/******************** #FUNCTION ************************************************
 *	@name	newString
 *	@desc	Allocate memory for a string and initialize it.
 *	@decl	types.h
 */
String newString (String content)
{
	String s = NULL;

	if (content == NULL) content = "";

	s = malloc( (strlen(content) + 1) * sizeof(*s) );
	CHECK_NULL(s)

	strcpy(s, content);

	return s;
}

/******************** #FUNCTION ************************************************
 *	@name	delString
 *	@desc	Deallocate a string in memory.
 *	@decl	types.h
 */
void delString (String s)
{
	CHECK_NULL(s)
	free(s);
	s = NULL_POINTER;
}

/******************** #FUNCTION ************************************************
 *	@name	logError
 *	@desc	Write critical events to a file and shut the application if needed.
 *	@decl	types.h
 */
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

/******************** #FUNCTION ************************************************
 *	@name	logInfo
 *	@desc	Track user inputs in a file.
 *	@decl	types.h
 */
void logInfo (const String message)
{
	FILE *f_stdout = fopen("log_infos.log", "a");
	CHECK_NULL(f_stdout)

	fprintf(f_stdout, "[%s %s] %s\n\n", __DATE__, __TIME__, message);

	fclose(f_stdout);
}

/******************** #FUNCTION ************************************************
 *	@name	logTrace
 *	@desc	Track function calls. Only used for debug.
 *	@decl	types.h
 */
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
