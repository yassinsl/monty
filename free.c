#include "monty.h"
#include "lists.h"

/**
 * free_all - custom memory handling function
 * @release_all: flag to indicate what to free
 */
void free_all(int release_all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_everything(data.words);
		data.words = NULL;
	}

	if (release_all)
	{
		if (data.stack)
		{
			free_dlistint(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}

