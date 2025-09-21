/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:24:01 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/25 17:39:09 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdlib.h>

int	main(void) {
	size_t n = 12; // Taille de la mémoire à initialiser
	unsigned char *s = malloc(n); // Allouer de la mémoire pour s
	if (s == NULL) {
		perror("Échec de l'allocation de mémoire");
		return (1); // Vérifier si l'allocation a échoué
	}

	int c = '-'; // Caractère à utiliser pour memset

	// Appeler ft_memset pour remplir la mémoire avec le caractère c
	ft_memset(s, c, n);

	// Afficher le contenu de la mémoire
	printf("Contenu de s : ");
	for (size_t i = 0; i < n; i++) {
		printf("%c", s[i]); // Afficher chaque caractère
	}
	printf("\n");

	free(s); // Libérer la mémoire allouée
	return (0);
}*/
