#include "monty.h"
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * in a doubly linked list
 * @list: double pointer to the list
 * @index: index of the node to insert
 * @data: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **list, unsigned int index, int data)
{
    unsigned int i;
    dlistint_t *new_node;
    dlistint_t *temp = *list;

    if (index == 0)
        return (add_dnodeint(list, data));

    for (i = 0; temp && i < index; i++)
    {
        if (i == index - 1)
        {
            if (temp->next == NULL)
                return (add_dnodeint_end(list, data));

            new_node = malloc(sizeof(dlistint_t));
            if (!new_node || !list)
                return (NULL);

            new_node->n = data;
            new_node->next = NULL;
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next->prev = new_node;
            temp->next = new_node;

            return (new_node);
        }
        else
            temp = temp->next;
    }

    return (NULL);
}

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @data: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int data)
{
    dlistint_t *new_node;
    dlistint_t *temp = *head;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (!new_node)
        return (NULL);

    new_node->n = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }

    while (temp->next)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;

    return (new_node);
}

/**
 * free_dlistint - frees a doubly linked list
 * @list: pointer to the list to free
 */
void free_dlistint(dlistint_t *list)
{
    dlistint_t *temp;

    while (list)
    {
        temp = list->next;
        free(list);
        list = temp;
    }
}

