/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:36:45 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 14:31:58 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void		delta(t_room *d0, t_room *d1, int *delx, int *dely)
{
	*delx = (d1->x - d0->x > 0) ? (d1->x - d0->x) : (d0->x - d1->x);
	*dely = (d1->y - d0->y > 0) ? (d1->y - d0->y) : (d0->y - d1->y);
}

static void		ft_dir(int *diry, int *dirx, t_room *d0, t_room *d1)
{
	*diry = (d0->y < d1->y) ? 1 : -1;
	*dirx = (d0->x < d1->x) ? 1 : -1;
}

void			ft_bresenham(t_room *d0, t_room *d1, t_mlx *mlx)
{
	int			delx;
	int			dely;
	int			diry;
	int			dirx;

	delta(d0, d1, &delx, &dely);
	ft_dir(&diry, &dirx, d0, d1);
	mlx->err = delx - dely;
	while (d0->x != d1->x || d0->y != d1->y)
	{
		mlx_pixel_put(mlx->ptr, mlx->wind, d0->x, d0->y, 16777215);
		mlx->derr = mlx->err * 2;
		if (mlx->derr > -dely)
		{
			mlx->err -= dely;
			d0->x += dirx;
		}
		if (mlx->derr < delx)
		{
			mlx->err += delx;
			d0->y += diry;
		}
	}
}
