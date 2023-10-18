#include "monty.h"

/**
 * div_ - div the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void div_(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		div_error(line_number);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}


/**
 * div_error - Handle error on divison to a too short stack.
 *
 * @line_number: Line number where the error occurred.
 * Return: No return value; exits with failure status.
 */
void div_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
