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

t_split			*ft_rec(char *file_name, t_lem *lem)
{
	int			fd;
	char 		*s;
	int 		t;
	t_split		*tmp;

	s = NULL;
	if (!(fd = open(file_name, O_RDONLY)) || fd < 0)
		return (NULL);
	t = 0;
	tmp = NULL;
	while (get_next_line(fd, &s))
	{
		if (s[0] != '#' && !cnt_char(s, 32) && !cnt_char(s, '-') && ft_isdigit(s[0]))
		{
			if (!lem->ants && check_number(s))
				lem->ants = ft_atoi(s);
			else
				return (0);
		}
		else if (ft_strequ(s, "##start") || ft_strequ(s, "##end"))
			t = (s[2] == 's') ? 1 : 2;
		else if (ft_count_char(s, ' ') == 3 && s[0] != '#')
		{
			tmp = (tmp) ? addlst(tmp, 3, &t) : ft_newsplit();
			if (!common_room(tmp, ft_strsplit(s, ' '), &t))
			{
				free(s);
				return (0);
			}
			lem->rooms_cnt++;
			t = 0;
		}
		else if (ft_count_char(s, '-') == 2 && s[0] != '#')
		{
			tmp = (tmp) ? addlst(tmp, 2, &t) : ft_newsplit();
			linker(tmp, ft_strsplit(s, '-'));
		}
		free(s);
	}
	if (!lem->rooms_cnt)
	{
		split_free(tmp);
		return (NULL);
	}
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}