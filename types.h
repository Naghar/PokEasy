/******************** #HEADER **************************************************
 *	@name		types.h
 *	@source		types.c
 *	@desc		Generic functions and data not specific to PokEasy.
 *
 *	@function	sprintfSized,
 *				fgetsSizing,
 *				newString,
 *				delString,
 *				logError,
 *				logInfo,
 *				logTrace
 *
 *	@global		None
 *
 *	@constant	NULL_POINTER,
 *				CONTEXT
 *
 *	@macro		STRINGIFY,
 *				TO_STRING,
 *				ENUM_SEVERITY,
 *				SEVERITY_ID,
 *				SEVERITY_NAME,
 *				CHECK_NULL
 *
 *	@depend		!stdlib.h,
 *				!stdio.h,
 *				!string.h,
 *				!errno.h,
 *				!stdarg.h
 ******************************************************************************/

#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <pthread.h>

/******************** #MACRO ***************************************************
 *	@name	TO_STRING
 *	@desc	Turn a constant into a string constant
 *
 *	@param	X	: The constant to expand
 */
#define TO_STRING(X) #X

/******************** #MACRO ***************************************************
 *	@name	STRINGIFY
 *	@desc	Let the constant be expanded (replaced by its value)
 *
 *	@param	X	: The constant to expand
 */
#define STRINGIFY(X) TO_STRING(X)

/******************** #MACRO ***************************************************
 *	@name	CHECK_NULL
 *	@desc	Log a fatal error and shut the application if a NULL element if met
 *
 *	@param	element	: The data to check
 */
#define CHECK_NULL(element)								  		\
	if ((element) == NULL) {									\
		logError ("Null element", FATAL, CONTEXT, __func__);	\
		exit(EXIT_FAILURE);										\
	}

#define NULL_POINTER 0
#define CONTEXT "File	 -> "__FILE__"\n\tLine	 -> "STRINGIFY(__LINE__)

typedef
	char*
	String;

typedef
	enum _boolean
	{
		FALSE,
		TRUE
	}
	Boolean;

typedef
	enum _severity
	{
		TRACE,
		INFO,
		WARNING,
		ERROR,
		FATAL
	}
	Severity;

static const String severity_names[]
						= {
							"Debug",
							"Information",
							"Warning",
							"Error",
							"Fatal Error"
						  };

/******************** #PROTOTYPE ***********************************************
 *	@name	sprintfSized
 *	@desc	sprintf replacement with dynamically calculated string length.
 *	@def	types.c
 *
 *	@param	fmt	: String containing format tags (e.g. %d, %s),
 *			...	: The values to replace the format tags with
 *
 *	@return	A string with the format tags replaced by their values
 */
String sprintfSized (const char* fmt, ...);

/******************** #PROTOTYPE ***********************************************
 *	@name	fgetsSizing
 *	@desc	fgets replacement with dynamically calculated string length.
 *	@def	types.c
 *
 *	@param	stream	: String containing format tags (e.g. %d, %s)
 *
 *	@return	The content of the file
 */
String fgetsSizing (FILE* stream);

/******************** #PROTOTYPE ***********************************************
 *	@name	newString
 *	@desc	Allocate memory for a string and initialize it.
 *	@def	types.c
 *
 *	@param	content	: The initial value to initialize the string with.
 *
 *	@return	The allocated string.
 *			An empty string if #param content is NULL
 */
String newString (String content);

/******************** #PROTOTYPE ***********************************************
 *	@name	delString
 *	@desc	Deallocate a string in memory.
 *	@def	types.c
 *
 *	@param	s	: The string to deallocate
 *
 *	@return	None
 */
void delString (String s);

/******************** #PROTOTYPE ***********************************************
 *	@name	logError
 *	@desc	Write critical events to a file and shut the application if needed.
 *	@def	types.c
 *
 *	@param	message	: Error to log
 *			s		: The level of severity of the error (warning or above)
 *			context	: The line and the file in which the error occured
 *			appel	: The function in which the error occured
 *
 *	@return	None
 */
void logError (const String message, const Severity s, const String context, const char* appel);

/******************** #PROTOTYPE ***********************************************
 *	@name	logInfo
 *	@desc	Track user inputs in a file.
 *	@def	types.c
 *
 *	@param	message	: String to log
 *
 *	@return	None
 */
void logInfo (const String message);

/******************** #PROTOTYPE ***********************************************
 *	@name	logTrace
 *	@desc	Track function calls. Only used for debug.
 *	@def	types.c
 *
 *	@param	fmt	: String containing format tags (e.g. %d, %s),
 *			...	: The values to replace the format tags with
 *
 *	@return	None
 */
void logTrace (const char* fmt, ...);

#endif
