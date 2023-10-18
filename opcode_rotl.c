#include "monty.h"

/**
 * rotl - Rotates the stack to the left.
 * @stack: A pointer to the stack.
 * @line_number: The current line number (unused).
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;
	stack_t *current;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	new_top = (*stack)->next;
	current = new_top;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = *stack;
	(*stack)->prev = current;
	(*stack)->next = NULL;
	new_top->prev = NULL;

	*stack = new_top;
}
