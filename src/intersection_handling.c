/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:07:51 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/19 15:07:52 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_intersect(t_path *path1, t_path *path2)
{
	t_path	*shorter;
	t_path	*longer;
	t_room	*shorthead;

	shorter = (path1->len < path2->len) ? path1 : path2;
	longer = (shorter == path1) ? path2 : path1;
	shorthead = shorter->start;
	while (shorthead)
	{
		if (shorthead != shorter->start && shorthead != shorter->end)
			if (longer->intersection_arr[shorthead->nb] != 0)
				return (1);
		shorthead = shorthead->next;
	}
	return (0);
}

int			is_intersecting_n_paths(t_path **path_arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (is_intersect(path_arr[i], path_arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_group		*newpatharr(t_path **patharr, t_group *group, int newsize)
{
	int		i;
	int		j;
	t_path	**newpatarr;

	i = 0;
	j = 0;
	newpatarr = malloc(sizeof(t_path*) * newsize);
	while (i < group->size)
	{
		if (patharr[i])
			newpatarr[j++] = patharr[i];
		i++;
	}
	free(group);
	return (create_group(newpatarr, newsize));
}

t_group		*delete_intersecting_paths(t_group *group)
{
	int		i;
	int		j;
	int		newsize;

	newsize = group->size;
	i = -1;
	while (++i < group->size)
	{
		j = i + 1;
		while (j < group->size)
		{
			if (group->path_array[i] && group->path_array[j])
				if (is_intersect(group->path_array[i], group->path_array[j]))
				{
					if (group->path_array[i]->len > group->path_array[j]->len)
						group->path_array[i] = NULL;
					else
						group->path_array[j] = NULL;
					newsize--;
				}
			j++;
		}
	}
	return (newpatharr(group->path_array, group, newsize));
}
