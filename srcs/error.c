/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:47:09 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/17 19:52:46 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	clear_link(t_room *room)
{
	int i;

	i = 0;
	if (room->link)
	{
		while (room->link[i])
			free(room->link[i++]);
		free(room->link[i]);
		free(room->link);
	}
}

void	clear_room(t_room *room)
{
	t_room *r;

	while (room)
	{
		r = room->next;
		if (room->name)
			free(room->name);
		clear_link(room);
		free(room);
		room = r;
	}
}

int		ant_clear(t_ant *ant)
{
	t_ant *n;

	while (ant)
	{
		n = ant->next;
		free(ant);
		ant = n;
	}
	return (1);
}

int		lem_clear(t_lem *lem)
{
	clear_room(lem->room);
	return (1);
}
