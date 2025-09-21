/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:32:40 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 13:59:24 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*
#include <stdlib.h>
#include <stdio.h> // Inclure pour printf
#include <string.h> // Inclure pour memcpy

int main() {
    size_t n = 12; // Taille de la mémoire à initialiser
    unsigned char *s = malloc(n); // Allouer de la mémoire pour s
    if (s == NULL) {
        perror("Échec de l'allocation de mémoire");
        return 1; // Vérifier si l'allocation a échoué
    }

    // Remplir s avec un texte
    const char *text = "Hello, World!";
    memcpy(s, text, n); // Copier le texte dans s

    // Afficher le contenu de la mémoire avant d'appeler bzero
    printf("Contenu de s avant ft_bzero : ");
    for (size_t i = 0; i < n; i++) {
        printf("%c", s[i]); // Afficher chaque caractère
    }
    printf("\n");

    // Initialiser la mémoire à zéro
    printf("Initialisation de la mémoire à zéro...\n");
    ft_bzero(s, n);

    // Afficher le contenu de la mémoire après l'appel à bzero
    printf("Contenu de s après ft_bzero : ");
    for (size_t i = 0; i < n; i++) {
        printf("%c", s[i]); // Afficher chaque caractère
    }
    printf("\n");

    free(s); // Libérer la mémoire allouée
    return 0;
}
*/