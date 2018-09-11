/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:05:45 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 08:18:49 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# define ROOM 1
# define PIPE 2
# define COM 3
# define CMD 4
# define EOF 5
# define ANT 6
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct s_link;

typedef struct		s_room
{
	struct s_room	*next;
	struct s_link	**link;
	char			*name;
	int				x;
	int				y;
	int				d;
	int				occuped;
	int				valid;
	char			passed;
}					t_room;

typedef struct		s_lem
{
	t_room		*room;
	t_room		*start;
	t_room		*stop;
	int			ant;
	int			arrived;
	int			nb_link;
	int			nb_room;
	char		inst_start;
	char		inst_stop;
}					t_lem;

typedef struct		s_link
{
	t_room	*to;
	int		weight;
}					t_link;

typedef struct		s_ant
{
	struct s_ant	*next;
	t_room			*room;
	int				id;
	int				arrived;
}					t_ant;

t_room				*push_room(t_room **lst, char *name, int x, int y);
t_room				*find_room(t_room **lst, char *name);
long long			ft_atoll(char *s);
int					parse(t_lem *lem);
int					parse_cmd(t_lem *lem, char *s);
int					parse_com(t_lem *lem, char *line);
int					parse_pipe(t_lem *lem, char *line);
int					parse_room(t_lem *lem, char *line);
int					parse_ant(t_lem *lem, char *line);
int					count_str_tab(char **s);
int					create_link(t_room *r1, t_room *r2);
int					check_unvalid_room(t_lem *lem);
int					str_digit(char *s);
int					create_ants(t_lem *lem, t_ant **queue, int n);
int					count_link(t_room *room);
int					solve(t_lem *lem);
int					free_str_tab(char **s);
int					lem_clear(t_lem *lem);
int					ant_clear(t_ant *ant);
int					is_cmd(char *line);
void				lem_error(t_lem *lem);
void				print_ant_pos(t_ant *ant);
void				init_solve(t_room *room, int distance);
void				order_by_distance(t_room *room);

#endif
