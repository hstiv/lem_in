//
// Created by Maybell Debbi on 2019-06-04.
//

#include "lem_in.h"

t_group	*create_group(t_path **patharr, int size)//todo testing
{
	t_group *newgroup;
	int pathsumlen;

	pathsumlen = 0;
	newgroup = malloc(sizeof(t_group));
	newgroup->size = size;
	newgroup->path_array = patharr;
	while (--size)
	{
		pathsumlen += patharr[size]->len;
	}
	newgroup->sumlen = pathsumlen;
	return (newgroup);
}

int get_new_combination(int **iter, int groupsize, int path_count)
{
	int i;

	i = groupsize;
	while (*iter[0] != path_count - groupsize)
	{
		i = groupsize;
		while (*iter[--i] )
		{

		}
	}
	return 0;
}

int n_paths_sumlen(t_path **patharr, int len)
{
	int sumlen;
	int i;

	i = 0;
	sumlen = 0;
	while (i < len)
	{
		sumlen += patharr[i++]->len;
	}
	return (sumlen);
}

t_group *find_best_group(t_path **patharr, int path_count, int groupsize)
{
	t_path **bestgroup;
	t_path **curgroup;
	int bestsum;
	int *iter;
	int i = -1;
	int cursum;

	bestsum = INT_MAX;
	bestgroup = ft_memalloc(sizeof(t_path*) * groupsize);
	curgroup = ft_memalloc(sizeof(t_path*) * groupsize);
	iter = ft_memalloc(sizeof(int) * groupsize);
	while (++i < groupsize)
		iter[i] = i;
	while (get_new_combination(&iter, groupsize, path_count))
	{
		i = 0;
		while (i < groupsize)
		{
			curgroup[i] = patharr[iter[i]];
			i++;
		}
		if (!is_intersecting_n_paths(curgroup, groupsize))
			if ((cursum = n_paths_sumlen(bestgroup, groupsize) < bestsum))
			{
				bestsum =  cursum;
				*bestgroup = *curgroup;
			}
	}
	free(curgroup);
	return (create_group(bestgroup, groupsize));
}