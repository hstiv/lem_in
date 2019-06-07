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

static void			free_helper(char ***s)
{
	int				i;

	i = 0;
	while (s[i] != NULL)
		i++;
	i -= 1;
	while (i >= 0)
	{
		ft_arraydel(s[i]);
		i--;
	}
	free(s);
	s = NULL;
}

void				ft_triplefree(char ****s)
{
	int				i;

	i = 0;
	while (s[i] != NULL)
	{
		free_helper(s[i]);
		i++;
	}
	free(s);
}
