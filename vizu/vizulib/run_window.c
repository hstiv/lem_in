/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:34:29 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/05 18:34:32 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

int					ft_close(void *param)
{
	t_mlx			*tmp;

	tmp = (t_mlx *)param;
	exit(0);
	return (0);
}

void				run_window(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->wind = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, VIZU);
	mappaint(mlx);
	mlx_hook(mlx->wind, 17, (1L << 17), ft_close, mlx);
	mlx_hook(mlx->wind, 2, 0, key_press, mlx);
	mlx_hook(mlx->wind, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->wind, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->wind, 5, 0, mouse_release, mlx);
	mlx_loop(mlx->ptr);
}
