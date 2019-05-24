#include "lem_in.h"

static int			cmp(char **s, int i)
{
	if (!ft_strcmp(s[i], "##start") || !ft_strcmp(s[i], "##end"))
		return (1);
	else if (s[i][0] == '#')
		return (0);
	return (1);
}

static void			linksplit(char ***s, char **str, int i, int l)
{
	while (str[i] != NULL)
	{
		s[l] = ft_strsplit(str[i], '-');
		l++;
		i++;
	}
}

char                ***triple_split(char **str)
{
	char			***s;
	int				i;
	int				l;

	l = ft_len2(str);
	i = 0;
	if (!(s = (char ***)malloc(sizeof(char **) * (l + 1))))
		return (NULL);
	while (--l >= 0)
		s[l] = NULL;
	l = 0;
	while (str[i] && str[i][ft_strlenc(str[i], '-')] == '\0')
	{
		while ((str[i][0] == '#' && str[i][1] != '#') || !cmp(str, i))
			i++;
		if (ft_strlenc(str[i], '-') == ft_strlen(str[i]))
		{
			s[l] = ft_strsplit(str[i], ' ');
			l++;
			i++;
		}
	}
	linksplit(s, str, i, l);
	ft_arraydel(str);
	return (s);
}