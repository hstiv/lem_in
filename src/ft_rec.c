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

/*
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
{}*/

/*static void		linker(t_room *beg, char **s, int i)
{

}

static int		record(char ***s, t_lem *lem)
{
	t_room		**map;
	t_room		*rom;
	t_room		*beg;
	int			i;

	i = 1;
	beg = rom;
	map = (t_room**)malloc(sizeof(t_room*) * (lem->rooms_cnt + 1));
	while (ft_len2(s[i] != 2 && s[i]))
	{
		if (!rom)
			rom = ft_newroom();
		else
		{
			rom->next = ft_newroom();
			rom = rom->next;
		}
		if (s[i][0][1] == '#' && s[i][0][2] == 's')
		{
			i++;
			lem->begin = rom;
		}
		else if (s[i][0][1] == '#' && s[i][0][2] == 'e')
		{
			i++;
			lem->end = rom;
		}
		rom->name = ft_strdup(s[i][0]);
		rom->x = ft_atoi(s[i][1]);
		rom->y = ft_atoi(s[1][2]);
	}
	linker(beg, s, i);
}
*/
char			***ft_rec(char *file_name, t_lem *lem)
{
	int			fd;
	char		buf[BUFF_SIZE + 1];
	int			y;
	int			o;
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
	while (s[y] != NULL)
	{
		o = 0;
		while (s[y][o] != NULL)
		{
			ft_putstr(s[y][o]);
			ft_putchar(' ');
			o++;
		}
		ft_putchar('\n');
		y++;
	}
	lem->ants += 1;
	//todo deep_valid for multiple start/end, name with 'L' at the beginning
//	if (!deep_valid(lem, s))
//		return (NULL);
	return (s);
}
