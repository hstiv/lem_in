//
// Created by Maybell Debbi on 2019-06-19.
//
#include "libft.h"



void	add_to_memlist(t_memlist *memlist, t_memnode *node)
{
	t_memnode *start;

	memlist->allocs_count++;

	if (!memlist->start)
		memlist->start = node;
	else{
		start = memlist->start;
		while (start->next)
		{
			start = start->next;
		}
		start->next = node;
	}
}

t_memlist *create_memlist()
{
	t_memlist *memlist;

	memlist = malloc(sizeof(t_memlist));
	memlist->allocs_count = 0;
	memlist->start = NULL;
	return (memlist);
}

t_memnode *create_memnode(void *memptr)
{
	t_memnode *memnode;
	memnode = malloc(sizeof(t_memnode));
	memnode->memptr = memptr;
	memnode->next = NULL;
	return (memnode);
}

void	*gmalloc(size_t size)
{
	void *memptr;

	memptr = ft_memalloc(size);
	add_to_memlist(g_memlist, create_memnode(memptr));
	return (memptr);
}