/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:38:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/05 18:38:21 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

int					mouse_move(int x, int y, t_mlx *param)
{
	if (param->left_mouse && param->right_mouse)
	{
		param->x_add = x;
		param->y_add = y;
		param->mv = 1;
	}
	mlx_clear_window(param->ptr, param->wind);
	mappaint(param);
	return (0);
}
