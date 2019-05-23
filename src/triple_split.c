#include "lem_in.h"

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
		s[l] = ft_strsplit(str[i], ' ');
		l++;
		i++;
	}
	while (str[i] != NULL)
	{
		s[l] = ft_strsplit(str[i], '-');
		l++;
		i++;
	}
	ft_arraydel(str);
	return (s);
}