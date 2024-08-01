#include "monty.h"
/* use atoi(), don't worry about int overflows */

instr *init_instr_set()
{
	instr instr_set[] = {
		{"push", op_push},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"pint", op_pint},
		{"pall", op_pall},
		{"nop", op_nop},
		{NULL, NULL},
	}
	return (instr_set);
}

void  (*get_instr(instr *set, char *opcode))(stacknode **top, unsigned int line)
{
	int i = 0;
	void (*f)(stacknode **stack, unsigned int line) = NULL;

	while(set[i]->opcode != NULL)
	{
		if (strcmp(opcode, set[i]->opcode) == 0)
		{
			f = set[i]->f;
			break;
		}
		i++;
	}
	return (f);
}

void exec_instr(
		char **opcode,
		void (*f)(stacknode **stack, unsigned int line),
		stacknode **stack,
		unsigned int line)
{
	if (f != NULL)
	{
		/*
		 * change f signature to handle both
		 * opcode and stack
		 */
		f(stack, opcode, line);
		return;
	}
	delete_stack(stack);
	op_invalid(opcode, line);
}
