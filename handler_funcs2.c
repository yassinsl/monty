#include "monty.h"
#include "lists.h"

/**
 * sub_handler - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void sub_handler(stack_t **stack, unsigned int line_number)
{
    int difference = 0;
    stack_t *result_node = NULL;
    stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
    stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO, SUB_FAIL, line_number);
        free_all(1);
        exit(EXIT_FAILURE);
    }

    difference = node_1->n - node_0->n;
    delete_dnodeint_at_index(stack, 0);
    delete_dnodeint_at_index(stack, 0);
    result_node = add_dnodeint(stack, difference);
    if (!result_node)
    {
        dprintf(STDERR_FILENO, MALLOC_FAIL);
        free_all(1);
        exit(EXIT_FAILURE);
    }
}

/**
 * div_handler - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void div_handler(stack_t **stack, unsigned int line_number)
{
    int quotient = 0;
    stack_t *result_node = NULL;
    stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
    stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO, DIV_FAIL, line_number);
        free_all(1);
        exit(EXIT_FAILURE);
    }

    if (node_0->n == 0)
    {
        dprintf(STDERR_FILENO, DIV_ZERO, line_number);
        free_all(1);
        exit(EXIT_FAILURE);
    }

    quotient = node_1->n / node_0->n;
    delete_dnodeint_at_index(stack, 0);
    delete_dnodeint_at_index(stack, 0);
    result_node = add_dnodeint(stack, quotient);
    if (!result_node)
    {
        dprintf(STDERR_FILENO, MALLOC_FAIL);
        free_all(1);
        exit(EXIT_FAILURE);
    }
}

/**
 * mul_handler - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mul_handler(stack_t **stack, unsigned int line_number)
{
    int product = 0;
    stack_t *result_node = NULL;
    stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
    stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO, MUL_FAIL, line_number);
        free_all(1);
        exit(EXIT_FAILURE);
    }

    product = node_1->n * node_0->n;
    delete_dnodeint_at_index(stack, 0);
    delete_dnodeint_at_index(stack, 0);
    result_node = add_dnodeint(stack, product);
    if (!result_node)
    {
        dprintf(STDERR_FILENO, MALLOC_FAIL);
        free_all(1);
        exit(EXIT_FAILURE);
    }
}

/**
 * mod_handler - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mod_handler(stack_t **stack, unsigned int line_number)
{
    int remainder = 0;
    stack_t *result_node = NULL;
    stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
    stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO, MOD_FAIL, line_number);
        free_all(1);
        exit(EXIT_FAILURE);
    }

    if (node_0->n == 0)
    {
        dprintf(STDERR_FILENO, DIV_ZERO, line_number);
        free_all(1);
        exit(EXIT_FAILURE);
    }

    remainder = node_1->n % node_0->n;
    delete_dnodeint_at_index(stack, 0);
    delete_dnodeint_at_index(stack, 0);
    result_node = add_dnodeint(stack, remainder);
    if (!result_node)
    {
        dprintf(STDERR_FILENO, MALLOC_FAIL);
        free_all(1);
        exit(EXIT_FAILURE);
    }
}

