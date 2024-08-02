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
	stacknode **new_top;

	(void) data;

	if
	(top == NULL ||
	*top == NULL ||
	(*top)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	new_top = malloc(sizeof(void *));
	if (new_top == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	*new_top = (*top)->next;
	a = (*new_top)->n;
	b = (*top)->n;
	(*new_top)->n = a + b;
	(*new_top)->prev = NULL;

	free(*top);
	*top = *new_top;
	free(new_top);
}
