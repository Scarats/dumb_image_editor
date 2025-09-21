/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:28:46 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/26 14:23:26 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gn_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = ft_gn_strlen(to_find);
	if (length == 0)
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
		{
			j++;
		}
		if (j == length)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_gn_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gn_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (!s)
		return (ft_gn_strdup(""));
	slen = ft_gn_strlen(s);
	if (start >= slen)
		return (ft_gn_strdup(""));
	if (slen - start < len)
		len = slen - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_gn_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}

char	*ft_gn_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_gn_strlen(s1);
	len2 = ft_gn_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i = -1;
	while (++i < len2)
		str[len1 + i] = s2[i];
	str[len1 + len2] = '\0';
	return (str);
}
