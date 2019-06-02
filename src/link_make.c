/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:03:55 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 17:03:57 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			ind_sch(t_lem *lem, char *s)
{
	int 			i;
	t_room			**adj;

	adj = lem->adj;
	i = 0;
	while (ft_strcmp(adj[i]->name, s) != 0)
		i++;
	return (i);
}

static void			lnk_connect(t_room **adj, int n1, int n2)
{
	t_room			*room;

	tmp = adj[n1]->tmp;
	if (!tmp)
	{
		tmp = ft_newtmp();
		tmp->room = adj[n2];
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_newtmp();
		tmp->next->prev = tmp;
		tmp->next->room = adj[n2];
	}
}

int 				link_make(t_lem *lem, char ***s, int i)
{
	int 			n1;
	int 			n2;

	while (s[i])
	{
		n1 = ind_sch(lem, s[i][0]);
		n2 = ind_sch(lem, s[i][1]);
		lnk_connect(lem->adj, n1, n2);
		lnk_connect(lem->adj, n2, n1);
		i++;
	}
	return (1);
}
