#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		malloc_error();
		return;
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
