#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		add_error(line_number);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
