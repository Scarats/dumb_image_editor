/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:27:26 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/11 16:00:19 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	router(char c, va_list list)
{
	int		i;
	size_t	y;

	i = 0;
	y = 0;
	if (c == 'c')
		i = type_c((char)va_arg(list, int));
	else if (c == 's')
		i = type_s(va_arg(list, char *));
	else if (c == 'i' || c == 'd')
		i = type_i(va_arg(list, int));
	else if (c == 'p')
		i = type_p(va_arg(list, void *));
	else if (c == 'x' || c == 'X')
		i = type_xx(va_arg(list, unsigned int), c);
	else if (c == 'u')
		i = type_u(va_arg(list, unsigned int));
	return (i + y);
}

int	loop(char *str, va_list list)
{
	size_t	i;
	size_t	y;
	size_t	nb;

	i = 0;
	y = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				y += write(1, "%", 1);
			else
				y += router(str[i + 1], list);
			nb += 2;
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	i += y - nb;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	list;

	i = 0;
	va_start(list, str);
	i = loop((char *)str, list);
	va_end(list);
	return (i);
}
/*
#include <stdio.h> // Inclure stdio.h pour utiliser printf

int	main(void)
{
	char			c;
	char			*s;
	int				y;
	char			*lol;
	unsigned int	a;
	int				i = ft_printf("Ceci est un test n%i:
							%c%s\n\nLe pointeur c est a l'adresse suivante :
							%%%%%p\nTest x et X : \nx = %x\nX;
	int				test2;
	int				test3;

	c = 'c';
	s = "oucou";
	y = 1231869327;
	lol = &c;
	a = 3000000000;
	i = ft_printf("Ceci est un test n%i:
			%c%s\n\nLe pointeur c est a l'adresse suivante :
			%%%%%p\nTest x et X : \nx = %x\nX = %X\n\n", y, c, s, lol, a, a);
	test2 = ft_printf("%%");
	test3 = printf("%%");
	printf("test2 = %i\n test3 = %i", test2, test3);
	printf("\nCounter: %d words", i);
	return (0);
}
*/