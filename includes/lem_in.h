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

typedef struct			s_lem
{
	char				**s;
	struct s_room		**adj;
	int					ants;//todo?
	int					rooms_cnt;
	struct s_room		*begin;
	struct s_room		*end;
	int					path_count;
	struct s_path 		**patharr;
	int					max_group_size;
}						t_lem;

typedef struct			s_room
{
	int 				nb;
	char				*name;
	int					ant;
	int					x;
	int					y;
	int 				link_count;//todo
	int 				visited;
	struct s_room		*next;
	struct s_room		*prev;
	struct s_room		*self;
	unsigned int		dijkstra;
	struct s_room		*queue_next;
}						t_room;

typedef struct s_split
{
	char		*name1;
	char		*name2;
	char		*name3;
	int			l;
	int			begin;
	int			end;
	struct s_split	*next;
	struct s_split	*prev;
	
}			t_split;

typedef struct{
	t_room	*start;
	t_room	*end;
	int size;
} t_queue;

typedef struct s_path{
	int len;
	t_room *start;
	t_room *end;
	struct s_path *next;
	char *intersection_arr;
} t_path;

typedef struct s_group {
	int size;
	int sumlen;
	t_path **path_array;
	struct s_group *next;//??maybe?
} t_group;

void					switch_links(t_path *path, t_lem *lem);
void					add_group(t_group *group_list, t_lem *lem);
t_group					*find_best_group(t_group *group_list, t_lem *lem);
void					create_solution(t_group *group);
void					split_free(t_split *split);
t_split					*ft_newsplit();
int						len_rooms(char ***s);
void					free_lem(t_lem *lem);
void					free_adj(t_room **adj);
int						adj_list(t_lem *lem, t_split *split);
t_split					*ft_rec(char *s, t_lem *lem);
int 					link_make(t_lem *lem, t_split *tmp);
t_lem					*ft_newlem();
t_room					*ft_newroom();
int 					rpf(t_room *room, t_lem *lem, t_path *path, t_path **pathlist);
t_path					*create_path();
void	add_to_path(t_path *path, t_room *room);
int 	is_intersect(t_path *path1, t_path *path2);
int		is_intersecting_n_paths(t_path **path_arr, int size);
void	add_to_priority_queue(t_room *room, t_queue *queue);
t_room	*pop_from_queue(t_queue *queue);
void	add_to_queue(t_room *room, t_queue *queue);
t_path	*dijkstra_search(t_lem *lem);
void	throw_error(char *msg);
int 	min(int a, int b);
void	print_path(t_path *path);
int		calc_max_group_size(t_lem *lem);
#endif
