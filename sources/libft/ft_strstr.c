/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:47:50 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 13:50:48 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

#include "libft.h"

char	*ft_strstr(const char *source, const char *target)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*target == '\0')
		return ((char *)source);
	while (source[i] != '\0')
	{
		j = 0;
		while (source[i + j] == target[j] && target[j] != '\0')
		{
			j++;
		}
		if (target[j] == '\0')
			return ((char *)&source[i]);
		i++;
	}
	return (NULL);
}

/*int main()
{
	const char *source = "Hello, world!";
	const char *target = "world";
	size_t len = 12;

	// Test cases
	struct {
		const char *source;
		const char *target;
		size_t len;
	} tests[] = {
		{"Hello, world!", "world", 12},
		{"Hello, world!", "world", 5},
		{"Hello, world!", "", 12},
		{"Hello, world!", "Hello", 5},
		{"Hello, world!", "world!", 12},
		{"Hello, world!", "world!", 13},
		{"Hello, world!", "!", 13},
		{"Hello, world!", "!", 12},
		{"Hello, world!", "world", 0},
		{"", "world", 5},
		{"Hello", "Hello, world!", 5},
		{"Hello", "Hello, world!", 12},
	};

	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
		char *result_ft = ft_strnstr(tests[i].source, tests[i].target,
				tests[i].len);
		char *result_str = strnstr(tests[i].source, tests[i].target,
				tests[i].len);
		printf("Test %d: ft_strnstr = %s, strnstr = %s\n", i + 1, result_ft,
			result_str);
	}

	return (0);
}*/