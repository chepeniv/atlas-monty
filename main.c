#include "monty.h"

int main(int argc, char **argv)
{
	stacknode *top = NULL;
	unsigned int line_num = 0;
	size_t read_bytes;
	FILE *monty_file;
	char **opcode = NULL,
		 *file_line = NULL,
		 *opcode = NULL,
		 *open_mode = "r";
	void (*f)(stacknode **stack, unsigned int line_number);
	instr *instr_set;

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

	instr_set = init_instr_set();
	while (getline(&file_line, &read_bytes, monty_file) > -1)
	{
		line_num++;
		opcode = parse(file_line);
		if (*opcode != NULL)
		{
			f = get_instr(opcode);
			exec_instr(opcode, f, top, line_num);
		}
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
