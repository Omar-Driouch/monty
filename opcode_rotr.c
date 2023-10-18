#include "monty.h"

/**
 * rotr - Rotates the stack to the right.
 * @stack: A pointer to the stack.
 * @line_number: The current line number (unused).
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
}
