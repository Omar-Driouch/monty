#include "monty.h"

/**
 * pchar - pchar the elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		pchar_error(line_number);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pchar_error - Handle error on putcharto an empty stack .
 *
 * @line_number: Line number where the error occurred.
 * Return: No return value; exits with failure status.
 */
void pchar_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
