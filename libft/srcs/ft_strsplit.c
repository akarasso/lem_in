/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:55:46 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/17 17:40:47 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	ft_count_word(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static int	ft_size_word(char const *s, char c)
{
	int size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static int	failed_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
	return (1);
}

static int	cpy_string(char **dest, char const *s, int size)
{
	*dest = 0;
	if (!(*dest = (char*)ft_memalloc(size + 1)))
		return (0);
	*dest = ft_strncpy(*dest, s, size);
	(*dest)[size] = '\0';
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		index;
	int		size;

	index = 0;
	ret = 0;
	if (!s || (!(ret = (char**)malloc((ft_count_word(s, c) + 1) * sizeof(*ret)))
		&& failed_split(ret)))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			size = ft_size_word(s, c);
			if (!cpy_string(&ret[index++], s, size) && failed_split(ret))
				return (0);
			s += size;
		}
		else
			s++;
	}
	ret[index] = NULL;
	return (ret);
}
