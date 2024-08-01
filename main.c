#include "monty.h"

int main(int argc, char **argv)
{
	stacknode *top = NULL;
	unsigned int line_num = 0;
	size_t read_bytes;
	FILE *monty_file;
	char **opcode = NULL,
		 *file_line = NULL,
		 *open_mode = "r";

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty <file>\n" );
		return (EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], open_mode);
	if (monty_file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Cant't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	top = malloc(sizeof(stacknode));
	if (top == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = 0;
	top->next = NULL;
	top->prev = NULL;

	while (getline(&file_line, &read_bytes, monty_file) > -1)
	{
		line_num++;
		opcode = parse(file_line);

		/*
		 * match item
		 * call matching func and pass arg
		 * if no match print error ?
		 *
		 * use atoi(), don't worry about overflows
		 */
	}

	free(file_line);
	fclose(monty_file);

	return (EXIT_SUCCESS);
}

char **parse(char *file_line)
{
	char *delims = " \t\n";
	char *line_dup = strdup(file_line);
	char **instr,
		 *opcode = NULL,
		 *arg = NULL;

	opcode = strtok(line_dup, delims);
	if (opcode != NULL)
		arg = strtok(line_dup, delims);

	instr = malloc(sizeof(void *) * 2);
	if (instr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(line_dup);
		exit(EXIT_FAILURE);
	}

	instr[0] = opcode;
	instr[1] = arg;

	free(line_dup);
	return (instr);
}
