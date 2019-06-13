//
// Created by Hallie Stiv on 2019-06-13.
//
#include "lem_in.h"

static int 		is_ants_at_finish(t_group *group)
{
	int 		i;
	int 		res;

	i = 0;
	res = 0;
	while (group->path_array[i])
	{
		res += group->path_array[i]->end->ant;
		i++;
	}
	return (res);
}

void			make_prev_for_path(t_group *group)
{
	int 		i;
	t_room		*path;
	t_room		*tmp;

	i = 0;
	while (group->path_array[i])
	{
		path = group->path_array[i]->start;
		while (path->next)
		{
			tmp = path;
			path = path->next;
			path->prev  = tmp;
		}
		i++;
	}
}

static void		if_prev_end(t_room *tmp, t_path *path, int ants_bg)
{
	printf("L%d-%s ", tmp->ant, path->end->name);
	path->end->ant++;
	if (tmp->prev->ant != 0)
	{
		while (tmp->prev != path->start && tmp->prev->ant > 0)
		{
			tmp->ant = 0;
			tmp->ant = tmp->prev->ant;
			printf("L%d-%s ", tmp->ant, tmp->name);
			tmp = tmp->prev;
		}
		if (tmp->prev == path->start && ants_bg)
		{
			tmp->ant++;
			printf("L%d-%s ", tmp->ant, tmp->name);
		}
	}
}

static void		if_prev_start(t_room *tmp, t_path *path, int ants_bg)
{
	if (ants_bg)
	{
		tmp->ant = 1;
		printf("L%d-%s ", tmp->ant, tmp->name);
	}
}

void			push_ants(t_path *path, int ants_bg)
{
	t_room		*tmp;

	tmp = path->end->prev;
	while (!tmp->ant && tmp->prev != path->start)
		tmp = tmp->prev;
	if (tmp->next == path->end)
		if_prev_end(tmp, path, ants_bg);
	else if (tmp->prev == path->start && !tmp->ant)
		if_prev_start(tmp, path, ants_bg);
	else
	{
		while (tmp && tmp->prev != path->start && tmp->ant != 0)
		{
			tmp->next->ant = tmp->ant;
			printf("L%d-%s ", tmp->next->ant, tmp->next->name);
			tmp = tmp->prev;
			(!ants_bg) ? tmp->ant = 0 : 0;
		}
		if (tmp->prev == path->start && ants_bg)
		{
			tmp->next->ant = tmp->ant;
			printf("L%d-%s ", tmp->next->ant, tmp->next->name);
			tmp->ant++;
			printf("L%d-%s ", tmp->ant, tmp->name);
		}
	}
}

int				run_ants(t_group *group, t_lem *lem, int n)
{
	int 		i;

	group->ants = lem->ants;
	make_prev_for_path(group);
	while (lem->ants != is_ants_at_finish(group))
	{
		i = 0;
		while (group->path_array[i])
		{
			push_ants(group->path_array[i], (group->ants > 0) ? group->ants : 0);
			group->ants--;
			i++;
		}
		printf("\n");
		lem->oper++;
	}
	printf("%d", lem->oper);
}
