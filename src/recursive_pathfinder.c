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



//typedef struct {
//	int path_count;
//	t_path *path_list;
//} t_allpathes;

t_path	*copy_path(t_path *path)
{
	t_path *copy;
	t_room *pathhead;

	pathhead = path->start;
	copy = create_path();
	while (pathhead)
	{
		add_to_path(copy, pathhead);
		pathhead = pathhead->next;
	}
	return (copy);
}

void 	add_path_to_all(t_path *path, t_path **path_list)
{
//	t_path *tmp;
	path = copy_path(path);
	if (*path_list == NULL)
		*path_list = path;
	else{
//		tmp = *path_list;
		path->next = *path_list;
		*path_list = path;
	}
}

int 	rpf(t_room *room, t_lem *lem, t_path *path, t_path **pathlist)
{
	int path_count = 0;
	t_room *this_room = room;

	add_to_path(path, room);
	if (!room || room->visited == 1)
		return (0);
	if (room == lem->end)
	{
//		print_path(path);
		add_path_to_all(path, pathlist);
		remove_last_from_path(path);
		return (1);
	}
	room->visited = 1;
	room = room->next;
	while (room)
	{
		if (room->self->visited == 0)
		{
			path_count += rpf(lem->adj[room->nb], lem, path, pathlist);
		}
		room = room->next;
	}
	this_room->visited = 0;
	remove_last_from_path(path);
	return (path_count);
}