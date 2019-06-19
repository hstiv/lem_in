/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:38:46 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/05 18:38:49 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void		x_and_y(int keycode, t_mlx *param)
{
	if (keycode == 53)
		ft_close((void *)param);
	if (keycode == 13)
		param->y_add -= CON;
	if (keycode == 1)
		param->y_add += CON;
	if (keycode == 2)
		param->x_add += CON;
	if (keycode == 0)
		param->x_add -= CON;
	if (keycode == 3)
		param->fill += 1;
	if (keycode == 69)
		param->l += 0.1;
	if (keycode == 78)
		param->l -= 0.1;
	if (keycode == 259)
		param->cmnd = 1;
	if (keycode == 5)
		ft_input(param);
}

int				key_release(int keycode, t_mlx *param)
{
	if (keycode == 259)
	{
		param->cmnd = 0;
		param->cor = 0;
	}
	return (0);
}

int				key_press(int keycode, t_mlx *param)
{
	x_and_y(keycode, param);
	mlx_clear_window(param->ptr, param->wind);
	mappaint(param);
	putman(param);
	return (0);
}
