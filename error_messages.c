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
 * global_error - Handle unknown instruction error.
 *
 * @line_number: The line number where the error occurred.
 * @file: A pointer to the file being processed.
 * @token: The token containing the unknown instruction.
 *
 * This function prints an error message indicating the line number and the
 * unknown instruction, frees allocated memory for the token, closes the file,
 * and exits the program with a failure status.
 *
 * Return: No return value; exits with failure status.
 */
void global_error(unsigned int line_number, FILE *file, char *token)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	free(token);
	fclose(file);
	exit(EXIT_FAILURE);
}
