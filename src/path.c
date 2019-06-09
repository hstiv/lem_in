//
// Created by Maybell Debbi on 2019-06-09.
//

#include "lem_in.h"

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