#include "lem_in.h"

static int		ant_count_check(char *s, t_lem *lem)
{
	int			n;

	n = ft_atoi(s);
	if (ft_strcmp(ft_itoa(n), s) != 0)
		return (0);
	lem->ants = n;
	return (1);
}

int				deep_valid(t_lem *lem, char ***s)
{
	int			i;
	// char		**s1;
	t_room		*room;
	// int			c;

	i = 1;
	room = ft_newroom();
	if ((!ant_count_check(s[0][0], lem)))
		return (0);
	while (ft_len2(s[i]) != 2)
	{
		if (s[i][0][0] == 'L')
		{
			write(1, "Invalid name\n", 13);
			return (0);
		}
		while (s[i][0][0] == '#' && s[i][0])
		room->name = ft_strdup(s[i][0])
	}
	return (1);
}