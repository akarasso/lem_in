/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:13:29 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 07:55:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

int		identify_line(char *line)
{
	if (str_digit(line))
		return (ANT);
	if (!ft_strcmp(line, ""))
		return (EOF);
	if (is_cmd(line))
		return (CMD);
	if (!ft_strncmp("#", line, 1))
		return (COM);
	if (ft_strchr(line, '-'))
		return (PIPE);
	return (ROOM);
}

int		parse_line(t_lem *lem, char *line)
{
	int type;

	type = identify_line(line);
	if ((lem->ant < 0 && type != COM && type != ANT && type != CMD)
		|| (lem->ant > -1 && type == ANT))
		return (0);
	if (type == EOF)
		return (-1);
	else if ((type == ROOM && lem->ant == -1)
		|| (type == ROOM && lem->nb_link != 0)
		|| (type == ROOM && !parse_room(lem, line)))
		return (0);
	else if (type == ANT && !parse_ant(lem, line))
		return (0);
	else if (type == CMD && !parse_cmd(lem, line))
		return (0);
	else if (type == COM && !parse_com(lem, line))
		return (0);
	else if (type == PIPE && !parse_pipe(lem, line))
		return (0);
	return (1);
}

int		check_parse(t_lem *lem)
{
	if (!lem->start || !lem->stop)
		return (0);
	return (1);
}

int		read_to_end(void)
{
	char	*line;

	line = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	write(1, "\n", 1);
	return (0);
}

int		parse(t_lem *lem)
{
	char	*line;
	int		ret;

	line = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		if (!(ret = parse_line(lem, line))
			|| lem->nb_link > 3000 || lem->nb_room > 3000)
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!ret || lem->nb_link > 3000
		|| lem->nb_room > 3000 || !(check_parse(lem)))
	{
		return (read_to_end());
	}
	return (ret);
}
