/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:25:25 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 07:48:52 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

int		exec_cmd(t_lem *lem, t_room *room)
{
	if (lem->inst_start && !lem->start)
		lem->start = room;
	if (lem->inst_stop && !lem->stop)
		lem->stop = room;
	if (lem->stop && lem->start
		&& !ft_strcmp(lem->start->name, lem->stop->name))
		return (0);
	return (1);
}

int		str_isdigit(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '-')
			return (0);
		s++;
	}
	return (1);
}

int		count_char(char *s, char c)
{
	int n;

	n = 0;
	while (*s)
	{
		if (*s == c)
			n++;
		s++;
	}
	return (n);
}

int		parse_room(t_lem *lem, char *line)
{
	t_room	*e;
	char	**str;

	str = 0;
	if (*line == 'L' || *line == '#' || count_char(line, ' ') != 2
		|| !(str = ft_strsplit(line, ' ')))
		return (0);
	if (count_str_tab(str) != 3
		|| !str_isdigit(str[1]) || !str_isdigit(str[2]))
	{
		free_str_tab(str);
		return (0);
	}
	if (!(e = push_room(&lem->room, str[0], ft_atoi(str[1]), ft_atoi(str[2])))
		&& free_str_tab(str))
		return (0);
	if (!(exec_cmd(lem, e)) && free_str_tab(str))
		return (0);
	free_str_tab(str);
	lem->nb_room++;
	return (1);
}
