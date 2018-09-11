/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:12:48 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 08:18:44 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

int		count_link(t_room *room)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!room->link)
		return (0);
	while (room->link[i])
	{
		if (room->link[i]->to->valid)
			len++;
		i++;
	}
	return (len);
}

int		resize_link_tab(t_room *room, t_link *link)
{
	t_link	**new;
	int		i;
	int		len;

	i = 0;
	len = count_link(room);
	if (!(new = (t_link **)malloc(sizeof(t_link) * (len + 1))))
		return (0);
	while (i < len)
	{
		new[i] = room->link[i];
		i++;
	}
	new[i++] = link;
	new[i] = 0;
	if (room->link)
		free(room->link);
	room->link = new;
	return (1);
}

t_link	*new_link(t_room *to, int weight)
{
	t_link *link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		return (0);
	link->to = to;
	link->weight = weight;
	return (link);
}

int		create_link(t_room *r1, t_room *r2)
{
	t_link	*l1;
	t_link	*l2;

	l1 = 0;
	l2 = 0;
	if (!r1 || !r2 || !ft_strcmp(r1->name, r2->name))
		return (0);
	if ((l1 = new_link(r2, 1))
		&& (l2 = new_link(r1, 1)))
	{
		if (resize_link_tab(r1, l1) && resize_link_tab(r2, l2))
			return (1);
	}
	else
	{
		if (l1)
			free(l1);
		if (l2)
			free(l2);
		return (0);
	}
	return (0);
}
