/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:02:06 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 03:26:31 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "libft.h"

int		parse_ant(t_lem *lem, char *line)
{
	long long ant;

	if ((ant = ft_atoll(line)) < 2147483648 && ant > 0)
	{
		lem->ant = (int)ant;
		return (1);
	}
	return (0);
}
