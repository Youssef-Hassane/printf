#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define FAIL -1
#define SUCCESS 0
#define SUCCESS_1 1
#define BUFFERSIZE 1024
#define theNull ((void *)0)
#define EIGHT 8
#define NINE 9
#define THIRTY_TWO 32
#define THIRTY_THREE 33



/**
 * struct print - struct for printer functions
 * @argument_type: identifier
 * @function_pointer: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	const char *argument_type;
	int (*function_pointer)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);

int Format_Specifier_Processing_Loop(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs);

void Process_Print_Function(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs, unsigned int *index);

int Display_The_Buffer(char *theBuffer, unsigned int numberOfBytesToPrint);

int Handling_Character_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int theIndexOfTheBuffer);

int Input_Validation_Condition(const char *theInputString);



unsigned int Combines_Buffer(
	char *theBuffer,
	char character,
	unsigned int numberOfBytesToPrint);


int Handling_String_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint);

int Handling_Integer_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint);

int Handle_Integer_Sign(
	int theInputOfInteger,
	char *theBuffer,
	unsigned int *numberOfBytesToPrint);

void Append_Digits_To_Buffer(
	unsigned int value,
	unsigned int *numberOfBytesToPrint,
	char *theBuffer,
	unsigned int *index);

int Handling_Percent_Sign_Specifier(va_list a, char *buffer, unsigned int i);

int Find_Matching_Function_Index(
	const char *identifier, int position,
	int *index_1, int *index_2,
	const print_t *functions);

int Display_The_Buffer(char *theBuffer, unsigned int numberOfBytesToPrint);

unsigned int Combines_Buffer(
	char *theBuffer,
	char character,
	unsigned int numberOfBytesToPrint);

ssize_t Write_Buffer_To_Stdout(char *theBuffer, size_t numberOfBytesToPrint);

void Process_Print_Function(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs, unsigned int *index);

int Format_Specifier_Processing_Loop(
	const char *theStringToProcess, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs);

int (*Determine_Function(const char *i, int p))(va_list, char *, unsigned int);

int Input_Validation_Condition(const char *theInputString);

int Find_Matching_Function_Index(
	const char *identifier, int position,
	int *index_1, int *index_2,
	const print_t *functions);

/*------------------------------*/
int Handling_Binary_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint);

int Handling_Binary_Number(
	va_list theArgs,
	char *theBuffer,
	unsigned int theIndexOfTheBuffer);


/*------------------------------*/

void printBinaryDigits(char *binaryRepresentation, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	int *theNumberOfCharactersPrinted, int *firstOne, int *index);

int Handling_Binary_Number(va_list theArgs, char *theBuffer,
	unsigned int theIndexOfTheBuffer);

char *Generate_Binary_Representation(
	char *binaryRepresentation, long int theGivenNumber,
	int isNegative, int theLimitOfBinary);

char *Generate_Binary_Representation_2(
	char *binaryRepresentation, long int theGivenNumber,
	int isNegative, int theLimitOfBinary);

int Handling_Unsigned_Integer_Specifier(
	va_list args, char *buffer, unsigned int index);

int Generate_Unsigned_Integer_Digits(
	unsigned int number, char *theBuffer, unsigned int *theIndexOfTheBuffer);

int Handling_Hexadecimal_Number(
	va_list theArgs,
	char *theBuffer,
	unsigned int theIndexOfTheBuffer);

char *Generate_Hexadecimal_Representation(
	char *binaryArray, char *hexArray,
	int isUppercase, int hexArraySize);

int Handling_Hexadecimal_Number_Upper(
	va_list theArgs,
	char *theBuffer,
	unsigned int theIndexOfTheBuffer);
char *Generate_Binary_Representation_3(
	char *binaryRepresentation, long int theGivenNumber,
	int isNegative, int theLimitOfBinary);

char *Generate_Hexadecimal_Representation_2(
	char *binaryArray, char *hexArray,
	int isUppercase, int hexArraySize);

int Handling_Rot13_Specifier(va_list theArgs,
		char *theBuffer,
		unsigned int numberOfBytesToPrint);

int Handling_Octal_Number(
	va_list theArgs,
	char *theBuffer,
	unsigned int theIndexOfTheBuffer);

#endif
