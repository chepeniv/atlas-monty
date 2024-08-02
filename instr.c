#include "monty.h"

void (*get_instr(instr set[], char *opcode))(stacknode **top, char *data, unsigned int line)
{
	int i = 0;
	void (*f)(stacknode **stack, char *data, unsigned int line) = NULL;

	while(set[i].opcode != NULL)
	{
		if (strcmp(opcode, set[i].opcode) == 0)
		{
			f = set[i].f;
			break;
		}
		i++;
	}

	if (f != NULL)
		return (f);
	exit(EXIT_FAILURE);
}

void exec_instr(
		char **opcode,
		void (*f)(stacknode **stack, char *data, unsigned int line),
		stacknode **stack,
		unsigned int line)
{
	if (f != NULL)
	{
		f(stack, opcode[1], line);
		return;
	}
	/*delete_stack(stack);
	op_invalid(opcode, line);*/
}
