/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:39:59 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/29 19:12:14 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	backway(char const *s1, char const *set)
{
	int	i;
	int	y;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		y = 0;
		while (set[y] != '\0' && set[y] != s1[i])
			y++;
		if (set[y] == s1[i])
			i--;
		else
			break ;
	}
	return (ft_strlen(s1) - 1 - i);
}

int	righway(char const *s1, char const *set)
{
	int	i;
	int	y;

	i = 0;
	while (s1[i] != '\0')
	{
		y = 0;
		while (set[y] != '\0' && set[y] != s1[i])
			y++;
		if (set[y] == s1[i])
			i++;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	r;
	size_t	len;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	l = righway(s1, set);
	r = backway(s1, set);
	if (l + r > len)
		return (ft_strdup(""));
	else
		len = len - (l + r);
	s2 = (char *)malloc((sizeof(char)) * (len + 1));
	if (!s2)
		return (NULL);
	ft_memmove(s2, &s1[l], len);
	s2[len] = '\0';
	return (s2);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *result;
	char *expected;

	// Test 1
	result = ft_strtrim("   ", " ");
	expected = " ";
	printf("Test 1: Output: '%s', Expected: '%s'\n", result, expected);
	free(result);

	// Test 2
	result = ft_strtrim("xxHello World!xx", "x");
	expected = "Hello World!";
	printf("Test 2: Output: '%s', Expected: '%s'\n", result, expected);
	free(result);

	// Test 3
	result = ft_strtrim("abcHello World!cba", "abc");
	expected = "Hello World!";
	printf("Test 3: Output: '%s', Expected: '%s'\n", result, expected);
	free(result);

	// Test 4
	result = ft_strtrim("Hello World!", "");
	expected = "Hello World!";
	printf("Test 4: Output: '%s', Expected: '%s'\n", result, expected);
	free(result);

	// Test 5
	result = ft_strtrim("", " ");
	expected = "";
	printf("Test 5: Output: '%s', Expected: '%s'\n", result, expected);
	free(result);

	return (0);
}*/