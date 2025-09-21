/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:42:38 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 13:58:45 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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

/*int	main(void)
{
	char dest[50];
	unsigned int n = 20;
	char src[] = "La vie";
	int b = ft_strlcpy(dest, src, n);
	// Afficher la chaîne copiée
	printf("Dest: %s\n", dest);

	// Afficher la longueur retournée
	printf("Longueur de src: %d\n", b);
	return (0);
}*/