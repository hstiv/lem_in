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

void	throw_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(0);
}

void	fill_intersection_array(t_path *path, int node_count)
{
	char *array;
	int i;
	t_room *start;

	start = path->start;
	array = ft_memalloc(sizeof(char) * node_count);
	i = 0;
	while (start)
	{
		array[start->nb] == 0 ? array[start->nb]++ : throw_error("path error");
		i++;
		start = start->next;
	}
	if (i != path->len)
		throw_error("fill intersection arr error");
	path->intersection_arr = array;
}

t_path	**path_list_to_array(t_path *pathlist, int pathcount, int nodecount)
{
	int i;

	t_path *path;
	path = pathlist;
	t_path **patharr = malloc(sizeof(t_path*) * pathcount + 1);
	i = 0;
	while (path)
	{
		fill_intersection_array(path, nodecount);
		patharr[i++] = path;
		path = path->next;
	}
	patharr[i] = NULL;
	if (i != pathcount)
		throw_error("path to array error");
	return (patharr);
}

t_path	*create_path()
{
	t_path	*path;

	path = malloc(sizeof(t_path));
	path->end = NULL;
	path->start = NULL;
	path->len = 0;
	path->next = NULL;
	path->intersection_arr = NULL;
	return (path);
}
void	print_path(t_path *path)
{
	t_room *start;

	if (!path)
	{
		printf("empty path\n");
		return ;
	}
	start = path->start;
	while (start)
	{
		printf("%s->", start->name);
		start = start->next;
	}
	printf("\n");
}

void	print_all_pathes(t_path **patharr)
{
	while (*patharr)
	{
		print_path(*patharr++);
	}
}

t_path**	find_two(t_path **patharr)
{
	int sumlen = INT_MAX;
	int i = 0;
	int j;
	t_path	**two = ft_memalloc(sizeof(t_path*) * 2);
	while (patharr[i])
	{
		j = i + 1;
		while (patharr[j])
		{
			if (!is_intersect(patharr[i], patharr[j]))
			{
				if (patharr[i]->len + patharr[j]->len < sumlen)
				{
					sumlen = patharr[i]->len + patharr[j]->len;
					two[0] = patharr[i];
					two[1] = patharr[j];
				}
			}
			j++;
		}
		i++;
	}
	return (two);
}

int 	min(int a, int b)
{
	return (a < b ? a : b);
}

int		calc_max_group_size(t_lem *lem)
{
	int min_paths;

	min_paths = min(lem->begin->link_count, lem->end->link_count);
	return (min(min(min_paths, lem->ants), lem->path_count));
}

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
	t_path *path = create_path();
	t_path *pathlist = NULL;
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


//int main(){
//	t_queue *queue = ft_memalloc(sizeof(t_queue));
//	t_room *r1 = ft_newroom();
//	t_room *r2 = ft_newroom();
//	t_room *r3 = ft_newroom();
//	r1->dijkstra = 4;
//	r2->dijkstra = 5;
//	r3->dijkstra = 3;
//	add_to_priority_queue(r1, queue);
//	add_to_priority_queue(r2, queue);
//	add_to_priority_queue(r3, queue);
//	t_room *pop = pop_from_queue(queue);
//}
