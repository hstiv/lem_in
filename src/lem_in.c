/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:58:35 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/02 17:42:28 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//t_path**	find_two(t_path **patharr)
//{
//	int sumlen = INT_MAX;
//	int i = 0;
//	int j;
//	t_path	**two = ft_memalloc(sizeof(t_path*) * 2);
//	while (patharr[i])
//	{
//		j = i + 1;
//		while (patharr[j])
//		{
//			if (!is_intersect(patharr[i], patharr[j]))
//			{
//				if (patharr[i]->len + patharr[j]->len < sumlen)
//				{
//					sumlen = patharr[i]->len + patharr[j]->len;
//					two[0] = patharr[i];
//					two[1] = patharr[j];
//				}
//			}
//			j++;
//		}
//		i++;
//	}
//	return (two);
//}

//int 			ant_run(t_path *path, int is_print, int ants)
//{
//	t_room		*tmp;
//
//	tmp = path->end->prev;
//	while (tmp->ant == 0 && tmp->prev)
//		tmp = tmp->prev;
//	if (ants || tmp->ant == 0)
//	{
//
//	}
//}
//
//int				create_solution(t_group *group, int is_print, t_lem *lem)
//{
//	int 		i;
//	t_room		*room;
//	t_room		*tmp;
//	int 		t;
//	int 		oper;
//
//	i = 0;
//	t = 1;
//	oper = 0
//	while (i < group->size)
//	{
//		room = group->path_array[i]->start;
//		while (room->next)
//		{
//			tmp = room;
//			tmp->self = lem->adj[tmp->nb];
//			room = room->next;
//			room->prev = tmp;
//		}
//		i++;
//	}
//	while (lem->end->ant != lem->ants)
//	{
//		i = 0;
//		t = 0;
//		while (i < group->size || t == 2)
//		{
//			t += ant_run(group->path_array[i], is_print, lem->ants);
//			i++;
//			if (lem->ants)
//				lem->ants--;
//		}
//		oper++;
//	}
//}

static void		print_group(t_group *group)
{
	int 		i;
	t_room		*room;

	i = 0;
	while (i < group->size)
	{
		room = group->path_array[i]->start;
		while (room)
		{
			if (room != group->path_array[i]->end)
				printf("%s->", room->name);
			else
				printf("%s", room->name);
			room = room->next;
		}
		printf("\n");
	}
}

int				main(int ac, char **av)
{
	t_split		*data;
	t_lem		*lem;
	t_group		*group_list;
	t_path		*shortest_path;

	lem = ft_newlem();
	group_list = NULL;
	if (ac != 2 || !(data = ft_rec(av[1], lem)))
	{
		free(lem);
		split_free(data);
		return (ft_err("Error\n"));
	}
	while(data->prev)
		data = data->prev;
	if (lem->ants <= 0 || !adj_list(lem, data))
	{
        free(lem);
        split_free(data);
        return (ft_err("Error\n"));
	}
	lem->max_group_size = calc_max_group_size(lem);
//	lem->patharr = path_list_to_array(pathlist, lem->path_count, lem->rooms_cnt);
	//todo free pathlist here, no more need it
//	print_all_pathes(lem->patharr);
	while ((shortest_path = dijkstra_search(lem)) != NULL)
	{
		switch_links(shortest_path, lem);
		add_group(group_list, lem);
	}
	print_group(find_best_group(group_list, lem));
//	create_solution(find_best_group(group_list, lem), 0, lem);
	split_free(data);
	free_lem(lem);
	return (0);
}
