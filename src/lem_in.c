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
	patharr = gmalloc(sizeof(t_room *) * lem->end->link_count);
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
	{
		free_group(best_group);
		return (cur_group);
	}
	free_group(cur_group);
	return (best_group);
}

int				main(int ac, char **av)
{
	t_split		*data;
	t_lem		*lem;
	t_path		*shortest_path;

	g_memlist = create_memlist();
	lem = ft_newlem();
	data = NULL;
	if (ac != 2 || !(data = ft_rec(av[1], lem)))
	{
		free(lem);
		if (data != NULL)
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
		free_path(shortest_path);
		best_group = find_best_group(best_group, lem);

	}
	printf("best group for this antcount(%d): \n", lem->ants);
	if (!best_group)
		throw_error("no possible pathes");
	print_group(best_group);
	run_ants(best_group, lem, 1);
	free_group(best_group);

	split_free(data);
	free_lem(lem);
	return (0);
}

//void	free_memlist(t_memlist *memlist)
//{
//	t_memnode *start;
//
//	start = memlist->start;
//	while (start)
//	{
//		if (start->memptr)
//			free(start->memptr);
//		start->memptr = NULL;
//		start = start->next;
//	}
//}

//int main()
//{
//	g_memlist = create_memlist();
//	char *str = gmalloc(10);
//	char *str2 = gmalloc(20);
//	char *str3 = gmalloc(200);
//	char *str4 = gmalloc(200);
//	char **s;
////	s = (char **)ftg_memalloc(sizeof(char *) * 20000000);
//	printf("%s\n", str4);
//	str4 = gmalloc(100);
////	str2 = g_memalloc(200);
////	free_memlist(g_memlist);
//}