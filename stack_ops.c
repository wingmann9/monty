#include <stdio.h>
#include "monty.h"

/**
 * add_nodes - Adds top two elements of the stack
 * @stack: Pointer to pointer of the top node of the stack
 * @ln: Line number of of the opcode
 */
void add_nodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_msg(8, ln, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - Subtracts top two elements of the stack
 * @stack: Pointer to pointer of the top node of the stack
 * @ln: Line number of of the opcode
 */
void sub_nodes(stack_t **stack, unsigned int ln)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_msg(8, ln, "sub");

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - Divides top two elements of the stack
 * @stack: Pointer to pointer of the top node of the stack
 * @ln: Line number of of the opcode
 */
void div_nodes(stack_t **stack, unsigned int ln)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_msg(8, ln, "div");

	if ((*stack)->n == 0)
		error_msg(9, ln);

	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nodes - Multiplies top two elements of the stack
 * @stack: Pointer to pointer of the top node of the stack
 * @ln: Line number of of the opcode
 */
void mul_nodes(stack_t **stack, unsigned int ln)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_msg(8, ln, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - Modulus of top two elements of the stack
 * @stack: Pointer to pointer of the top node of the stack
 * @ln: Line number of of the opcode
 */
void mod_nodes(stack_t **stack, unsigned int ln)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_msg(8, ln, "mod");

	if ((*stack)->n == 0)
		error_msg(9, ln);

	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
