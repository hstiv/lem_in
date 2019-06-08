/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizulib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:28:45 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/05 18:28:47 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZULIB_H
# define VIZULIB_H

# define HEIGHT 1395
# define WIDTH 2560
# define LINE 20
# define COLOR 50
# define CON 1
# define VIZU "vizu"

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

typedef struct			s_lem
{
	char				**s;
	struct s_room		**adj;
	int					ants;
	int					rooms_cnt;
	struct s_room		*begin;
	struct s_room		*end;
	int					path_count;
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
	int					cor;
	struct s_room		*next;
	struct s_room		*prev;
	struct s_room		*self;
}						t_room;

typedef	struct			s_mlx
{
	void				*wind;
	void				*ptr;
	int					x_add;
	int					y_add;
	int					radius;
	int					blue;
	int					red;
	int					green;
	int					yellow;
	int					white;
	int					err;
	int					derr;
	float				l;
	int					right_mouse;
	int					left_mouse;
	int					mv;
	int					sl;
	int					fill;
	int					x;
	int					y;
	int					cor;
	int					cmnd;
	t_lem				*lem;
}						t_mlx;

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

t_split					*ft_newsplit();
void					split_free(t_split *split);
void					putman(t_mlx *mlx);
int						key_release(int keycode, t_mlx *mlx);
void					graph_color(t_lem *lem, t_room *adj,
										t_mlx *mlx, int *col);
void					cloner(t_room *cl, t_room *adj, t_mlx *mlx);
void					visited(t_room *room, t_room *adj);
void					release_visited(t_room **adj);
void					fcircle(int x0, int y0, t_mlx *mlx, int colot);
int						mouse_release(int button, int x, int y, t_mlx *param);
int						mouse_move(int x, int y, t_mlx *param);
int						mouse_press(int button, int x, int y, t_mlx *param);
int						key_press(int keycode, t_mlx *param);
int						link_make(t_lem *lem, t_split *tmp);
void					free_lem(t_lem *lem);
void					free_adj(t_room **adj);
int						adj_list(t_lem *lem, t_split *split);
void					ft_triplefree(char ***s);
t_split					*ft_rec(char *s, t_lem *lem);
char					***triple_split(char **s, t_lem *lem);
int						link_make(t_lem *lem, t_split *tmp);
t_lem					*ft_newlem();
t_room					*ft_newroom();
void					mappaint(t_mlx *mlx);
void					circle(int x0, int y0, t_mlx *mlx, int color);
void					ft_bresenham(t_room *d0, t_room *d1, t_mlx *mlx);
void					run_window(t_mlx *mlx);
int						ft_close(void *param);
t_mlx					*ft_newmlx();

#endif
