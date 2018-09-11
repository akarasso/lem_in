/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:17:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 08:18:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	reset_passed(t_room *r)
{
	while (r)
	{
		r->passed = 0;
		r = r->next;
	}
}

int		check_end_con(t_lem *lem, t_room *room, t_room *from)
{
	int i;

	i = 0;
	if (!room->passed)
	{
		if (count_link(room) == 1
			&& room != lem->stop && room->link[0]->to == from)
		{
			room->valid = 0;
			return (1);
		}
		room->passed = 1;
		if (room->link)
		{
			while (room->link[i])
			{
				if (room->link[i]->to->valid
					&& check_end_con(lem, room->link[i]->to, room))
					return (1);
				i++;
			}
		}
	}
	return (0);
}

void	init_solve(t_room *room, int distance)
{
	int i;

	i = 0;
	if (room && (room->d == -1 || room->d > distance))
	{
		room->d = distance;
		if (room->link)
		{
			while (room->link[i])
			{
				init_solve(room->link[i]->to, distance + 1);
				i++;
			}
		}
	}
}

void	order_by_distance(t_room *room)
{
	t_link	*tmp;
	int		i;

	while (room)
	{
		if (room->link)
		{
			i = 0;
			while (room->link[i] && room->link[i + 1])
			{
				if (room->link[i]->to->d > room->link[i + 1]->to->d)
				{
					tmp = room->link[i];
					room->link[i] = room->link[i + 1];
					room->link[i + 1] = tmp;
					i = 0;
				}
				else
					i++;
			}
		}
		room = room->next;
	}
}

int		check_unvalid_room(t_lem *lem)
{
	while (check_end_con(lem, lem->start, lem->start))
		reset_passed(lem->start);
	return (1);
}
