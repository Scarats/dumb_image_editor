/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:46:09 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 15:39:00 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	y;
	size_t	dstsize;
	size_t	srcsize;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	y = 0;
	if (size <= dstsize)
		return (size + srcsize);
	while (y < size - dstsize - 1 && src[y] != '\0')
	{
		dst[dstsize + y] = src[y];
		y++;
	}
	dst[dstsize + y] = '\0';
	return (dstsize + srcsize);
}
/*int	main(void)
{
	char a[] = "je m'appelle keke";
	char b[] = " et je suis g";
	b[0] = '\0';
	unsigned int size = 5;
	int bite = ft_strlcat(a, b, size);
	printf("%s", a);
	printf("%d", bite);
	return (0);
}*/