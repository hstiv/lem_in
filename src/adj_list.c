/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:46:51 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/02 17:40:13 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int				if_start(t_lem *lem, t_split *tmp, int *l)
{
	if (lem->begin || !(lem->adj[*l] = ft_newroom()))
		return (0);
	lem->adj[*l]->x = ft_atoi(tmp->name2);
	lem->adj[*l]->y = ft_atoi(tmp->name3);
	lem->adj[*l]->name = ft_strdup(tmp->name1);
	lem->begin = lem->adj[*l];
	lem->adj[*l]->nb = *l;
	(*l)++;
	return (1);
}

static	int				if_end(t_lem *lem, t_split *tmp, int *l)
{
	if (lem->end || !(lem->adj[*l] = ft_newroom()))
		return (0);
	lem->adj[*l]->x = ft_atoi(tmp->name2);
	lem->adj[*l]->y = ft_atoi(tmp->name3);
	lem->adj[*l]->name = ft_strdup(tmp->name1);
	lem->end = lem->adj[*l];
	lem->adj[*l]->nb = *l;
	(*l)++;
	return (1);
}

static int				if_common(t_lem *lem, t_split *tmp, int *l)
{
	if (!(lem->adj[*l] = ft_newroom()))
		return (0);
	lem->adj[*l]->x = ft_atoi(tmp->name2);
	lem->adj[*l]->y = ft_atoi(tmp->name3);
	lem->adj[*l]->name = ft_strdup(tmp->name1);
	lem->adj[*l]->nb = *l;
	(*l)++;
	return (1);
}

int						adj_list(t_lem *lem, t_split *split)
{
	t_room				**adj;
	int					l;
	t_split				*tmp;

	tmp = split;
	if (!(adj = (t_room **) malloc(sizeof(t_room *) * (lem->rooms_cnt + 1))))
		return (0);
	l = 0;
	lem->adj = adj;
	while (l < lem->rooms_cnt)
	{
		if (tmp->begin)
		{
			if (lem->begin || !(if_start(lem, tmp, &l)))
				return (0);
		}
		else if (tmp->end)
		{
			if (!lem->end && !(if_end(lem, tmp, &l)))
				return (0);
		}
		else if (l < lem->rooms_cnt && !if_common(lem, tmp, &l))
			return (0);
		tmp = tmp->next;
	}
	lem->adj[l] = NULL;
	if (!lem->begin || !lem->end)
		return (0);
//	lem->begin->ant = lem->ants;
	return(link_make(lem, tmp));
}
