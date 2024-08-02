#include "monty.h"

/**
 * op_pint -
 * @top:
 * @data:
 * @line:
 *
 * Return:
 */
void op_pint(stacknode **top, char *data, unsigned int line)
{

	op_nop(top, data, line);
	if (top == NULL || *top == NULL)
		return;

	printf("%d\n", (*top)->n);
}


/**
 * op_pall -
 * @top:
 * @data:
 * @line:
 *
 * Return:
 */
void op_pall(stacknode **top, char *data, unsigned int line)
{
	stacknode *next;

	if (top == NULL)
		return;

	next = *top;
	while (next != NULL)
	{
		op_pint(&next, data, line);
		next = next->next;
	}
}
