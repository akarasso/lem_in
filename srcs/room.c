/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:30:20 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/17 20:00:28 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

t_room		*new_room(char *name, int x, int y)
{
	t_room	*new;

	new = 0;
	if (!name)
		return (0);
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (0);
	if (!(new->name = ft_strdup(name)))
	{
		free(new);
		return (0);
	}
	new->x = x;
	new->y = y;
	new->d = -1;
	new->valid = 1;
	new->occuped = 0;
	new->next = 0;
	new->link = 0;
	new->passed = 0;
	return (new);
}

t_room		*push_room(t_room **lst, char *name, int x, int y)
{
	t_room *room;

	if (*lst)
	{
		room = *lst;
		while (room->next)
		{
			if (!(ft_strcmp(name, room->name)))
				return (0);
			room = room->next;
		}
		if (!ft_strcmp(name, room->name))
			return (0);
		if (!(room->next = new_room(name, x, y)))
			return (0);
		return (room->next);
	}
	else
	{
		*lst = new_room(name, x, y);
		return (*lst);
	}
}

t_room		*find_room(t_room **start, char *name)
{
	t_room *lst;

	lst = *start;
	while (lst)
	{
		if (!ft_strcmp(name, lst->name))
			return (lst);
		lst = lst->next;
	}
	return (0);
}
