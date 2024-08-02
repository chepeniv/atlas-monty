#include "monty.h"

/* pint */

void op_pall(stacknode **top, char *data, unsigned int line)
{
	stacknode *next;

	(void)data;
	(void)line;

	if (*top == NULL)
		return;

	next = *top;
	while (next != NULL)
	{
		printf("%d\n", next->n);
		next = next->next;
	}
}
