#include "monty.h"
/**
 * free_stack - frees a doubly linked list
 * @stack: head of the stack
 */
void free_stack(stack_t **stack)
{
	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	while (*stack != NULL)
	{
		stack_t *tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
