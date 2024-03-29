#ifndef _MONTY_H_
#define _MONTY_H_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

#define DATA_SIZE malloc(sizeof(stack_t))

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

extern stack_t *head;

/*Type for opcode functions*/
typedef void (*op_func)(stack_t **, unsigned int);

/* Error hanlding */
void error_msg(int error_code, ...);

/* File operations */
void open_file(char *);
void read_file(FILE *);
int len_chars(FILE *);
int interpret_line(char *, int, int);
void find_func(char *, char *, int, int);

/* Stack operations */
stack_t *create_node(int n);
void call_fun(op_func, char *, char *, int, int);
void push(stack_t **, unsigned int);
void push_new(stack_t **, unsigned int);
void push_queue(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void free_nodes(void);

/* Math operations with nodes */
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

#endif /* _MONTY_H_ */
