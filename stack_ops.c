#include "monty.h"

/**
 * is_int - checks whether a string is an integer
 * @str: string to analyze
 *
 * Return: true or false
 */
int is_int(char *str)
{
	int i = 0;

	if
	(str == NULL ||
	(!isdigit(str[i]) && str[i] != '-'))
		return (false);

	i++;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}

	return (true);
}

/**
 * op_push - puts a new node at the top of the stack
 * @top: the top of the stack
 * @data: the line data
 * @line: the line number
 *
 * Return: void
 */
void op_push(stacknode **top, char *data, unsigned int line)
{
	stacknode *new = NULL;
	int n;

	if (!is_int(data))
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
	else
	{
		(*top)->prev = new;
		new->next = *top;
	}

	*top = new;
}

/**
 * op_pop - removes the top element of the stack given
 * @top: the top of the stack
 * @data: the line data
 * @line: the line number
 *
 * Return: void
 */
void op_pop(stacknode **top, char *data, unsigned int line)
{
	stacknode **new_top = NULL;

	op_nop(top, data, line);
	if (top == NULL || *top == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	new_top = malloc(sizeof(void *));
	if (new_top == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*new_top = (*top)->next;

	free(*top);
	*top = *new_top;
	free(new_top);
}

/**
 * op_swap - swaps the order of the top two nodes of the given stack
 * @top: the top of the stack
 * @data: the line data
 * @line: the line number
 *
 * Return: void
 */
void op_swap(stacknode **top, char *data, unsigned int line)
{
	stacknode **newtop;

	(void) data;
	if
	(top == NULL ||
	*top == NULL ||
	(*top)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	newtop = malloc(sizeof(void *));
	if (newtop == NULL)
		exit(EXIT_FAILURE);

	*newtop = (*top)->next;
	(*top)->prev = *newtop;
	(*top)->next = (*newtop)->next;
	(*newtop)->prev = NULL;
	(*newtop)->next = *top;
	*top = *newtop;
	free(newtop);
}

/**
 * delete_stack - completely frees the memory allocated for a stack
 * @top: top of the stack
 *
 * Return: void
 */
void delete_stack(stacknode **top)
{
	if (top == NULL)
		return;

	while (*top != NULL)
	{
		op_pop(top, NULL, 0);
	}
}
