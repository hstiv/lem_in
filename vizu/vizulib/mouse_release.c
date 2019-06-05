/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:35:30 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/05 18:35:39 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

int					mouse_release(int button, int x, int y, t_mlx *param)
{
	x = 0;
	y = 0;
	if (button == 1)
	{
		param->left_mouse = 0;
		if (param->mv)
			param->mv = 0;
	}
	if (button == 2)
	{
		param->right_mouse = 0;
		if (param->sl)
			param->sl = 0;
	}
	mlx_clear_window(param->ptr, param->wind);
	mappaint(param);
	putman(param);
	return (0);
}
