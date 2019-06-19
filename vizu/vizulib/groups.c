/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:38:03 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/19 21:03:57 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

int			calc_max_group_size(t_lem *lem)
{
	int		min_paths;

	min_paths = min(lem->begin->link_count, lem->end->link_count);
	return (min(min(min_paths, lem->ants), lem->path_count));
}

t_group		*create_group(t_path **patharr, int size)
{
	t_group	*newgroup;
	int		pathsumlen;

	pathsumlen = 0;
	newgroup = malloc(sizeof(t_group));
	newgroup->size = size;
	newgroup->path_array = patharr;
	while (size--)
	{
		pathsumlen += patharr[size]->len;
	}
	newgroup->sumlen = pathsumlen;
	return (newgroup);
}

int			n_paths_sumlen(t_path **patharr, int len)
{
	int		sumlen;
	int		i;

	i = 0;
	sumlen = 0;
	while (i < len)
	{
		sumlen += patharr[i++]->len;
	}
	return (sumlen);
}

void		free_group(t_group *group)
{
	int		i;

	i = 0;
	while (i < group->size)
	{
		free_path_full(group->path_array[i]);
		i++;
	}
	free(group->path_array);
	free(group);
}
