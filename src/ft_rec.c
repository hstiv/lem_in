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

char			****ft_rec(char *file_name, t_lem *lem)
{
	int			fd;
	char		buf[BUFF_SIZE];
	int			y;
	char 		****s;
	int 		i;

	i = 0;
	s = (char ****)malloc(sizeof(char ***) * 10);
	while (i < 10)
		s[i++] = NULL;
	i = 0;
	if (!(fd = open(file_name, O_RDONLY)))
		return (NULL);
	while ((y = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[y] = '\0';
		if (!(s[i] = triple_split(ft_strsplit(buf, '\n'), lem, i + 1)))
		{
			if (i > 0)
				ft_triplefree(s);
			return (NULL);
		}
		i++;
	}
	if (!lem->rooms_cnt)
	{
		ft_triplefree(s);
		return (NULL);
	}
	return (s);
}
