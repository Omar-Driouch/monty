#include "monty.h"

/**
 * execute_f - Execute an opcode-based function.
 *
 * @content: The string containing the opcode and optional arguments.
 * @stack: A pointer to the stack.
 * @numlin: The current line number.
 * @file: A pointer to the file.
 *
 * This function executes a function based on the provided opcode
 * Return: int 1 if the command executed esle 0;
 */

int execute_f(char *content, stack_t **stack, unsigned int numlin, FILE *file)
{
	char *content_copy, *token, *value;
	int valu, i = 0;
	instruction_t Spe_func[] = {{"push", push}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
	{"div", div_}, {"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
	{"div", div_}, {"rotl", rotl}, {"rotr", rotr},{NULL, NULL}};

	content_copy = strdup(content);
	token = strtok(content_copy, " \n\t");
	value = strtok(NULL, " \n\t");
	if (token == NULL || token[0] == '#')
	{
		free(content_copy);
		return (0);
	}
	if (strcmp(token, "push") == 0)
	{
		if (value == NULL || !is_valid_integer(value))
		{
			free(content_copy);
			push_error(numlin, file);
			return (0);
		}
		valu = atoi(value);
	}
	else
		valu = numlin;
	while (Spe_func[i].opcode)
	{
		if (strcmp(Spe_func[i].opcode, token) == 0)
		{
			Spe_func[i].f(&*stack, valu);
			free(content_copy);
			return (1);
		}
		i++;
	}
	global_error(numlin, file, token);
	free(content_copy);
	return (0);
}
