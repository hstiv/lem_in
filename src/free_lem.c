#include "lem_in.h"

void				free_adj(t_room **adj)
{
	t_tmp			*tmp;
	int 			i;

	i = 0;
	while (adj[i])
		i++;
	while (i >= 0)
	{
		tmp = adj[i]->tmp;
		while (tmp && tmp->next)
			tmp = tmp->next;
		while (tmp)
		{
			tmp = tmp->prev;
			free(tmp->next);
		}
		if (tmp)
			free(tmp);
		i--;
	}
}

void				free_lem(t_lem *lem)
{
	if (lem->adj)
		free_adj(lem->adj);
	free(lem);
}