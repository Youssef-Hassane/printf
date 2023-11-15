#include "main.h"
#include "Function/function.h"
#include "Function/Determine_Print_Function.c"
#include "Function/Input_Validation_Condition.c"
#include "Function/Format_Specifier_Processing_Loop.c"
#include "Function/Find_Matching_Function_Index.c"
#include "Buffer/Display_The_Buffer.c"
#include "Buffer/Combines_Buffer.c"
#include "Buffer/Write_Buffer_To_Stdout.c"



/**
 * _printf - Custom implementation of the printf function.
 * Formats and prints data according to the provided format string.
 * Return: The number of characters printed (excluding null terminator).
 * ----------------------
 * Prototype:
 * int _printf(const char *format, ...);
 * ----------------------
 * @format: The format string containing format specifiers.
 * ----------------------
 * By Youssef Hassane
 */

int _printf(const char *format, ...)
{
	/* Index for iterating through the format string */
	/* unsigned int index = 0; */
	/* Length of the formatted string */
	unsigned int length = 0;
	/* Index in the buffer where characters are stored for printing */
	unsigned int theIndexOfTheBuffer = 0;
	/* Dynamically allocated buffer to store formatted characters */
	static char *theBuffer;
	/* Variable argument list */
	va_list theArgs;
	/* Allocate memory for the buffer */
	theBuffer = malloc(sizeof(char) * BUFFERSIZE);
	/* Validate the input format */
	if (theBuffer == NULL)
	{
		free(theBuffer); /* Return failure if memory allocation fails */
		exit(1);
	}
}
