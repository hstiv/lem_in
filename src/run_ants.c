#include "lem_in.h"

static int 		is_ants_at_finish(t_group *group)
{
	int 		i;
	int 		res;
//	int			ended_paths;

//	ended_paths = 0;
	i = 0;
	res = 0;
	while (i < group->size)
	{
		res += group->path_array[i]->end->ant;
//		if (group->path_array[i]->end->ant > 0)
//			ended_paths++;
		i++;
	}
//	return (ended_paths ? res / ended_paths : res);
	return (res);
}



static void		if_next_end(t_room *tmp, t_path *path, int ants_bg, int n)
{
	(n) ? printf("L%d-%s ", tmp->ant, tmp->next->name) : 0;
	path->end->ant++;
	tmp->ant = 0;
	if (tmp->prev->ant != 0)
	{
		while (tmp->prev != path->start && tmp->prev->ant > 0)
		{
			tmp->ant = tmp->prev->ant;
			(n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
			tmp = tmp->prev;
			tmp->ant = 0;
		}
		if (tmp->prev == path->start && ants_bg)
		{
			tmp->ant = tmp->next->ant + 1;
			(n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
		}
	}
}

static void		if_midd(t_room *tmp, t_path *path, int ants_bg, int n)
{
	while (tmp && tmp->prev != path->start && tmp->ant != 0)
	{
		tmp->next->ant = tmp->ant;
		(n) ? printf("L%d-%s ", tmp->next->ant, tmp->next->name) : 0;
		tmp = tmp->prev;
		(!ants_bg) ? tmp->ant = 0 : 0;
	}
	if (tmp && tmp->prev == path->start && tmp->ant)
	{
		tmp->next->ant = tmp->ant;
		(n) ? printf("L%d-%s ", tmp->next->ant, tmp->next->name) : 0;
		if (ants_bg)
		{
			tmp->ant = tmp->next->ant + 1;
			(n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
		}
		else
			tmp->ant = 0;
	}
}

void			push_ants(t_path *path, int ants_bg, int n)
{
	t_room		*tmp;

	tmp = path->end->prev;
	while (!tmp->ant && tmp->prev != path->start)
		tmp = tmp->prev;
	if (tmp->next == path->end)
		if_next_end(tmp, path, ants_bg, n);
	else if (tmp->prev == path->start && !tmp->ant)
	{
		if (ants_bg)
		{
			tmp->ant = 1;
			(n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
		}
	}
	else
		if_midd(tmp, path, ants_bg, n);
}

void	reset_ants_at_finish(t_group *group)
{
	int i;

	i = 0;
	while (i < group->size)
	{
		group->path_array[i++]->end->ant = 0;
	}
}

int				run_ants(t_group *group, t_lem *lem, int n)
{
	int 		i;

	lem->oper = 0;
	group->ants = lem->ants;
	make_prev_for_path(group);
	while (lem->ants != is_ants_at_finish(group))///something wrong
	{
		i = 0;
		while (i < group->size)
		{
			push_ants(group->path_array[i], (group->ants > 0) ? group->ants : 0, n);
			group->ants--;
			i++;
		}
		(n) ? printf("\n") : 0;
		lem->oper++;
	}
	(n) ? printf("%d", lem->oper) : 0;
	reset_ants_at_finish(group);
	return (lem->oper);
}
