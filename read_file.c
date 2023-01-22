#include <stdio.h>
#include "monty.h"

/**
 * open_file - Opens the bytecode file
 * @fName: Name of the file
 */

void open_file(char *fName)
{
	int file_check;
	FILE *fd;

	/* Checks if the file exists */
	if (fName == NULL)
		error_msg(2, fName);
	file_check = access(fName, R_OK);
	if (file_check == -1)
		error_msg(2, fName);
	/* Open file if it exists & != empty */
	fd = fopen(fName, "r");
	if (fd == NULL)
		error_msg(2, fName);

	/* errors are handled inside this function */
	read_file(fd);
	/* check for errors on closing  file */
	fclose(fd);
}

/**
 * read_file - Reads the content of a file line by line
 * @fd: Pointer to file descriptor of opened file
 */

void read_file(FILE *fd)
{
	int line_n;
	int format;
	char *lineprt;
	size_t n;

	lineprt = NULL;
	n = 0;
	format = 0;

	if (fd == NULL)
		error_msg(2, "fName");

	/* Get each line in the file */
	for (line_n = 1; getline(&lineprt, &n, fd) != EOF; line_n++)
	{
		format = interpret_line(lineprt, line_n, format);
	}
	free(lineprt);
}


/**
 * interpret_line - Tokenizes each line to determine which function to call
 * @lineptr: line in a file
 * @ln: Line number for the opcode
 * @format: Format specifier. If
 *		0: Nodes are entered as stack
 *		1: Nodes are entered as queue
 *
 * Return: 0 if opcode is stack || 1 if queue
 */
int interpret_line(char *lineptr, int ln, int format)
{
	const char *delim;
	char *opcode;
	char *value;

	if (lineptr == NULL)
		error_msg(4);
	delim = "\n ";
	opcode = strtok(lineptr, delim);

	/* handling blank lines */
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	find_func(opcode, value, ln, format);
	return (format);
}

/**
 * find_func - Finds the appropite function to run opcode instructions
 * @opcode: Operation code
 * @value: Possible value for the operation
 * @ln: Line number for the opcode
 * @format: Format specifier. If
 *		0: Nodes are entered as a stack
 *		1: Nodes are entered as a queue
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_new},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", push},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	/* Iterates through list to find the right function */
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		/* When 0 found the right opcode */
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error_msg(3, ln, opcode);
}

/**
 * call_fun - Calls the required function
 * @f: Pointer to the called function
 * @op: opcode
 * @val: string representing a numeric value
 * @ln: line numeber for the instruction
 * @format: Format specifier. If
 *		0: Nodes are entered as a stack
 *		1: Nodes are entered as a queue.
 */
void call_fun(op_func f, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		/* Checks if the number is negative and move  val */
		if (val != NULL && val[0] == '-')
		{
			val++;
			flag = -1;
		}
		/* val is not a digit, return value is 0*/
		if (val == NULL)
			error_msg(5, ln);

		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error_msg(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			f(&node, ln);
		if (format == 1)
			push_queue(&node, ln);
	}
	else
		f(&head, ln);
}
