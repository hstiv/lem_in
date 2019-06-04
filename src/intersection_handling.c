//
// Created by Maybell Debbi on 2019-06-04.
//

#include "lem_in.h"

int 	is_intersect(t_path *path1, t_path *path2)
{
	t_path *shorter;
	t_path *longer;
	t_room *shorthead;

	shorter = (path1->len < path2->len) ? path1 : path2;
	longer = (shorter == path1) ? path2 : path1;
	shorthead = shorter->start;
	while (shorthead)
	{
		if (shorthead != shorter->start && shorthead != shorter->end)
			if(longer->intersection_arr[shorthead->nb] != 0)
				return (1);
		shorthead = shorthead->next;
	}
	return (0);
}

int		is_intersecting_n_paths(t_path **path_arr, int size)//todo testing
{
	int i;
	int j;

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