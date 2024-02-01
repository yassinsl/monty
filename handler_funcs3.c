#include "monty.h"
#include "lists.h"

/**
 * rotl_handler - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotl_handler(stack_t **stack, unsigned int line_number)
{
    stack_t *current_top = *stack;
    int value = 0;

    (void)line_number;

    if (*stack == NULL)
        return;

    current_top = get_dnodeint_at_index(*stack, 0);
    value = current_top->n;
    delete_dnodeint_at_index(stack, 0);
    add_dnodeint_end(stack, value);
}

/**
 * rotr_handler - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
    stack_t *current_top = *stack;
    int value = 0, length = dlistint_len(*stack);

    (void)line_number;

    if (*stack == NULL)
        return;

    current_top = get_dnodeint_at_index(*stack, length - 1);
    value = current_top->n;
    delete_dnodeint_at_index(stack, length - 1);
    add_dnodeint(stack, value);
}

/**
 * stack_handler - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void stack_handler(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    data.qflag = 0;
}

/**
 * queue_handler - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void queue_handler(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    data.qflag = 1;
}

