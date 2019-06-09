//
//	Created by Hallie Stiv on 2019-06-09.
//

#include "lem_in.h"

static void 		link_mark(int nb, t_room **adj, int nb1)
{
	t_room			*room;

	room = adj[nb];
	room->link_count -= 1;
	room = adj[nb]->next;
	while (room->self != adj[nb1] && room->next)
		room = room->next;
	room->visited = 1;
	room->self->link_count -= 1;
	room = room->self->next;
	while (room->self != adj[nb] && room->next)
		room = room->next;
	room->visited = 1;
}

void				dislinker(t_lem *lem, t_path *path)
{
	t_room			*room;
	t_room			*tmp;
	t_room			**adj;

	adj = lem->adj;
	room = path->end->prev;
	tmp = room;
	while (tmp->link_count <= 2 && adj[tmp->nb] != lem->begin)
		tmp = tmp->prev;
	if (tmp->link_count > 2 && adj[tmp->nb] != lem->begin)
		link_mark(tmp->nb, adj, tmp->next->nb);
	else
	{
		tmp = tmp->next;
		while (tmp->next)
		{
			adj[tmp->nb]->visited = 1;
			tmp = tmp->next;
		}
	}
}
