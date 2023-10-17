#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (value == NULL || !atoi(value))
	{
		push_error(line_number);
	}


	if (!new_node)
	{
		malloc_error();
	}

	new_node->n = atoi(value);
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
