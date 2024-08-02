#include "monty.h"

/*
 * op_pop()
 * op_swap
 * delete_stack -- repeatedly calling pop
 **/

void op_push(stacknode **top, char *data, unsigned int line)
{
	stacknode *new = NULL;
	int n;

	if (data == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stacknode));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	n = atoi(data);
	new->prev = NULL;
	new->n = n;
	if (*top == NULL)
		new->next = NULL;
	else {
		(*top)->prev = new;
		new->next = *top;
	}

	*top = new;
}

void op_pop(stacknode **top, char *data, unsigned int line)
{
	stacknode *old_top = NULL;

	op_nop(top, data, line);
	if (top == NULL || *top == NULL)
		return;

	old_top = *top;

	*top = (*top)->next;
	/*(*top)->prev = NULL;*/
	free(old_top);
}

void delete_stack(stacknode **top)
{
	if (top == NULL)
		return;

	while (*top != NULL)
	{
		op_pop(top, NULL, 0);
	}
}
