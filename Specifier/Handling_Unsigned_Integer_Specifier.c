#include "../main.h"
#include "Generate/Generate_Unsigned_Integer_Digits.c"

/**
 * Handling_Unsigned_Integer_Specifier - Handles unsigned
 * integer specifier in a format string.
 * Return: Number of characters processed.
 * ----------------------
 * prototype:
 * int Handling_Unsigned_Integer_Specifier(
 *     va_list theArgs, char *theBuffer, unsigned int theIndexOfTheBuffer);
 * ----------------------
 * @theArgs: Variable arguments list.
 * @theBuffer: The buffer to store the processed characters.
 * @theIndexOfTheBuffer: The index of the buffer.
 * ----------------------
 * This function extracts an unsigned integer from the variable arguments list
 * and processes and displays its digits using Display_Unsigned_Integer_Digits.
 * ----------------------
 * By Ahmed Abdelhamid
 */

int Handling_Unsigned_Integer_Specifier(
	va_list theArgs, char *theBuffer, unsigned int theIndexOfTheBuffer)
{
	/* Extract the unsigned integer from the variable arguments list */
	unsigned int theGivenNumber = va_arg(theArgs, unsigned int);
	/* Call Display_Unsigned_Integer_Digits to process and display the digits */
	unsigned int index = Generate_Unsigned_Integer_Digits(
	    theGivenNumber,
	    theBuffer,
	    &theIndexOfTheBuffer);
	/* Return the number of characters processed */
	return (index);
}
