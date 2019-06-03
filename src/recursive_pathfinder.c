//
// Created by Maybell Debbi on 2019-06-03.
//

#include "lem_in.h"



void	add_to_path(t_path *path, t_room *room)
{
	t_room *newroom = ft_newroom();
	*newroom = *room;

	newroom->prev = path->end;
	path->len++;
	if (!path->start)
		path->start = newroom;
	if (path->end)
		path->end->next = newroom;
	path->end = newroom;
	newroom->next = NULL;
}

void	remove_last_from_path(t_path *path)
{
	t_room *end;

	end = path->end;
	path->len--;
	if (path->len > 0)
	{
		path->end = end->prev;
		end->prev->next = NULL;
	}
	free(end);
}

void	print_path(t_path *path)
{
	t_room *start;

	start = path->start;
	while (start)
	{
		printf("%s->", start->name);
		start = start->next;
	}
	printf("\n");
}

int 	rpf(t_room *room, t_lem *lem, t_path *path)
{
	static int i = 0;
	i++;
	t_room *this_room = room;

	add_to_path(path, room);
	if (!room || room->visited == 1)
		return (0);
	if (room == lem->end)
	{
		print_path(path);
		remove_last_from_path(path);
		return (1);
	}
	room->visited = 1;
	room = room->next;
	while (room)
	{
		if (room->self->visited == 0 && rpf(lem->adj[room->nb], lem, path))
		{

//			printf("%d, %s\n",i, this_room->name);//

		}
		room = room->next;
	}
	this_room->visited = 0;
	remove_last_from_path(path);
	return (0);
}