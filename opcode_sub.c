#include "monty.h"

/**
 * sub - substract the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		sub_error(line_number);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}


/**
 * sub_error - Handle error on substraction to a too short stack.
 *
 * @line_number: Line number where the error occurred.
 * Return: No return value; exits with failure status.
 */
void sub_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
