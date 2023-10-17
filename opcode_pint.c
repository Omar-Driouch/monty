#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		pint_error(line_number);
	}

	printf("%d\n", (*stack)->n);
}
