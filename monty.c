#include "monty.h"

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content = NULL;
	size_t content_size = 0;
	size_t char_read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	char *file_path = argv[1];
	FILE *file = fopen(file_path, "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((char_read = getline(&content, &content_size, file)) != (size_t)-1)
	{
		if (content[char_read - 1] == '\n')
			content[char_read - 1] = '\0';
		execute_f(content, &stack, line_number, file);
		line_number++;
	}

	fclose(file);
	free_stack(&stack);
	free(content);
	return (0);
}
