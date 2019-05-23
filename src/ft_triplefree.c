#include "lem_in.h"

void				ft_triplefree(char ***s)
{
	int				i;

	i = 0;
	while (s[i] != NULL)
		i++;
	i -= 1;
	while (i >= 0)
	{
		ft_arraydel(s[i]);
		i--;
	}
	free(s);
	s = NULL;
}