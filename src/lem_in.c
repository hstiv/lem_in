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


	lem = ft_newlem();
	if (ac != 2 || !(data = ft_rec(av[1], lem)))
	{
		free(lem);
		split_free(data);
		return (ft_err("Error\n"));
	}
	while(data->prev)
		data = data->prev;
//	ft_putnbr(lem->ants);
//	ft_putchar('\n');
//	while (data)
//	{
//		ft_putstr(data->name1);
//		ft_putchar(32);
//		ft_putstr(data->name2);
//		ft_putchar(32);
//		if (data->name3)
//		{
//			ft_putstr(data->name3);
//			ft_putchar(32);
//		}
//		ft_putnbr(data->begin);
//		ft_putchar(32);
//		ft_putnbr(data->end);
//		ft_putchar(32);
//		ft_putchar('\n');
//		data = data->next;
//	}
//	return (0);
	if (lem->ants <= 0 || !adj_list(lem, data))
	{
        free(lem);
        split_free(data);
        return (ft_err("Error\n"));
    }
//	t_path *path = create_path();
//	t_path *pathlist = NULL;
//	printf("total paths count: %d\n",lem->path_count = rpf(lem->begin, lem, path, &pathlist));

	lem->max_group_size = calc_max_group_size(lem);


//	lem->patharr = path_list_to_array(pathlist, lem->path_count, lem->rooms_cnt);
	//todo free pathlist here, no more need it
//	print_all_pathes(lem->patharr);


	print_path(dijkstra_search(lem));
//	printf("shortest path len = %d\n", lem->end->dijkstra);

//	t_path **two = find_two(lem->patharr);
//	printf("two shortest non intersecting paths are:\n");
//	print_path(two[0]);
//	print_path(two[1]);
	split_free(data);
	free_lem(lem);
	return (0);
}
