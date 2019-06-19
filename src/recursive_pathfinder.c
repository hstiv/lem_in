/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_pathfinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:26:40 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/19 17:26:43 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_to_path(t_path *path, t_room *room)
{
	t_room	*newroom;

	newroom = ft_newroom();
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

void		remove_last_from_path(t_path *path)
{
	t_room	*end;

	end = path->end;
	path->len--;
	if (path->len > 0)
	{
		path->end = end->prev;
		end->prev->next = NULL;
	}
	free(end);
	g_recursdepth--;
}

t_path		*copy_path(t_path *path)
{
	t_path	*copy;
	t_room	*pathhead;

	pathhead = path->start;
	copy = create_path();
	while (pathhead)
	{
		add_to_path(copy, pathhead);
		pathhead = pathhead->next;
	}
	return (copy);
}

void		add_path_to_all(t_path *path, t_path **path_list)
{
	path = copy_path(path);
	if (*path_list == NULL)
		*path_list = path;
	else
	{
		path->next = *path_list;
		*path_list = path;
	}
}

int			rpf(t_room *room, t_lem *lem, t_path *path, t_path **pathlist)
{
	int		path_count;
	t_room	*this_room;

	this_room = room;
	path_count = 0;
	g_recursdepth = 0;
	add_to_path(path, room);
	if (room == lem->end)
	{
		g_recursdepth--;
		add_path_to_all(path, pathlist);
		remove_last_from_path(path);
		return (1);
	}
	room->visited = 1;
	room = room->next;
	while (room)
	{
		if (room->self->visited == 0)
			path_count += rpf(lem->adj[room->nb], lem, path, pathlist);
		room = room->next;
	}
	this_room->visited = 0;
	remove_last_from_path(path);
	return (path_count);
}
