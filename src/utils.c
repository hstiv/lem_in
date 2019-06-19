/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:25:02 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/17 18:25:05 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			throw_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(0);
}

int				min(int a, int b)
{
	return (a < b ? a : b);
}

void			make_prev_for_path(t_group *group, t_lem *lem)
{
	int			i;
	t_room		*path;
	t_room		*tmp;

	i = 0;
	lem->oper = 0;
	lem->nb = 1;
	while (i < group->size)
	{
		path = group->path_array[i]->start;
		while (path->next)
		{
			tmp = path;
			path = path->next;
			path->prev = tmp;
		}
		i++;
	}
}

int				check_link(t_room *src, t_room *dest)
{
	src = src->next;
	while (src->next && src->self != dest)
		src = src->next;
	return (src->visited == 1) ? 0 : 1;
}

int				is_ants_at_finish(t_group *group)
{
	int			i;
	int			res;

	i = 0;
	res = 0;
	while (i < group->size)
	{
		res += group->path_array[i]->end->ant;
		i++;
	}
	return (res);
}
