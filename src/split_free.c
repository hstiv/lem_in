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

#include "lem_in.h"

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
		free(tmp->name1);
		free(tmp->name2);
		if (tmp->l == 3)
			free(tmp->name3);
	}
}
