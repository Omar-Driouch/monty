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

/**
 * is_valid_integer - Check if a string is a valid integer.
 *
 * @str: The string to be checked for being a valid integer.
 *
 * This function checks if the given string represents a valid integer. It
 * allows for an optional leading plus or minus sign. If the string is empty or
 * contains non-digit characters after the optional sign, it is considered
 * invalid.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_valid_integer(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
