#include "vizulib.h"

static void			cor_give(t_room **adj)
{
	int				i;
	int				t;

	t = 5;
	i = 0;
	while (adj[i])
	{
		adj[i]->cor = t;
		t += 15;
		i++;
	}
}

static int			adj(t_lem *lem, char **av, int ac)
{
	char		***s;

	if (ac != 2 || !(s = ft_rec(av[1], lem)))
	{
		free(lem);
		return (ft_err("Error\n"));
	}
	if (!adj_list(lem, s))
	{
		free(lem);
		ft_triplefree(s);
		return (ft_err("Error\n"));
	}
	ft_triplefree(s);
	return (1);
}

int					main(int c, char **s)
{
	t_lem		*lem;
	t_mlx		*mlx;

	lem = ft_newlem();
	mlx = ft_newmlx();
	mlx->lem = lem;
	if (!adj(lem, s, c) || !lem->begin || !lem->end)
		return (0);
	cor_give(lem->adj);
	run_window(mlx);
	free_lem(lem);
	free(mlx);
	return (0);
}
