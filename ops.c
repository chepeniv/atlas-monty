#include "monty.h"

/**
 * op_invalid - the command ran if an invalid function is given
 * @opcode: the instruction tokens
 * @line: the instruction's line number
 *
 * Return: void
 */
void op_invalid(char **opcode, unsigned int line)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line, *opcode);
	free(opcode);
	exit(EXIT_FAILURE);
}

/**
 * op_nop - the do-nothing instruction
 * @stack: the program's stack
 * @data: the line data
 * @line: the line number
 *
 * Return:
 */
void op_nop(stacknode **stack, char *data, unsigned int line)
{
	(void)stack;
	(void)data;
	(void)line;
}

void op_add(stacknode **top, char *data, unsigned int line)
{
	int a, b;

	(void) data;
	if
	(top == NULL ||
	*top == NULL ||
	(*top)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	a = (*top)->n;
	b = (*top)->next->n;
	(*top)->next->n = a + b;
	*top = (*top)->next;
	free((*top)->prev);
	(*top)->prev = NULL;
}
