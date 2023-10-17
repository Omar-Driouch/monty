#include "monty.h"
/**
 * pop_error - Handle error on popping an empty stack.
 *
 * @line_number: Line number where the error occurred.
 * Return: No return value; exits with failure status.
 */
void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * swap_error - Handle error on swapping a too short stack.
 *
 * @line_number: Line number where the error occurred.
 * Return: No return value; exits with failure status.
 */
void swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * add_error - Handle error on adding to a too short stack.
 *
 * @line_number: Line number where the error occurred.
 * Return: No return value; exits with failure status.
 */
void add_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Report error on failed memory allocation.
 *
 * Return: No return value; exits with failure status.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
