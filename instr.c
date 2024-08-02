#include "monty.h"

/**
 * get_instr - find a function based on opcode given
 * @set: set of instructions
 * @opcode: the name of the instruction
 *
 * Return: a function pointer that carries out the instruction
 */
void
(*get_instr(instr set[], char *opcode))(
		stacknode **top,
		char *data,
		unsigned int line)
{
	int i = 0;
	void (*f)(stacknode **stack, char *data, unsigned int line) = NULL;

	while (set[i].opcode != NULL)
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

/**
 * exec_instr - runs the instruction given
 * @opcode: the full instruction
 * @f: the instruction
 * @stack: the stack storing the monty program data
 * @line: line number where the instruction occurs
 *
 * Return: void
 */
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
	delete_stack(stack);
	op_invalid(opcode, line);
}
