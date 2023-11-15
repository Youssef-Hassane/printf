#include "main.h"
#include "Function/function.h"
#include "Function/Determine_Print_Function.c"
#include "Function/Input_Validation_Condition.c"
#include "Function/Format_Specifier_Processing_Loop.c"
#include "Function/Find_Matching_Function_Index.c"
#include "Buffer/Display_The_Buffer.c"
#include "Buffer/Combines_Buffer.c"
#include "Buffer/Write_Buffer_To_Stdout.c"
#include "Specifier/Handling_Character_Specifier.c"
#include "Specifier/Handling_String_Specifier.c"
#include "Specifier/Handling_Integer_Specifier.c"
#include "Specifier/Handling_Percent_Sign_Specifier.c"
#include "Specifier/Handling_Binary_Number.c"
#include "Specifier/Handling_Unsigned_Integer_Specifier.c"
#include "Specifier/Handling_Hexadecimal_Number.c"
#include "Specifier/Handling_Hexadecimal_Number_Upper.c"
#include "Specifier/Handling_Octal_Number.c"
#include "Specifier/Handling_Rot13_Specifier.c"

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
 * By Youssef Hassane & Ahmed Abdelhamid
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
	if (Input_Validation_Condition(format))
	{
		return (-1);
	}
	/* Check for an empty format string */
	if (!format[0])
	{
		/* Return success if the format string is empty */
		return (0);
	}
	va_start(theArgs, format); /* Start the variable argument processing */
	/* Process the format string and store the result in the buffer */
	length = Format_Specifier_Processing_Loop(
		format, theBuffer, &theIndexOfTheBuffer,
		&length, theArgs);
	/* Display all the content of the buffer */
	Display_The_Buffer(theBuffer, theIndexOfTheBuffer);
	free(theBuffer); /* Free the allocated memory for the buffer */
	va_end(theArgs); /* End variable argument processing */
	/* Return the number of characters printed */
	return (length);
}
