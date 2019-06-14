//
// Created by Maybell Debbi on 2019-06-09.
//

#include "lem_in.h"

void			throw_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(0);
}

int 			min(int a, int b)
{
	return (a < b ? a : b);
}

void			make_prev_for_path(t_group *group)
{
	int 		i;
	t_room		*path;
	t_room		*tmp;

	i = 0;
	while (group->path_array[i])
	{
		path = group->path_array[i]->start;
		while (path->next)
		{
			tmp = path;
			path = path->next;
			path->prev  = tmp;
		}
		i++;
	}
}