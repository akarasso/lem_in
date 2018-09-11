/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 06:56:58 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 08:38:33 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static void			ft_move(char *begin, char *end)
{
	while (*end)
	{
		*begin = *end;
		end++;
		begin++;
	}
	*begin = 0;
}

static int			buff_concat(char **line, t_cbuffer *cnl, char c)
{
	char	*pos;
	char	*new;

	pos = ft_strchr(cnl->buff, c);
	if (pos)
	{
		if ((new = ft_strnew(ft_strlen(*line) + pos - cnl->buff)))
		{
			ft_strcpy(new, *line);
			ft_strncat(new, cnl->buff, pos - cnl->buff);
			ft_move(cnl->buff, pos + 1);
			ft_strdel(line);
		}
		*line = new;
		return (1);
	}
	else
	{
		new = ft_strjoin(*line, cnl->buff);
		ft_strdel(line);
		*line = new;
		ft_strclr(cnl->buff);
		return (0);
	}
}

static t_cbuffer	*get_buffer_canal(t_cbuffer *lst, const int fd)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->fd == fd)
				return (lst);
			lst = lst->next;
		}
		if (lst->fd == fd)
			return (lst);
		if (!(lst->next = (t_cbuffer*)ft_memalloc(sizeof(*lst))))
			return (0);
		lst = lst->next;
		lst->fd = fd;
	}
	else
	{
		if (!(lst = (t_cbuffer*)ft_memalloc(sizeof(*lst))))
			return (0);
		lst->fd = fd;
	}
	return (lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_cbuffer	*buffs = 0;
	t_cbuffer			*cnl;
	int					ret;
	int					len;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strnew(0);
	if ((cnl = get_buffer_canal(buffs, fd)) && !buffs)
		buffs = cnl;
	else if (!cnl || !(*line))
		return (-1);
	len = ft_strlen(cnl->buff);
	if (len > 0 && buff_concat(line, cnl, '\n'))
		return (1);
	while ((ret = read(cnl->fd, cnl->buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		if (!(cnl->buff[ret] = 0) && buff_concat(line, cnl, '\n'))
			return (1);
	}
	return (line && *line && ft_strlen(*line)) ? 1 : 0;
}
