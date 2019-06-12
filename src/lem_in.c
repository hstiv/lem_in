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
	create_solution(find_best_group(group_list, lem));
	split_free(data);
	free_lem(lem);
	return (0);
}
