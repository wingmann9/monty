#include <stdio.h>
#include "monty.h"

/**
 * print_top - Prints the top node of the stack
 * @stack: Pointer to pointer of the top node of the stack
 * @ln: Line number of of the opcode
 */
void print_top(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		error_msg(6, ln);
	printf("%d\n", (*stack)->n);
}

/**
 * print_stack - Print elements of the stack
 * @stack: Pointer to a pointer of the top node of the stack
 * @ln: Line number of the opcode
 */
void print_stack(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	(void) ln;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to pointer of the top node of the stack
 * @ln: Line number of of the opcode
 */
void print_char(stack_t **stack, unsigned int ln)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		error_msg(11, ln);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		error_msg(10, ln);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to pointer of the top node of the stack
 * @ln: Line number of of the opcode
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
