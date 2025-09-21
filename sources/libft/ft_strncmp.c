/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:47:34 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 13:54:46 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (ps1[i] != '\0' && ps2[i] != '\0' && i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	if (i < n)
		return (ps1[i] - ps2[i]);
	return (0);
}
/*int main() {
	char str1[] = "Hello";
	char str2[] = "Hello, World!";
	size_t n = 8;

	int result = strncmp(str1, str2, n);
	printf("Result of strncmp: %d\n", result);

	return (0);
}*/