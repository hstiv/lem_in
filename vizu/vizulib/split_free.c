/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triplefree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:16:40 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/25 14:16:42 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

void			split_free(t_split *split)
{
	t_split		*tmp;

	if (!split)
		return ;
	while (split->prev)
		split = split->prev;
	while (split)
	{
		tmp = split;
		split = split->next;
		if (tmp->name1)
		{
			free(tmp->name1);
			tmp->name1 = NULL;
			if (tmp->name2)
			{
				free(tmp->name2);
				tmp->name2 = NULL;
				(tmp->l == 3) ? free(tmp->name3) : 0;
				tmp->name3 = NULL;
			}
		}
	}
}
