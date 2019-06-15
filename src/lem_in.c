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

void		print_group(t_group *group)
{
	int 		i;
	t_room		*room;

	i = 0;
	printf("\nGroup------------------\n\n");
	while (i < group->size)
	{
		room = group->path_array[i]->start;
		while (room)
		{
			if (room != group->path_array[i]->end)
				printf("%s->", room->name);
			else
				printf("%s\n", room->name);
			room = room->next;
		}
		i++;
	}
	printf("\nend group---------------\n\n");
}

t_path *backtrace_path(t_room *room, t_lem *lem)
{
	t_path *res_path;
	t_room *cur_room;
	t_room *link;
	t_room *better_link;

	res_path = create_path();
	add_to_path(res_path, lem->end);
	cur_room = room->self;
	while (cur_room != lem->begin)
	{
		add_to_path(res_path, cur_room);
		link = cur_room->next;
		better_link = NULL;
		while (link)
		{
			if (!check_link(link->self, cur_room))
				if (!better_link || (link->self->dijkstra < better_link->self->dijkstra))
					better_link = link;
			link = link->next;
		}
		cur_room = better_link->self;
	}
	add_to_path(res_path, lem->begin);
	return (reverse_path(res_path));
}

t_group *make_group(t_lem *lem)
{
	t_path **patharr;
	t_room *end;
	t_room *link;
	int i;

	i = 0;
	end = lem->end;
	link = end->next;
	patharr = ft_memalloc(sizeof(t_room*) * lem->end->link_count);
	while (link)
	{
		if (!check_link(link->self, end))
		{
			patharr[i] = backtrace_path(link, lem);
			fill_intersection_array(patharr[i++], lem);
		}
		link = link->next;
	}
	return (create_group(patharr, i));
}

t_group					*find_best_group(t_group *best_group, t_lem *lem)
{
	t_group *cur_group;

	cur_group = make_group(lem);

	if (is_intersecting_n_paths(cur_group->path_array, cur_group->size))
	{
		printf("^^^^^^^WARNING: Group has intersections!!!!^^^^^^^^^");
		print_group(cur_group);
	}
	cur_group = delete_intersecting_paths(cur_group);
	print_group(cur_group);
	if (!best_group)
		return (cur_group);
	if (cur_group && run_ants(cur_group, lem, 0) < run_ants(best_group, lem, 0))
		return (cur_group);
	return (best_group);
}

int				main(int ac, char **av)
{
	t_split		*data;
	t_lem		*lem;
	t_path		*shortest_path;

	lem = ft_newlem();
	if (ac != 2 || !(data = ft_rec(av[1], lem)))
	{
		free(lem);
		split_free(data);
		return (ft_err("Error\n"));
	}
//	while(data->prev)
//		data = data->prev;
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

//	print_path(shortest_path = dijkstra_search(lem));
//	switch_links(shortest_path, lem);
//	print_path(shortest_path = dijkstra_search(lem));
//	switch_links(shortest_path, lem);
//	print_path(shortest_path = dijkstra_search(lem));
//	switch_links(shortest_path, lem);
//	print_path(shortest_path = dijkstra_search(lem));


	t_group *best_group = NULL;
	while ((shortest_path = dijkstra_search(lem)) != NULL)
	{
		printf("\n\nshortest path:   ");
		print_path(shortest_path);
		switch_links(shortest_path, lem);
		best_group = find_best_group(best_group, lem);

	}
	printf("best group for this antcount:\n");
	print_group(best_group);
	run_ants(best_group, lem, 1);
//	create_solution(best_group);
	split_free(data);
	free_lem(lem);
	return (0);
}
