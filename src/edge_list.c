 #include "lem_in.h"

 static void			if_start(t_lem *lem, char ***s, int *i, int *l)
 {
	t_room				*adj;

	adj = lem->adj[*l];
	*(i)++;
	adj->x = ft_atoi(s[*i][1]);
	adj->y = ft_atoi(s[*i][2]);
	adj->name = ft_strdup(s[*i][0]);
	lem->begin = adj;
	adj->nb = *l;
	*(i)++;
	*(l)++;
 }

 static void			if_end(t_lem *lem, char ***s, int *i, int *l)
 {
	t_room				*adj;

	adj = lem->adj[*l];
	*(i)++;
	adj->x = ft_atoi(s[*i][1]);
	adj->y = ft_atoi(s[*i][2]);
	adj->name = ft_strdup(s[*i][0]);
	lem->end = adj;
	adj->nb = *l;
	*(i)++;
	*(l)++;
 }

 static void			if_common(t_lem *lem, char ***s, int *i, int *l)
 {
	t_room				*adj;

	adj = lem->adj[*l];
	adj->x = ft_atoi(s[*i][1]);
	adj->y = ft_atoi(s[*i][2]);
	adj->name = ft_strdup(s[*i][0]);
	adj->nb = *l;
	*(i)++;
	*(l)++;
 }

 int					adj_list(t_lem *lem, char ***s)
 {
	t_room				**adj;
	int 				l;
	int 				i;

	l = lem->rooms_cnt;
	if (!(adj = (t_room**)malloc(sizeof(t_room*) * (lem->rooms_cnt + 1))))
		return (0);
	lem->adj = adj;
	i = 1;
	while (ft_len2(s[i]) != 2)
	{
		if (s[i][0][0] == '#' && s[i][0][2] == 's')
			if_start(lem, s, &i, &l);
		else if (s[i][0][0] == '#' && s[i][0][2] == 'e')
			if_end(lem, s, &i, &l);
		else
			if_common(lem, s, &i, &l);
	}
	return (link_make(lem, s, i));
 }
