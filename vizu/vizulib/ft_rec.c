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
		free(tmp->name1);
		free(tmp->name2);
		if (tmp->l == 3)
			free(tmp->name3);
	}
}

static int		cnt_char(char *s, char c)
{
	int			i;
	int			l;
	
	i = 0;
	l = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			l++;
		i++;
	}
	return (l);
}

static t_split		*addlst(t_split *tmp, int l, int *t)
{
	t_split		*split;

	split = ft_newsplit();
	tmp->next = split;
	split->prev = tmp;
	tmp->l = l;
	if (*t == 1)
		split->begin = 1;
	else if (*t == 2)
		split->end = 1;
	*t = 0;
	return (split);
}

static int		common_room(t_split *tmp, char **s, int *t)
{
	if (ft_len2(s) != 3)
	{
		split_free(tmp);
		ft_arraydel(s);
		return (0);
	}
	tmp->name1 = ft_strdup(s[0]);
	tmp->name2 = ft_strdup(s[1]);
	tmp->name3 = ft_strdup(s[2]);
	ft_arraydel(s);
	if (tmp->name1[0] == 'L')
	{
		split_free(tmp);
		return (0);
	}
	if ((*t) == 1)
		tmp->begin = 1;
	else if (*t == 2)
		tmp->end = 1;
	return (1);
}

static int		linker(t_split *tmp, char **s)
{
	if (ft_len2(s) != 2)
	{
		split_free(tmp);
		ft_arraydel(s);
		return (0);
	}
	tmp->name1 = ft_strdup(s[0]);
	tmp->name2 = ft_strdup(s[1]);
	ft_arraydel(s);
	return (1);
}

t_split			*ft_rec(char *file_name, t_lem *lem)
{
	int			fd;
	char 		*s;
	int 		t;
	t_split		*tmp;

	if (!(fd = open(file_name, O_RDONLY)) || fd < 0)
		return (NULL);
	t = 0;
	tmp = NULL;
	while (get_next_line(fd, &s))
	{
		if (s[0] != '#' && !cnt_char(s, 32) && !cnt_char(s, '-') && ft_isdigit(s[0]))
		{
			if (!lem->ants)
				lem->ants = ft_atoi(s);
			else
				return (0);
		}
		else if (ft_strequ(s, "##start") || ft_strequ(s, "##end"))
			t = (s[2] == 's') ? 1 : 2;
		else if (cnt_char(s, ' ') == 2 && s[0] != '#')
		{
			tmp = (tmp) ? addlst(tmp, 2, &t) : ft_newsplit();
			if (!common_room(tmp, ft_strsplit(s, ' '), &t))
			{
				free(s);
				return (0);
			}
			lem->rooms_cnt++;
			t = 0;
		}
		else if (cnt_char(s, '-') == 1 && s[0] != '#')
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