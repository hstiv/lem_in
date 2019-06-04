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

int 	is_intersect(t_path *path1, t_path *path2)
{
	t_path *shorter;
	t_path *longer;
	t_room *shorthead;

	shorter = (path1->len < path2->len) ? path1 : path2;
	longer = (shorter == path1) ? path2 : path1;
	shorthead = shorter->start;
	while (shorthead)
	{
		if (shorthead != shorter->start && shorthead != shorter->end)
			if(longer->intersection_arr[shorthead->nb] != 0)
				return (1);
		shorthead = shorthead->next;
	}
	return (0);
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

int				main(int ac, char **av)
{
	char		***s;
	t_lem		*lem;

	lem = ft_newlem();
	if (ac != 2 || !(s = ft_rec(av[1], lem)))
	{
		free(lem);
		return (ft_err("Error\n"));
	}
	adj_list(lem, s);
	int path_count;
	t_path *path = create_path();
	t_path *pathlist = NULL;
	printf("total paths count: %d\n",path_count = rpf(lem->begin, lem, path, &pathlist));
	t_path **patharr;
	patharr = path_list_to_array(pathlist, path_count, lem->rooms_cnt);
	//todo free pathlist here, no more need it
	print_all_pathes(patharr);
//	printf("%d\n",is_intersect(patharr[6], patharr[42]));

	t_path **two = find_two(patharr);
	printf("two shortest non intersecting paths are:\n");
	print_path(two[0]);
	print_path(two[1]);
	ft_triplefree(s);
	free_lem(lem);
	return (0);
}
