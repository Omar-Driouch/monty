#include "monty.h"
 
/**
 * opcode_pstr - pstr
 * @stack: input
 * @line_number: input
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	while (curr != NULL && curr->n != 0 && curr->n >= 0 && curr->n <= 127)
	{
		putchar(curr->n);
		curr = curr->next;
	}
	putchar('\n');
}
