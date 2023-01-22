#include <stdio.h>
#include "monty.h"

/**
 * push - Adds a node to the stack.
 * @stack: Pointer to a pointer of the top node of the stack
 * @ln: Line number of the opcode
 */
void push(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		error_msg(7, ln);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * push_new - Adds new  node to the stack
 * @new_node: Pointer to the new node
 * @ln: Line number of the opcode.
 */
void push_new(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * push_queue - Adds new node to the queue
 * @new_node: Pointer to the new node
 * @ln: Line number of the opcode
 */
void push_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
