/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:46:51 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 15:50:38 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			if_start(t_lem *lem, char ***s, int *i, int *l)
{
	lem->adj[*l] = ft_newroom();
	(*i)++;
	lem->adj[*l]->x = ft_atoi(s[*i][1]);
	lem->adj[*l]->y = ft_atoi(s[*i][2]);
	lem->adj[*l]->name = ft_strdup(s[*i][0]);
	lem->begin = lem->adj[*l];
	lem->adj[*l]->nb = *l;
	(*i)++;
	(*l)++;
}

 static void			if_end(t_lem *lem, char ***s, int *i, int *l)
 {
	 lem->adj[*l] = ft_newroom();
	 (*i)++;
	 lem->adj[*l]->x = ft_atoi(s[*i][1]);
	 lem->adj[*l]->y = ft_atoi(s[*i][2]);
	 lem->adj[*l]->name = ft_strdup(s[*i][0]);
	 lem->end = lem->adj[*l];
	 lem->adj[*l]->nb = *l;
	 (*i)++;
	 (*l)++;
 }

 static void			if_common(t_lem *lem, char ***s, int *i, int *l)
 {
	lem->adj[*l] = ft_newroom();
	lem->adj[*l]->x = ft_atoi(s[*i][1]);
	lem->adj[*l]->y = ft_atoi(s[*i][2]);
	lem->adj[*l]->name = ft_strdup(s[*i][0]);
	lem->adj[*l]->nb = *l;
	(*i)++;
	(*l)++;
 }

 int					adj_list(t_lem *lem, char ***s)
 {
	t_room				**adj;
	int 				l;
	int 				i;

	l = 0;
	if (!(adj = (t_room**)malloc(sizeof(t_room*) * (lem->rooms_cnt + 1))))
		return (0);
	lem->adj = adj;
	i = 1;
	while (l != lem->rooms_cnt)
	{
		if (s[i][0][0] == '#' && s[i][0][2] == 's')
			if_start(lem, s, &i, &l);
		else if (s[i][0][0] == '#' && s[i][0][2] == 'e')
			if_end(lem, s, &i, &l);
		else
			if_common(lem, s, &i, &l);
	}
	lem->adj[l] = NULL;
	return (link_make(lem, s, i));
 }
