/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:15:42 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 08:18:59 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

int		get_weight(t_room *room, int max)
{
	int i;
	int weight;

	i = 0;
	weight = 0;
	while (i <= max && room->link[i])
	{
		if (room->link[i]->to->valid)
			weight += room->link[i]->to->d;
		i++;
	}
	return (weight);
}

int		process_occuped(t_lem *lem, t_ant *ant, int i)
{
	t_room	*room;

	room = ant->room;
	while (room->link[i])
	{
		if (room->link[i]->to->valid && !room->link[i]->to->occuped
			&& get_weight(room, i) < room->occuped)
		{
			room->occuped--;
			ant->room = room->link[i]->to;
			print_ant_pos(ant);
			if (ft_strcmp(ant->room->name, lem->stop->name))
				room->link[i]->to->occuped++;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ant_arrived(t_lem *lem, t_ant *ant)
{
	if (!ant->arrived)
	{
		lem->arrived++;
		ant->arrived = 1;
	}
	return (0);
}

int		process(t_lem *lem, t_ant *ant)
{
	int		i;
	t_room	*room;

	i = 0;
	room = ant->room;
	if (ant->arrived || !ft_strcmp(room->name, lem->stop->name))
		return (ant_arrived(lem, ant));
	while (room->link[i] && !room->link[i]->to->valid)
		i++;
	if (room->link[i] && room->link[i]->to->occuped)
		return (process_occuped(lem, ant, ++i));
	if (room->link[i]->to->valid && !room->link[i]->to->occuped)
	{
		room->occuped--;
		ant->room = room->link[i]->to;
		print_ant_pos(ant);
		if (ft_strcmp(ant->room->name, lem->stop->name))
			room->link[i]->to->occuped++;
		return (1);
	}
	return (0);
}

int		solve(t_lem *lem)
{
	t_ant	*queue;
	t_ant	*curr;

	queue = 0;
	create_ants(lem, &queue, lem->ant);
	while (lem->ant != lem->arrived)
	{
		curr = queue;
		while (curr)
		{
			if (process(lem, curr))
				write(1, " ", 1);
			curr = curr->next;
		}
		if (lem->ant != lem->arrived)
			write(1, "\n", 1);
	}
	ant_clear(queue);
	return (1);
}
