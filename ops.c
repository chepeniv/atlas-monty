#include "monty.h"

/* op_add */

void op_nop(stacknode **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

void op_invalid(char **opcode, unsigned int line)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line, *opcode);
	/*free opcode */
	exit(EXIT_FAILURE);
}
