/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:46:18 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 13:59:22 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char str1[] = "abcdef";
	const char str2[] = "abcdeg";
	size_t n = 6;

	int result = ft_memcmp(str1, str2, n);
	int expected = memcmp(str1, str2, n);

	printf("ft_memcmp result: %d\n", result);
	printf("memcmp result: %d\n", expected);

	if (result == expected)
		printf("Test passed!\n");
	else
		printf("Test failed!\n");

	return (0);
}*/