#include "monty.h"

/**
 * op_pint - print's out the top element's value
 * @top: the top of the prog stack
 * @data: the line data
 * @line: the line numeber
 *
 * Return: void
 */
void op_pint(stacknode **top, char *data, unsigned int line)
{

	op_nop(top, data, line);
	if (top == NULL || *top == NULL)
		return;

	printf("%d\n", (*top)->n);
}


/**
 * op_pall - prints out all of the stack node's values in pop-order
 * @top: the top of the stack
 * @data: the line data
 * @line: the line number
 *
 * Return: void
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
