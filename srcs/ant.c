/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:31:01 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/17 15:28:10 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

void	print_ant_pos(t_ant *ant)
{
	write(1, "L", 1);
	ft_putnbr(ant->id);
	write(1, "-", 1);
	ft_putstr(ant->room->name);
}

t_ant	*new_queue(t_room *room, int n)
{
	t_ant	*new;

	if (!(new = (t_ant *)malloc(sizeof(t_ant))))
		return (NULL);
	new->room = room;
	new->id = n;
	new->arrived = 0;
	new->next = 0;
	return (new);
}

t_ant	*push_back_queue(t_ant **queue, t_room *room, int n)
{
	t_ant *q;

	q = *queue;
	if (q)
	{
		while (q->next)
			q = q->next;
		q->next = new_queue(room, n);
		q->next->room->occuped++;
		return (q->next);
	}
	else
	{
		*queue = new_queue(room, n);
		(*queue)->room->occuped++;
		return (*queue);
	}
}

int		create_ants(t_lem *lem, t_ant **queue, int n)
{
	int i;

	i = 1;
	while (i <= n)
		push_back_queue(queue, lem->start, i++);
	return (1);
}
