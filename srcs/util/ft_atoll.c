/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:13:30 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/18 03:56:25 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

long long	ft_atoll(char *str)
{
	long long	res;
	int			neg;

	res = 0;
	neg = 1;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str > 47 && *str < 58 && res < 21474836480 && res > -21474836480)
	{
		res = res * 10 + (long long)*str - 48;
		str++;
	}
	return (res * neg);
}
