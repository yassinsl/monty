#include "monty.h"
#include "lists.h"

/**
 * pchar_handler - handles the pchar instruction
 * @custom_stack: double pointer to the stack to push to
 * @line_number_custom: number of the line in the file
 */
void pchar_handler(stack_t **custom_stack, unsigned int line_number_custom)
{
	stack_t *custom_node = *custom_stack;

	if (!custom_node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number_custom);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (custom_node->n < 0 || custom_node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number_custom);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(custom_node->n);
	putchar('\n');
}

/**
 * pstr_handler - handles the pstr instruction
 * @custom_stack: double pointer to the stack to push to
 * @line_number_custom: number of the line in the file
 */
void pstr_handler(stack_t **custom_stack, unsigned int line_number_custom)
{
	stack_t *custom_node = *custom_stack;

	(void)line_number_custom;

	if (!custom_node)
	{
		putchar('\n');
		return;
	}

	while (custom_node && custom_node->n != 0 && custom_node->n >= 0 && custom_node->n <= 127)
	{
		putchar(custom_node->n);
		custom_node = custom_node->next;
	}

	putchar('\n');
}

