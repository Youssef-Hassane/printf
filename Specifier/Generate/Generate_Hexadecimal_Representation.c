#include "../../main.h"

/**
 * Convert_Binary_Chunk_To_Hex - Converts a chunk of binary to hexadecimal.
 * Return: void
 * ----------------------
 * prototype: void Convert_Binary_Chunk_To_Hex(
 * char *binaryArray, char *hexArray,
 * int *binaryIndex, int letterOffset)
 * ----------------------
 * @binaryArray: Pointer to the binary array.
 * @hexArray: Pointer to the hexadecimal array.
 * @binaryIndex: Pointer to the current index in the binary array.
 * @letterOffset: Offset for ASCII conversion
 * based on uppercase or lowercase requirement.
 * ----------------------
 * This function processes an unsigned integer
 * extracts its binary chunk, and converts it to hexadecimal.
 * The resulting hexadecimal digit is stored in the provided hexArray.
 * ----------------------
 * By Ahmed Abdelhamid
 */

void Convert_Binary_Chunk_To_Hex(
	char *binaryArray, char *hexArray,
	int *binaryIndex, int letterOffset)
{
	/* */
	int binaryChunk = 0;
	/* */
	int powerOfTwo = 1;
	/* */
	for (; powerOfTwo <= 8; powerOfTwo *= 2, (*binaryIndex)--)
	{
		binaryChunk = ((binaryArray[*binaryIndex] - '0') * powerOfTwo) + binaryChunk;
	}
	/* Restore the binaryIndex after the loop */
	(*binaryIndex)++;
	/* Convert the obtained value to hexadecimal and store it in the hexArray */
	if (binaryChunk < 10)
	{
		/* Convert to ASCII for digits 0-9 */
		hexArray[(*binaryIndex) / 4] = binaryChunk + 48;
	}
	else
	{
		/* Convert to ASCII for letters A-F or a-f */
		hexArray[(*binaryIndex) / 4] = binaryChunk + letterOffset;
	}
}

/**
 * Generate_Hexadecimal_Representation - Generates the
 * hexadecimal representation of binary data.
 * Return: The hexadecimal representation
 * ----------------------
 * prototype: char *Generate_Hexadecimal_Representation(
 * char *binaryArray, char *hexArray,
 * int isUppercase, int hexArraySize)
 * ----------------------
 * @binaryArray: Pointer to the binary array.
 * @hexArray: Pointer to the hexadecimal array.
 * @isUppercase: Flag indicating whether the output
 * should be in uppercase (1) or lowercase (0).
 * @hexArraySize:Size of the hexadecimal array.
 * ----------------------
 * This function converts a binary array to its
 * corresponding hexadecimal representation.
 * The result is stored in the provided hexArray,
 * and the output can be in uppercase or lowercase.
 * ----------------------
 * By Youssef Hassane
 */

char *Generate_Hexadecimal_Representation(
	char *binaryArray, char *hexArray,
	int isUppercase, int hexArraySize)
{
	/* */
	int binaryIndex = (hexArraySize * 4) - 1;
	/* */
	int letterOffset;
	/* */
	hexArray[hexArraySize] = '\0';
	/* Set the ASCII value for the letter 'A'  */
	/* or 'a' based on the case requirement */
	letterOffset = (isUppercase) ? 55 : 87;
	/* Convert binary to hexadecimal */
	for (; binaryIndex >= 0; binaryIndex--)
	{
		/* */
		Convert_Binary_Chunk_To_Hex(
		    binaryArray, hexArray, &binaryIndex, letterOffset);
	}
	/* */
	return (hexArray);
}
