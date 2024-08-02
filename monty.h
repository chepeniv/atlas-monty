#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
typedef struct _instr
{
        char *opcode;
        void (*f)(stacknode **stack, char *data, unsigned int line);
} instr;

extern instr instr_set[];

char **parse(char *file_line);
void exec_instr(
		char **opcode,
		void (*f)(stacknode **stack, char *data, unsigned int line),
		stacknode **stack,
		unsigned int line);

void (*get_instr(instr *set, char *opcode))(stacknode **top, char *data, unsigned int line);
void op_push(stacknode **top, char *data, unsigned int line);
void op_pop(stacknode **top, char *data, unsigned int line);
void op_nop(stacknode **top, char *data, unsigned int line);
void op_pint(stacknode **top, char *data, unsigned int line);
void op_pall(stacknode **top, char *data, unsigned int line);
void op_invalid(char **opcode, unsigned int line);
void delete_stack(stacknode **top);

#endif
