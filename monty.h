#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct _stack_node - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct _stack_node
{
        int n;
        struct _stack_node *prev;
        struct _stack_node *next;
} stacknode;

/**
 * struct _instruction - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct _instruction
{
        char *opcode;
        void (*f)(stacknode **stack, unsigned int line_number);
} instruction;

#endif
