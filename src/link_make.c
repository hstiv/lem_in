#include "lem_in.h"

static int			ind_sch(t_lem *lem, char *s)
{
	int 			i;
	t_room			**adj;

	adj = lem->adj;
	i = 0;
	while (ft_strcmp(adj[i]->name, s) != 0)
		i++;
	return (i);
}

static void			lnk_connect(t_room **adj, int n1, int n2)
{

}

int 				link_make(t_lem *lem, char ***s, int i)
{
	t_tmp			*tmp;
	int 			n1;
	int 			n2;

	n1= 0;
	n2 = 0;
	tmp = ft_newtmp();
	while (s[i])
	{
		n1 = ind_sch(lem, s[i][0]);
		n2 = ind_sch(lem, s[i][1]);
		lnk_connect(lem->adj, n1, n2);
		i++;
	}
	return (1);
}
