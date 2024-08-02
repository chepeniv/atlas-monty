# Project : Stacks and Queues
compilation : `gcc -Wall -Werror -Wextra -pedantic -ggdb3 *.c -o monty`

## objectives
- *what are LIFO and FIFO data structures ?*
- *what are stacks and queues and when to use which ?*
- *what is the proper way to use global variables ?*

## requirements
- no more than one global variable allowed
- no more than five functions per file
- usage of the c library is permitted
	- except for `malloc` and `free` no other function from `man malloc` is permitted
- include all function signatures in `monty.h`
- all header files should be include-guarded
- carryout the task in order

## `extern`
- *how to use extern to share variables between files ?*
- *what is an extern variable ?*
- *how is it declared ? what is its scope ?*
- *where should extern be used ?*



## the monty language
this project's goal is to create an interpreter for monty bytecode files

### monty bytecode
opcodes :

	- `push <int>` -- adds an element to the top of a stack with value `<int>`
	- `pop` -- removes the top element
	- `swap` -- swaps the top two elements
	- `add` -- adds the top two elements 
	- `pint` -- prints out the top element's value
	- `pall` -- prints out all of the element's values
	- `nop` -- doesn't do anything

typically monty bytecode files use the `.m` extension. there can only be one instruction per line along with any amount of whitespace. blank lines are also permitted. any text following the opcode and its arguments is ignored, effectively making the de facto comment.

### the monty program

- usage : `monty path/to/file.m`

for the following errors return exit status `EXIT_FAILURE` :
- if not exactly one file is given, print: `USAGE: monty file\n`
- if the file cannot be opened, print: `Error: Cant't open file <file>\n`
- if the file contains an invalid instruction, print: `L<line>: unknown instruction <opcode>\n` (line numbers always start at 1)
- the monty program runs the bytecodes line-by-line and stops if either
	- it successfully executed all lines of the file
	- found an error in the file
	- an error occured
- if no more memory could be allocated, print: `Error: malloc failed\n`
