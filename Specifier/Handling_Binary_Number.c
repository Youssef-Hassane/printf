#include "../main.h"
#include "Generate/Generate_Binary_Representation.c"

/**
 * Display_Binary_Digits - Display binary digits
 * of the given binary representation.
 * Return: void
 * ----------------------
 * prototype: void Display_Binary_Digits(char *binaryRepresentation,
 * char *theBuffer,
 * unsigned int *theIndexOfTheBuffer,
 * int *theNumberOfCharactersPrinted, int *firstOne, int *index)
 * ----------------------
 * @binaryRepresentation: The binary representation to be displayed.
 * @theBuffer: The buffer to store the combined binary digits.
 * @theIndexOfTheBuffer: Pointer to the index of the buffer.
 * @theNumberOfCharactersPrinted: Pointer to the number of characters printed.
 * @firstOne: Pointer to a flag indicating if the first '1'
 * has been encountered.
 * @index: Pointer to the current index in the binary representation.
 * ----------------------
 * By Youssef Hassane
 */
void Display_Binary_Digits(char *binaryRepresentation, char *theBuffer,
				   unsigned int *theIndexOfTheBuffer,
				   int *theNumberOfCharactersPrinted, int *firstOne, int *index)
{
	/* Iterate through the binary representation */
	for (*theNumberOfCharactersPrinted = *index = 0;
	     binaryRepresentation[*index]; (*index)++)
	{
		/* Check if the first '1' has been encountered */
		if (*firstOne == 0 && binaryRepresentation[*index] == '1')
		{
			*firstOne = 1;
		}
		/* If the first '1' has been encountered, combine the buffer */
		if (*firstOne == 1)
		{
			*theIndexOfTheBuffer = Combines_Buffer(
			    theBuffer,
			    binaryRepresentation[*index],
			    *theIndexOfTheBuffer);
			(*theNumberOfCharactersPrinted)++;
		}
	}
}

/**
 * Handling_Binary_Number - Handle the binary representation of a given number.
 * Return: Number of characters printed.
 * ----------------------
 * prototype: int Handling_Binary_Number(va_list theArgs, char *theBuffer,
 *                                        unsigned int theIndexOfTheBuffer)
 * ----------------------
 * @theArgs: Variable argument list.
 * @theBuffer: The buffer to store the combined binary digits.
 * @theIndexOfTheBuffer: Index of the buffer.
 * ----------------------
 * By Youssef Hassane
 */
int Handling_Binary_Number(va_list theArgs, char *theBuffer,
				   unsigned int theIndexOfTheBuffer)
{
	/* Initialize variables */
	int index = 0;
	int theGivenNumber;
	int theNumberOfCharactersPrinted = 0;
	int firstOne = 0;
	int isNegative = 0;
	char *binaryRepresentation = malloc(sizeof(char) * (32 + 1));
	/* Check for memory allocation failure */
	if (binaryRepresentation == NULL)
	{
		free(binaryRepresentation);
		exit(1);
	}
	/* Retrieve the given number from variable arguments */
	theGivenNumber = va_arg(theArgs, int);
	/* Handle the case when the given number is 0 */
	if (theGivenNumber == 0)
	{
		theIndexOfTheBuffer = Combines_Buffer(theBuffer, '0', theIndexOfTheBuffer);
		return (1);
	}
	/* Handle the case when the given number is negative */
	if (theGivenNumber < 0)
	{
		theGivenNumber = (theGivenNumber * -1) - 1;
		isNegative = 1;
	}
	/* Generate binary representation of the given number */
	binaryRepresentation = Generate_Binary_Representation(
	    binaryRepresentation,
	    theGivenNumber,
	    isNegative, 32);
	/* Display binary digits */
	Display_Binary_Digits(binaryRepresentation, theBuffer, &theIndexOfTheBuffer,
				    &theNumberOfCharactersPrinted, &firstOne, &index);
	/* Free allocated memory */
	free(binaryRepresentation);
	/* Return the number of characters printed */
	return (theNumberOfCharactersPrinted);
}
