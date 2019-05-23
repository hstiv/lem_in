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
	int					ants;
	int					rooms;
	struct s_lem		*begin;
	struct s_lem		*end;
}						t_lem;

typedef struct			s_room
{
	int					*w;
	int					room_cnt;
	char				*name;
	int					ant;
	int					x;
	int					y;
	struct s_room		**bridge;
	struct s_room		*next;
}						t_room;

int						deep_rec(t_lem *lem, char **s);
char					**ft_rec(char *s, t_lem *lem);
t_lem                   *ft_newlem();
t_room					*ft_newroom();
#endif
