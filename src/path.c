/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:46:05 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/19 17:46:07 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		fill_intersection_array(t_path *path, t_lem *lem)
{
	char	*array;
	int		i;
	t_room	*start;

	start = path->start;
	array = gmalloc(sizeof(char) * (lem->rooms_cnt + 1));
	i = 0;
	while (start)
	{
		array[start->nb] == 0 ? (array[start->nb])++ :
		throw_error("path error");
		i++;
		start = start->next;
	}
	if (i != path->len)
		throw_error("fill intersection arr error");
	path->intersection_arr = array;
}

t_path		*create_path(void)
{
	t_path	*path;

	path = gmalloc(sizeof(t_path));
	if (path)
	{
		path->end = NULL;
		path->start = NULL;
		path->len = 0;
		path->next = NULL;
		path->intersection_arr = NULL;
	}
	return (path);
}

void		free_path_full(t_path *path)
{
	t_room	*room;
	t_room	*tmp;

	room = path->start;
	while (room)
	{
		tmp = room;
		room = room->next;
		free(tmp);
	}
	if (path->intersection_arr)
		free(path->intersection_arr);
	free(path);
}

void		free_path(t_path *path)
{
	if (path->intersection_arr)
		free(path->intersection_arr);
	free(path);
}
