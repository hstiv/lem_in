/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:01:54 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/19 21:02:28 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void		ants_are_on_run(t_room **adj, char **s, t_mlx *mlx)
{
	int			i;

	i = 0;
	while (adj[i])
	{
		if (ft_strequ(adj[i]->name, s[1]))
		{
			adj[i]->color = mlx->green;
			ft_arraydel(s);
			return ;
		}
		i++;
	}
}

void			ft_input(t_mlx *mlx)
{
	char		*str;
	char		**s;
	char		**s1;
	int			i;

	i = 0;
	resert_color(mlx);
	if (get_next_line(0, &str) > 0)
	{
		s = ft_strsplit(str, ' ');
		free(str);
		resert_color(mlx);
		while (s[i])
		{
			s1 = ft_strsplit(s[i], '-');
			ants_are_on_run(mlx->lem->adj, s1, mlx);
			i++;
		}
		ft_arraydel(s);
		mappaint(mlx);
		putman(mlx);
	}
	else
		exit(0);
}
