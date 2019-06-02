/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:02:15 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/23 14:49:35 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


char			***ft_rec(char *file_name, t_lem *lem)
{
	int			fd;
	char		buf[BUFF_SIZE + 1];
	int			y;
//	int			o;
	char		***s;

	if (!(fd = open(file_name, O_RDONLY)))
		return (NULL);
	if ((y = read(fd, buf, BUFF_SIZE)) < 0)
		return (NULL);
	buf[y] = '\0';
	if (!(s = triple_split(ft_strsplit(buf, '\n'), lem)))
		return (NULL);
	y = 0;
	if (!lem->rooms_cnt)
	{
		ft_triplefree(s);
		return (NULL);
	}
	// edge_list(lem, s);
//	while (s[y] != NULL)
//	{
//		o = 0;
//		while (s[y][o] != NULL)
//		{
//			ft_putstr(s[y][o]);
//			ft_putchar(' ');
//			o++;
//		}
//		ft_putchar('\n');
//		y++;
//	}
	lem->ants += 1;
	//todo deep_valid for multiple start/end, name with 'L' at the beginning
//	if (!deep_valid(lem, s))
//		return (NULL);
	return (s);
}
