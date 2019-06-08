/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:16:47 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 15:46:39 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					len_rooms(char ***s)
{
	int				i;
	int				l;

	i = 0;
	l = 0;
	while (s[i] != NULL && ft_len2(s[i]) != 2)
	{
		if (s[i][0][0] == '#')
			i++;
		if (ft_len2(s[i]) == 3 && s[i][0][0] != '#')
			l++;
		i++;
	}
	return (l);
}

static int			ft_cmp(char **s, int i)
{
	if (ft_strequ(s[i], "##start") || ft_strequ(s[i], "##end"))
		return (1);
	else if (s[i][0] == '#')
		return (0);
	return (1);
}

static void			linksplit(char ***s, char **str, int i, int l)
{
	int				o;

//	o = l;
	while (str[i] != NULL)
	{
		while (str[i + 1] != NULL && !ft_cmp(str, i))
			i++;
		if (ft_cmp(str, i))
		{
            s[l] = ft_strsplit(str[i], '-');
            l++;
            i++;
        }
		else
		    i++;
	}
//	if (o == 0 || i == o)
//		return (0);
//	o = len_rooms(s);
//	return (o);
}

static int			deep_valid(char ***s, int j, t_lem *lem, int cnt)
{
	int				i;
	int				l;

	i = 1;
	if (cnt == 1 && !ft_isdigit(s[0][0][0]))
		return (0);
	if (cnt == 1)
		lem->ants = ft_atoi(s[0][0]);
	while (i < j)
	{
		l = i + 1;
		if (s[i][0][0] == 'L')
			return (0);
		while (l < j)
		{
			if (ft_strequ(s[i][0], s[l][0]))
				return (0);
			l++;
		}
		i++;
	}
	return (1);
}

char				***triple_split(char **str, t_lem *lem, int	cnt)
{
	char			***s;
	int				i;
	int				l;

	if (str == NULL || *str == NULL)
    {
	    if (str)
	        free(str);
	    return (NULL);
    }
	l = ft_len2(str);
	i = 0;
	if (!(s = (char ***)malloc(sizeof(char **) * (l + 1))))
		return (NULL);
	while (i <= l)
		s[i++] = NULL;
	l = 0;
	i = 0;
	while (str[i] && str[i][ft_strlenc(str[i], '-')] == '\0')
	{
		while (!ft_cmp(str, i))
			i++;
		if (str[i] != NULL && ft_strlenc(str[i], '-') == ft_strlen(str[i]))
        {
			s[l] = ft_strsplit(str[i], ' ');
			l++;
			i++;
		}
	}
	if (!deep_valid(s, l, lem, cnt))
	{
		ft_arraydel(str);
		return (NULL);
	}
	if (str[i] && str[i][ft_strlenc(str[i], '-') == '-'])
		linksplit(s, str, i, l);
//	l = 0;
//    while (s[l])
//    {
//        ft_putstr(s[l][0]);
//        ft_putchar(32);
//        ft_putstr(s[l][1]);
//		ft_putchar(32);
//		ft_putstr(s[l][1]);
//        ft_putchar('\n');
//        l++;
//    }
//    return (NULL);
	ft_arraydel(str);
	return (s);
}
