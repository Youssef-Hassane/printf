#include "../../main.h"

/**
 * Convert_Binary_To_Octal - Convert binary representation to octal.
 * -----------------------------------
 * @binaryArray: Binary array to be converted.
 * @octalRepresentation: Array to store the resulting octal representation.
 * @binaryIndex: Current index in the binary array.
 * @octalIndex: Current index in the octal array.
 * -----------------------------------
 * By Ahmed Abdelhamid
 */
void Convert_Binary_To_Octal(
	char *binaryArray, char *octalRepresentation,
	int *binaryIndex, int *octalIndex)
{
	/* Initialize octalDigit to store the calculated octal digit. */
	int octalDigit = 0;
	/* Initialize bitPower to represent the current power of 2. */
	int bitPower = 1;
	/* bitLimit determines the maximum bitPower based on binaryIndex. */
	int bitLimit;
	/* If binaryIndex is greater than 1, use 4 bits, else use 2 bits. */
	(*binaryIndex > 1) ? (bitLimit = 4) : (bitLimit = 2);
	/* Loop to calculate octal digit based on binary representation. */
	for (; bitPower <= bitLimit; bitPower *= 2, (*binaryIndex)--)
	{
		/* Calculate the octal digit using the current bitPower. */
		octalDigit = ((binaryArray[*binaryIndex] - '0') * bitPower) + octalDigit;
	}
	/* Increment binaryIndex to restore its original value. */
	(*binaryIndex)++;
	/* Store the calculated octal digit in the octal representation array. */
	octalRepresentation[*octalIndex] = octalDigit + '0';
}

/**
 * Generate_Octal_Representation - Generate octal
 * representation of a given number.
 * Return: Octal Representation string.
 * -----------------------------------
 * @binaryArray: Binary array to be converted.
 * @octalRepresentation: Array to store the resulting octal representation.
 * -----------------------------------
 * By Ahmed Abdelhamid
 */
char *Generate_Octal_Representation(
	char *binaryArray, char *octalRepresentation)
{
	/* Initialize binaryIndex to the highest index in the binary array. */
	int binaryIndex = 31;
	/* Initialize octalIndex to the highest index in the octal array. */
	int octalIndex = 10;
	/* Null-terminate the octal representation string. */
	octalRepresentation[11] = '\0';
	/* Loop to convert binary to octal and */
	/* store the result in octalRepresentation. */
	for (; binaryIndex >= 0; binaryIndex--, octalIndex--)
	{
		/* Call Convert_Binary_To_Octal to convert */
		/* a set of binary digits to octal. */
		Convert_Binary_To_Octal(
		    binaryArray,
		    octalRepresentation,
		    &binaryIndex,
		    &octalIndex);
	}
	/* Return the generated octal representation string. */
	return (octalRepresentation);
}
