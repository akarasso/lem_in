/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:25:16 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 08:20:53 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

char	**split_line(char *line)
{
	char	**str;

	str = ft_strsplit(line, '-');
	if (count_str_tab(str) != 2)
	{
		free_str_tab(str);
		return (0);
	}
	return (str);
}

int		parse_pipe(t_lem *lem, char *line)
{
	t_room	*r1;
	t_room	*r2;
	char	**str;

	r1 = 0;
	r2 = 0;
	if ((str = split_line(line)))
	{
		if ((r1 = find_room(&lem->room, str[0]))
			&& (r2 = find_room(&lem->room, str[1]))
			&& create_link(r1, r2))
		{
			lem->nb_link++;
			free_str_tab(str);
			return (1);
		}
		free_str_tab(str);
		return (0);
	}
	return (0);
}
