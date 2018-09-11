/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:25:00 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/17 20:25:49 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

int		is_cmd(char *line)
{
	if (*line && *(line + 1) && *line == '#'
		&& *(line + 1) == '#' && *(line + 2) != '#')
	{
		return (1);
	}
	return (0);
}

int		parse_cmd(t_lem *lem, char *line)
{
	if (!ft_strcmp(line, "##start") && lem->inst_start)
		return (0);
	if (!ft_strcmp(line, "##end") && lem->inst_stop)
		return (0);
	if (!ft_strcmp(line, "##start"))
		lem->inst_start = 1;
	if (!ft_strcmp(line, "##end"))
		lem->inst_stop = 1;
	return (1);
}
