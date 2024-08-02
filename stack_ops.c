#include "monty.h"

/*
 * op_pop()
 * op_swap
 * create_tack -- might not need this func
 * delete_stack -- repeatedly calling pop
 **/

void op_push(stacknode **top, char *data, unsigned int line)
{
	stacknode *new = NULL;
	int n;

	if
	(data == NULL ||
	data[0] < '0' ||
	data[0] > '9')
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
