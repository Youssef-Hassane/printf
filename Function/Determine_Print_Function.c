#include "../main.h"
#include "function.h"

/**
 * Determine_Function - Selects the appropriate function
 * for the task based on the provided identifier and position.
 * Return: Pointer to a function that matches the given identifier.
 * ----------------------
 * Prototype:
 * int (*Determine_Function(
 * const char *identifier,
 * int position))(va_list, char *, unsigned int)
 * ----------------------
 * @id: Argument identifier.
 * @p: Position for the argument identifier.
 * ----------------------
 * By Youssef Hassane
 * ----------------------
 * *id = identifier
 * p = position
 */

int (*Determine_Function(const char *id, int p))(va_list, char *, unsigned int)
{
	/* Initialize index variables for iteration */
	/* through functions and argument types */
	int index_1 = 0;
	int index_2 = 0;
	/* Array of structures mapping identifiers to corresponding functions */
	print_t functions[] = {
	    /* Handling Character Specifier */
	    {"c", Handling_Character_Specifier},
	    /* Handling String Specifier */
	    {"s", Handling_String_Specifier},
	    /* Handling Percent Sign Specifier */
	    {"%", Handling_Percent_Sign_Specifier},
	    /* Handling Integer that has the sign "i" Specifier */
	    {"i", Handling_Integer_Specifier},
	    /* Handling Integer that has the sign "d" Specifier */
	    {"d", Handling_Integer_Specifier},
	    /* Handling Binary Number Specifier */
	    {"b", Handling_Binary_Number},
	    /* Handling Unsigned Integer "u" Specifier */
	    {"u", Handling_Unsigned_Integer_Specifier},
	    /*Sentinel entry indicating the end of the array */
	    {"x", Handling_Hexadecimal_Number},
	    /* Handling Unsigned Integer "X" Specifier */
	    {"X", Handling_Hexadecimal_Number_Upper},
	    /* Handling Octal Number Specifier */
	    {"o", Handling_Octal_Number},
	    {NULL, NULL},
	};
	/* Find the index of the matching function in the 'functions' array */
	int matchingIndex = Find_Matching_Function_Index(
	    id, p,
	    &index_1, &index_2, functions);
	/* Return the pointer to the matching function */
	return (functions[matchingIndex].function_pointer);
}
