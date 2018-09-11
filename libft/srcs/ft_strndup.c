/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:18:18 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/17 15:54:50 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s;

	s = (char*)malloc(sizeof(*s) * (n + 1));
	if (!s)
		return (NULL);
	s = ft_memcpy(s, s1, n);
	s[n] = 0;
	return (s);
}
