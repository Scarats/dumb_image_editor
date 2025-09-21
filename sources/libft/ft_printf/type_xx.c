/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:56:29 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/11 16:12:38 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	swap(char *ptr, int i)
{
	int		y;
	char	temp;

	y = 0;
	while (y < i / 2)
	{
		temp = ptr[y];
		ptr[y] = ptr[i - y - 1];
		ptr[i - y - 1] = temp;
		y++;
	}
}

unsigned int	to_hexa_ptr(unsigned int nb, char *ptr)
{
	int		i;

	i = 0;
	if (nb == 0)
		ptr[i++] = '0';
	else
	{
		while (nb > 0)
		{
			ptr[i++] = HEXA_MAJ[nb % 16];
			nb /= 16;
		}
	}
	ptr[i] = '\0';
	swap(ptr, i);
	return (i);
}

int	type_xx(unsigned int nb, char c)
{
	int		i;
	int		y;
	char	*ptr;

	ptr = malloc(9 * (sizeof(char)));
	if (!ptr)
		return (-1);
	i = to_hexa_ptr(nb, ptr);
	if (c == 'x')
	{
		y = 0;
		while (ptr[y] != '\0')
		{
			if (ptr[y] <= 90 && ptr[y] >= 65)
				ptr[y] += 32;
			y++;
		}
	}
	type_s(ptr);
	free(ptr);
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned int i = 3000000000;
	char c = 'x';
	int y = type_xX(i, c);
	printf("\n%d, %X", y, i);
	return (0);
}*/