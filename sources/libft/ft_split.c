/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:46:48 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/29 23:47:40 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	i;
	int	inword;

	i = 0;
	inword = 0;
	while (*s)
	{
		if (*s != c && !inword)
		{
			inword = 1;
			i++;
		}
		else if (*s == c)
			inword = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	length;
	size_t	i;
	char	**ptr;

	i = 0;
	ptr = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!ptr || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				length = ft_strlen(s);
			else
				length = ft_strchr(s, c) - s;
			ptr[i++] = ft_substr(s, 0, length);
			s += length;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
