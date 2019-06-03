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
t_path	*create_path()
{
	t_path	*path;

	path = malloc(sizeof(t_path));
	path->end = NULL;
	path->start = NULL;
	path->len = 0;
	return (path);
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
	t_path *path = create_path();
	rpf(lem->begin, lem, path);
	ft_triplefree(s);
	free_lem(lem);
	return (0);
}
