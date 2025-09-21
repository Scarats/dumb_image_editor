/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:31:01 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 15:31:02 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s);
	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, size + 1);
	return (ptr);
}

/*int main(void)
{
	const char *original = "Hello, world!";
	char *duplicate;

	duplicate = ft_strdup(original);

	if (duplicate == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	printf("Original: %s\n", original);
	printf("Duplicate: %s\n", duplicate);

	// Libérer la mémoire allouée
	free(duplicate);

	return (0);
}*/