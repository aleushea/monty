#include "monty.h"
/**
 * f_push - a fn takes two parameters: head and counter for pushing a new node
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, each_digits = 0, flag = 0;
	/*** check if an argument represents the value to be pushed to stack ***/
	if (bus.arg)
	{
		/*** check if the number is negative ***/
		if (bus.arg[0] == '-')
			each_digits++;
		for (; bus.arg[each_digits] != '\0'; each_digits++)
		{
			if (bus.arg[each_digits] > 57 || bus.arg[each_digits] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

