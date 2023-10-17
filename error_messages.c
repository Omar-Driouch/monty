#include "monty.h"

/**
 * push_error - Report a "push" command usage error.
 *
 * @line_number: The line number where the error occurred.
 * Return: No return value, exits with failure status.
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * pall_error - Handle "pall" command when stack is empty.
 *
 * Return: No return value; it does nothing and returns.
 */
void pall_error(void)
{
	return; /* Do nothing when pall error occurs. */
}

/**
 * pint_error - Handle "pint" command when the stack is empty.
 *
 * @line_number: The line number where the error occurred.
 * Return: No return value; prints an error message and exits with failure
 * status.
 */
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
