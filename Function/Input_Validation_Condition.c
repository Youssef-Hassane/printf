#include "../main.h"
#include "function.h"

/**
 * Input_Validation_Condition - Checks the input validation
 * condition for _printf function.
 * Return: 1 if the condition is true, 0 otherwise.
 * --------------------------
 * Prototype: int Input_Validation_Condition(
 * const char *theInputString, unsigned int index)
 * --------------------------
 * @theInputString: input string.
 * --------------------------
 * By Ahmed Abdelhamid
 */

int Input_Validation_Condition(const char *theInputString)
{
	/* Check if theInputString is a null pointer */
	/* or if the current character is '%' and the next character is null */
	return (!theInputString || (theInputString[0] == '%' && !theInputString[1]));
}
