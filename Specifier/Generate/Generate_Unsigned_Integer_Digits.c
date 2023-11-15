#include "../../main.h"

/**
 * Generate_Unsigned_Integer_Digits - Processes and
 * displays unsigned integer digits.
 * Return: Number of digits processed.
 * ----------------------
 * prototype:
 * int Generate_Unsigned_Integer_Digits(
 *    unsigned int number, char *theBuffer,
 *	unsigned int *theIndexOfTheBuffer);
 * ----------------------
 * @number: The unsigned integer to be processed.
 * @theBuffer: The buffer to store the processed digits.
 * @theIndexOfTheBuffer: The index of the buffer.
 * ----------------------
 * This function processes the unsigned integer
 * and stores its digits in the buffer.
 * ----------------------
 * By Ahmed Abdelhamid
 */


int Generate_Unsigned_Integer_Digits(
	unsigned int number, char *theBuffer, unsigned int *theIndexOfTheBuffer)
{
	/* Initialize a temporary variable to hold the processed integer */
	unsigned int temporaryVariableOfTheIntegerThatProcessed = number;
	/* Initialize a divisor for extracting digits */
	unsigned int theDivisor = 1;
	/* Initialize an index to keep track of the number of digits processed */
	unsigned int index = 0;
	/* Determine the divisor for the given number */
	while (temporaryVariableOfTheIntegerThatProcessed > 9)
	{
		theDivisor *= 10;
		temporaryVariableOfTheIntegerThatProcessed /= 10;
	}
	/* Extract and store each digit in the buffer */
	while (theDivisor > 0)
	{
		/* Store the digit in the buffer and update the buffer index */
		*theIndexOfTheBuffer = Combines_Buffer(
		    theBuffer,
		    ((number / theDivisor) % 10) + '0',
		    *theIndexOfTheBuffer);

		/* Update the divisor and index */
		theDivisor /= 10;
		index++;
	}
	/* Return the number of digits processed */
	return (index);
}
