#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		swap_error(line_number);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
