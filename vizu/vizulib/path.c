/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:56:40 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/19 20:57:41 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

void		fill_intersection_array(t_path *path, t_lem *lem)
{
	char	*array;
	int		i;
	t_room	*start;

	start = path->start;
	array = ft_memalloc(sizeof(char) * (lem->rooms_cnt + 1));
	i = 0;
	while (start)
	{
		array[start->nb] == 0 ? (array[start->nb])++
		: throw_error("path error");
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

	path = malloc(sizeof(t_path));
	path->end = NULL;
	path->start = NULL;
	path->len = 0;
	path->next = NULL;
	path->intersection_arr = NULL;
	return (path);
}

void		print_path(t_path *path)
{
	t_room	*start;

	if (!path)
	{
		printf("empty path\n");
		return ;
	}
	start = path->start;
	while (start)
	{
		printf("%s->", start->name);
		start = start->next;
	}
	printf("\n");
}

void		print_all_pathes(t_path **patharr)
{
	while (*patharr)
	{
		print_path(*patharr++);
	}
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
