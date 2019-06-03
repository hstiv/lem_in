//
// Created by Maybell Debbi on 2019-06-03.
//

#include <includes/lem_in.h>

int 	rpf(t_room *room, t_lem *lem)
{
	static int i = 0;
	i++;
	t_room *this_room = room;

	if (!room || room->visited == 1)
		return (0);
	if (room == lem->end)
		return (1);
	room->visited = 1;
	room = room->next;
	while (room)
	{
		if (rpf(lem->adj[room->nb], lem))
		{
			printf("%d, %s\n",i, this_room->name);
			return (1);
		}
		room = room->next;
	}
	this_room->visited = 0;
	return (0);
}