/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:39:00 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/05 18:39:03 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

t_mlx				*ft_newmlx(void)
{
	t_mlx			*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx)
	{
		mlx->wind = NULL;
		mlx->ptr = NULL;
		mlx->lem = NULL;
		mlx->x_add = 0;
		mlx->y_add = 0;
		mlx->radius = 5;
		mlx->blue = 4518094;
		mlx->red = 16124995;
		mlx->green = 849467;
		mlx->yellow = 16776960;
		mlx->white = 16777215;
		mlx->l = 0.1;
		mlx->err = 0;
		mlx->derr = 0;
		mlx->left_mouse = 0;
		mlx->right_mouse = 0;
		mlx->mv = 0;
		mlx->fill = 1;
	}
	return (mlx);
}
