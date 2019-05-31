#include "lem_in.h"

void				free_adj(t_room **adj)
{
	t_tmp			*tmp;
	int 			i;
	t_tmp			*prev;

	i = 0;
	while (adj[i])
	{
		tmp = adj[i]->tmp;
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev);
		}
		free(adj[i]->name);
		free(adj[i]);
		i++;
	}
	free(adj);
}

void				free_lem(t_lem *lem)
{
	if (lem->adj)
		free_adj(lem->adj);
	free(lem);
}