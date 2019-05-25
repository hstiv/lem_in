/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:16:33 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/25 14:16:36 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem			*ft_newlem(void)
{
	t_lem		*new;

	new = (t_lem *)malloc(sizeof(t_lem));
	if (new)
	{
		new->s = NULL;
		new->ants = 0;
		new->rooms = 0;
		new->begin = NULL;
		new->end = NULL;
	}
	return (new);
}

t_room			*ft_newroom(void)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new)
	{
		new->w = 0;
		new->room_cnt = 0;
		new->ant = 0;
		new->x = 0;
		new->y = 0;
		new->bridge = NULL;
		new->next = NULL;
	}
	return (new);
}
