#include "monty.h"

/**
 * pstr - Prints a string of characters from the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number (unused).
 *
 * This function traverses the stack, starting from the top, and prints each
 * character stored in the stack as long as the character's ASCII value is
 * within the range [0, 127]. It stops when it encounters a non-printable
 * character, a 0 value, or the end of the stack.
 * Return: void.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	while (curr != NULL && curr->n != 0 && curr->n >= 0 && curr->n <= 127)
	{
		putchar(curr->n);
		curr = curr->next;
	}
	putchar('\n');
}
