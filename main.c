#include "monty.h"

instr instr_set[] = {
	{"push", op_push},
	{"pop", op_pop},
	{"pint", op_pint},
	{"pall", op_pall},
	{NULL, NULL}
	/*
	 * {"swap", op_swap},
	 * {"add", op_add},
	 * {"nop", op_nop},
	 */
};

/**
 * main - init program
 * @argc: number of args passed
 * @argv: array of args passed
 *
 * Return: exit codes
 */
int main(int argc, char **argv)
{
	stacknode **top = NULL;
	unsigned int line_num = 0;
	size_t read_bytes;
	FILE *monty_file;
	char **opcode = NULL,
		 *file_line = NULL,
		 *open_mode = "r";
	void (*f)(stacknode **stack, char *data, unsigned int line);

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], open_mode);
	if (monty_file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	top = malloc(sizeof(void *));
	*top = NULL;
	while (getline(&file_line, &read_bytes, monty_file) > -1)
	{
		line_num++;
		opcode = parse(file_line);
		if (opcode[0] != NULL)
		{
			f = get_instr(instr_set, opcode[0]);
			exec_instr(opcode, f, top, line_num);
		}
		free(opcode);
	}
	free(file_line);
	delete_stack(top);
	free(top);
	fclose(monty_file);
	return (EXIT_SUCCESS);
}


/**
 * parse - tokenize a file line
 * @file_line: string to parse
 *
 * Return: token array of size two
 */
char **parse(char *file_line)
{
	char *delims = " \t\n";
	char **instr,
		 *opcode = NULL,
		 *arg = NULL;

	instr = malloc(sizeof(void *) * 2);
	if (instr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(file_line, delims);
	arg = strtok(NULL, delims);
	instr[0] = opcode;
	instr[1] = arg;

	return (instr);
}
