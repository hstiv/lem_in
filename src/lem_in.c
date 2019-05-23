/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:58:35 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/19 13:58:37 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(int ac, char **av)
{
	char		**s;
	t_lem		*lem;

	lem = ft_newlem();
	if (ac != 2 || !(s = ft_rec(av[1], lem)))
	{
		perror("Error\n");
		return (0);
	}
	ft_arraydel((void **)s);
	free(lem);
	return (0);
}
