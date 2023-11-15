#include "../main.h"
#include "Generate/Generate_Octal_Representation.c"

static char *Generate_Binary_Representation_4(
	char *binaryRepresentation, long int theGivenNumber,
	int isNegative, int theLimitOfBinary);


/**
 * print_hex - converts a decimal to hexadecimal and prints it
 * @theArgs: input decimal value
 * @theBuffer: buffer pointer to store the result
 * @theIndexOfTheBuffer: index for buffer pointer
 * Return: number of characters printed
 * ----------------------
 * By Ahmed Abdelhamid
 */

int Handling_Octal_Number(
	va_list theArgs,
	char *theBuffer,
	unsigned int theIndexOfTheBuffer)
{
	int theGivenNumber = va_arg(theArgs, int);
	int index = 0;
	int isNegative = 0;
	int theNumberOfCharactersPrinted = 0;
	int firstOne = 0;
	char *binaryRepresentation;
	char *octalRepresentation;

	if (theGivenNumber == 0)
	{
		theIndexOfTheBuffer = Combines_Buffer(theBuffer, '0', theIndexOfTheBuffer);
		return (1);
	}

	if (theGivenNumber < 0)
	{
		theGivenNumber = (theGivenNumber * -1) - 1;
		isNegative = 1;
	}

	binaryRepresentation = malloc(sizeof(char) * THIRTY_THREE);

	binaryRepresentation = Generate_Binary_Representation_4(
		binaryRepresentation,
		theGivenNumber, isNegative, THIRTY_TWO);

	octalRepresentation = malloc(sizeof(char) * 12);
	octalRepresentation = Generate_Octal_Representation(binaryRepresentation, octalRepresentation);

	for (; octalRepresentation[index]; index++)
	{
		if (octalRepresentation[index] != '0' && firstOne == 0)
			firstOne = 1;

		if (firstOne)
		{
			theIndexOfTheBuffer = Combines_Buffer(
				theBuffer,
				octalRepresentation[index],
				theIndexOfTheBuffer);
			theNumberOfCharactersPrinted++;
		}
	}

	free(binaryRepresentation);
	free(octalRepresentation);

	return (theNumberOfCharactersPrinted);
}



/**
 * Generate_Binary_Representation_2 - Generate binary representation
 * of a given number.
 * Return: Binary representation string.
 * ----------------------
 * prototype: char *Generate_Binary_Representation(
 * char *binaryRepresentation, long int theGivenNumber,
 * int isNegative, int theLimitOfBinary)
 * ----------------------
 * @binaryRepresentation: The binary representation string to be generated.
 * @theGivenNumber: The given number to be represented in binary.
 * @isNegative: Flag indicating if the number is negative.
 * @theLimitOfBinary: The limit of binary digits.
 * ----------------------
 * By Youssef Hassane
 */

static char *Generate_Binary_Representation_4(
	char *binaryRepresentation, long int theGivenNumber,
	int isNegative, int theLimitOfBinary)
{
	/* Initialize index for binary representation */
	int index = 0;
	/* Initialize binary representation with zeros */
	while (index < theLimitOfBinary)
	{
		binaryRepresentation[index] = '0';
		index++;
	}
	/* Add null terminator to the binary representation string */
	binaryRepresentation[theLimitOfBinary] = '\0';
	/* Generate binary representation of the given number */
	index = theLimitOfBinary - 1;
	while (theGivenNumber > 0)
	{
		binaryRepresentation[index] = (theGivenNumber % 2) + '0';
		theGivenNumber /= 2;
		index--;

		/* Break if index goes below 0 */
		if (index < 0)
		{
			break;
		}
	}
	/* Invert bits if the number is negative */
	if (isNegative)
	{
		index = 0;
		while (binaryRepresentation[index])
		{
			binaryRepresentation[index] = (
				binaryRepresentation[index] == '0') ? '1' : '0';
			index++;
		}
	}
	/* Return the generated binary representation string */
	return (binaryRepresentation);
}
