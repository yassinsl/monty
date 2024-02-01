#include "monty.h"

/**
 * dlistint_len - returns the number of nodes in a doubly linked list
 * @current: pointer to the list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *current)
{
    size_t nodes = 0;

    if (!current)
        return (0);

    while (current)
    {
        nodes++;
        current = current->next;
    }

    return (nodes);
}

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @data: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int data)
{
    dlistint_t *new_node;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (!new_node)
        return (NULL);

    new_node->n = data;

    new_node->next = *head;
    new_node->prev = NULL;

    if (*head)
        (*head)->prev = new_node;

    *head = new_node;

    return (new_node);
}

/**
 * print_dlistint - prints a doubly linked list
 * @current: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *current)
{
    size_t nodes = 0;

    if (!current)
        return (0);

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
        nodes++;
    }

    return (nodes);
}

/**
 * delete_dnodeint_at_index - deletes a node in a doubly linked list
 * at a given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp = *head;
    unsigned int i = 0;

    if (!index)
    {
        (*head) = temp->next;
        if (temp->next)
            temp->next->prev = NULL;
        temp->next = NULL;
        free(temp);
        return (1);
    }

    while (i < index)
    {
        temp = temp->next;
        i++;
        if (!temp)
            return (0);
    }

    temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);

    return (1);
}

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list
 * @current: pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *current, unsigned int index)
{
    unsigned int i = 0;

    if (!current)
        return (NULL);

    while (current && i < index)
    {
        current = current->next;
        i++;
    }

    return (current ? current : NULL);
}

