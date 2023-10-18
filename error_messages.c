#include "monty.h"

/**
 * push_error - Report a "push" command usage error.
 *
 * @line_number: The line number where the error occurred.
 * @file: sdv
 * Return: No return value, exits with failure status.
 */
void push_error(unsigned int line_number, FILE *file)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	fclose(file);
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

/**
 * global_error - Handle errors and exit the program.
 * @lr: The line number where the error occurred.
 * @file: A pointer to the file that's being processed (can be NULL).
 * @token: A string representing the problematic instruction.
 * @stack: A pointer to a stack data structure (can be NULL).
 */
void global_error(unsigned int lr, FILE *file, char *token, stack_t **stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", lr, token);
	free_stack(stack);
	free(token);
	fclose(file);
	exit(EXIT_FAILURE);
}
