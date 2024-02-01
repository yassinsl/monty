#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

size_t dlistint_len(const dlistint_t *current);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
size_t print_dlistint(const dlistint_t *current);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
dlistint_t *get_dnodeint_at_index(dlistint_t *current, unsigned int index);
dlistint_t *insert_dnodeint_at_index(dlistint_t **list, unsigned int index, int data);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int data);
void free_dlistint(dlistint_t *list);

#endif
