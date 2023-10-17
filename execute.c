#include "monty.h"

/**
 * execute_f - Execute an opcode-based function.
 *
 * @content: The string containing the opcode and optional arguments.
 * @stack: A pointer to the stack.
 * @numlin: The current line number.
 * @file: A pointer to the file.
 *
 * This function executes a function based on the provided opcode and handles
 * known instructions. It returns 1 for valid instructions or 0 for unknown
 * ones,
 * printing an error message and exiting in the latter case.
 *
 * Return: 1 for a valid instruction, 0 for unknown instructions.
 */

int execute_f(char *content, stack_t **stack, unsigned int numlin, FILE *file)
{
	instruction_t Spe_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};
	int i = 0;

	if (content == NULL || content[0] == '#')
	{
		/* Skip comments and empty lines*/
		return (0);
	}

	while (Spe_func[i].opcode)
	{
		if (strcmp(Spe_func[i].opcode, content) == 0)
		{
			Spe_func[i].f(stack, numlin);
			return (1);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", numlin, content);
	fclose(file);
	exit(EXIT_FAILURE);
	return (0);
}
