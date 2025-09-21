/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:08:05 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/11 15:11:36 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_p(void *ptr)
{
	unsigned long long	i;
	unsigned long long	addr;

	if (ptr != NULL)
		type_s("0x");
	else
	{
		type_s("(nil)");
		return (5);
	}
	addr = (unsigned long long)ptr;
	i = to_hexa(addr);
	return (i + 2);
}
/*
int	main(void)
{
	int a = 12;
	int *test = &a;
	type_p(test);
	return (0);
}*/