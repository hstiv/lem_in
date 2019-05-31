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
# define BUFF_SIZE 9999

typedef struct			s_lem
{
	char				**s;
	struct s_room		**adj;
	int					ants;
	int					rooms_cnt;
	struct s_room		*begin;
	struct s_room		*end;
}						t_lem;

typedef struct			s_room
{
	int 				nb;
	char				*name;
	int					ant;
	int					x;
	int					y;
	int 				link_count;
	struct s_tmp		*tmp;
}						t_room;

typedef struct			s_tmp
{
	t_room				*room;
	int					visited;
	struct s_tmp		*next;
	struct s_tmp		*prev;
}						t_tmp;

int 					link_make(t_lem *lem, char ***s, int i);
void					free_lem(t_lem *lem);
void					free_adj(t_room **adj);
int						adj_list(t_lem *lem, char ***s);
void					ft_triplefree(char ***s);
char					***ft_rec(char *s, t_lem *lem);
char					***triple_split(char **s, t_lem *lem);
int 					link_make(t_lem *lem, char ***s, int i);
t_lem					*ft_newlem();
t_room					*ft_newroom();
t_tmp					*ft_newtmp();
#endif
