/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:58:46 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/19 13:58:58 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>

int			g_recursdepth;

typedef struct			s_lem
{
	char				**s;
	int					n;
	int					nb;
	struct s_room		**adj;
	int					ants;
	int					rooms_cnt;
	struct s_room		*begin;
	struct s_room		*end;
	int					path_count;
	int					oper;
	struct s_path		**patharr;
	int					max_group_size;
}						t_lem;

typedef struct			s_room
{
	int					nb;
	char				*name;
	int					ant;
	int					x;
	int					y;
	int					link_count;
	int					visited;
	struct s_room		*next;
	struct s_room		*prev;
	struct s_room		*self;
	unsigned int		dijkstra;
	struct s_room		*queue_next;
}						t_room;

typedef struct			s_split
{
	char				*name1;
	char				*name2;
	char				*name3;
	int					l;
	int					begin;
	int					end;
	struct s_split		*next;
	struct s_split		*prev;

}						t_split;

typedef	struct			s_queue
{
	t_room				*start;
	t_room				*end;
	int					size;
}						t_queue;

typedef struct			s_path
{
	int					len;
	t_room				*start;
	t_room				*end;
	struct s_path		*next;
	struct s_path		*prev;
	char				*intersection_arr;
}						t_path;

typedef struct			s_group
{
	int					size;
	int					sumlen;
	int					ants;
	t_path				**path_array;
	struct s_group		*next;
}						t_group;

int						dublicates(t_split *tmp);
int						ret_null(t_split *tmp);
int						is_ants_at_finish(t_group *group);
void					make_prev_for_path(t_group *group, t_lem *lem);
t_split					*addlst(t_split *tmp, int l, int *t);
int						common_room(t_split *tmp, char **s, const int *t);
int						linker(t_split *tmp, char **s);
int						run_ants(t_group *group, t_lem *lem, int n);
void					switch_links(t_path *path, t_lem *lem);
void					add_group(t_group *group_list, t_lem *lem);
t_group					*find_best_group(t_group *group_list, t_lem *lem);
void					split_free(t_split *split);
t_split					*ft_newsplit();
void					free_lem(t_lem *lem);
void					free_adj(t_room **adj);
int						adj_list(t_lem *lem, t_split *split);
t_split					*ft_rec(char *s, t_lem *lem);
int						link_make(t_lem *lem, t_split *tmp);
t_lem					*ft_newlem();
t_room					*ft_newroom();
int						rpf(t_room *room, t_lem *lem,
						t_path *path, t_path **pathlist);
t_path					*create_path();
void					add_to_path(t_path *path, t_room *room);
int						is_intersect(t_path *path1, t_path *path2);
int						is_intersecting_n_paths(t_path **path_arr, int size);
void					add_to_priority_queue(t_room *room, t_queue *queue);
t_room					*pop_from_queue(t_queue *queue);
void					add_to_queue(t_room *room, t_queue *queue);
t_path					*dijkstra_search(t_lem *lem);
void					throw_error(char *msg);
int						min(int a, int b);
int						calc_max_group_size(t_lem *lem);
t_group					*create_group(t_path **patharr, int size);
int						check_link(t_room *src, t_room *dest);
t_path					*reverse_path(t_path *path);
void					fill_intersection_array(t_path *path, t_lem *lem);
t_group					*delete_intersecting_paths(t_group *group);
void					free_path(t_path *path);
void					free_group(t_group *group);
void					free_queue(t_queue *queue);
void					free_path_full(t_path *path);

#endif
