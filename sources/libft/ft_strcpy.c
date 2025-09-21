/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:42:38 by tcardair          #+#    #+#             */
/*   Updated: 2025/05/20 18:09:09 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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