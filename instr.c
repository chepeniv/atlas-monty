#include "monty.h"

/* make this an extern variable ??? */
instr *init_instr_set()
{
	instr instr_set[]= {
		{"push", op_push},
		{"pall", op_pall},
		/*{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"pint", op_pint},
		{"nop", op_nop},*/
		{NULL, NULL}
	};

	return (&instr_set[0]);
}

void (*get_instr(instr *set, char *opcode))(stacknode **top, char *data, unsigned int line)
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
	return (f);
}

void exec_instr(
		char **opcode,
		void (*f)(stacknode **stack, char *data, unsigned int line),
		stacknode **stack,
		unsigned int line)
{
	if (f != NULL)
	{
		f(stack, opcode[2], line);
		return;
	}
	/*delete_stack(stack);
	op_invalid(opcode, line);*/
}
