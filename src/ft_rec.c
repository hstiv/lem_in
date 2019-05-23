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

/*static int		ant_count_check(char *s, t_lem *lem)
{
	int			n;

	n = ft_atoi(s);
	if (ft_strcmp(ft_itoa(n), s) != 0)
		return (0);
	lem->ants = n;
}

static int		room_maker(t_room *room, char **s, t_lem *lem)
{
	int			i;

	i = 0;
	if (s[i][0] == '#' && s[i][1] == '#')
		return (1);
	
	ft_arraydel((void **)s);
	return (1);
}

static int		room_creator(t_lem *lrm, char **s)
{}
int				deep_valid(t_lem *lem, char **s)
{
	int			i;
	char		**s1;
	t_room		*room;
	int			c;

	i = 1;
	room = ft_newroom();
	if (s == NULL || s[0] == '\0' || !ant_count_check(s[0], lem))
		return (0);
	while (s[i] && s[i][ft_strlenc(s[i],'-')] == '\0')
	{
		if (!s[i] || !room_maker(room, ft_strsplit(s[i], ' '), lem))
			return (0);
		if (s[++i] && c != 0)
		{
			room->next = ft_newroom();
			room = room->next;
		}
		(c == 0) ? lem->end = room : 0;
	}
	if (!links_valid(s, i, lem))
		return (0);
	return (1);
}*/



char			**ft_rec(char *file_name, t_lem *lem)
{
	int			fd;
	char		buf[BUFF_SIZE + 1];
	int			y;
	char		***s;

	if (!(fd = open(file_name, O_RDONLY)))
		return (NULL);
	if ((y = read(fd, buf, BUFF_SIZE)) < 0)
		return (NULL);
	buf[y] = '\0';
	s = triple_split(ft_strsplit(buf, '\n'));
	if (!deep_valid(lem, s) || !deep_rec(lem, s))
		return (NULL);
	return (s);
}
