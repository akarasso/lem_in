/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:05:52 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 07:54:40 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	init(t_lem *lem)
{
	lem->start = 0;
	lem->stop = 0;
	lem->room = 0;
	lem->ant = -1;
	lem->arrived = 0;
	lem->nb_link = 0;
	lem->nb_room = 0;
	lem->inst_start = 0;
	lem->inst_stop = 0;
}

int		init_resolve(t_lem *lem)
{
	init_solve(lem->stop, 0);
	if (lem->start->d == -1)
		return (0);
	check_unvalid_room(lem);
	order_by_distance(lem->room);
	return (1);
}

int		main(void)
{
	t_lem	lem;

	init(&lem);
	if (!parse(&lem) && lem_clear(&lem))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	if (!init_resolve(&lem) && lem_clear(&lem))
	{
		write(1, "\nError\n", 7);
		return (1);
	}
	write(1, "\n", 1);
	if (!solve(&lem) && lem_clear(&lem))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	lem_clear(&lem);
	return (0);
}
