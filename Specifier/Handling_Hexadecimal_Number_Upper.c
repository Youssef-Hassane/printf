#include "../main.h"
#include "Generate/Generate_Binary_Representation_3.c"
#include "Generate/Generate_Hexadecimal_Representation_2.c"

/**
 * print_hex - converts a decimal to hexadecimal and prints it
 * @theArgs: input decimal value
 * @theBuffer: buffer pointer to store the result
 * @theIndexOfTheBuffer: index for buffer pointer
 * Return: number of characters printed
 */

int Handling_Hexadecimal_Number_Upper(
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
	char *hexadecimalRepresentation;

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

	binaryRepresentation = Generate_Binary_Representation_3(
		binaryRepresentation,
		theGivenNumber, isNegative, THIRTY_TWO);

	hexadecimalRepresentation = malloc(sizeof(char) * NINE);
	hexadecimalRepresentation = Generate_Hexadecimal_Representation_2(binaryRepresentation, hexadecimalRepresentation, 1, EIGHT);

	for (; hexadecimalRepresentation[index]; index++)
	{
		if (hexadecimalRepresentation[index] != '0' && firstOne == 0)
			firstOne = 1;

		if (firstOne)
		{
			theIndexOfTheBuffer = Combines_Buffer(
				theBuffer,
				hexadecimalRepresentation[index],
				theIndexOfTheBuffer);
			theNumberOfCharactersPrinted++;
		}
	}

	free(binaryRepresentation);
	free(hexadecimalRepresentation);

	return (theNumberOfCharactersPrinted);
}
