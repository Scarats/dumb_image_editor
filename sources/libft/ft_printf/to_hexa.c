/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:30:26 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/11 16:10:19 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	to_hexa(unsigned long long addr)
{
	unsigned long long	count;

	count = 0;
	if (addr >= 16)
	{
		count += to_hexa(addr / 16);
	}
	type_c(HEXA[addr % 16]);
	count += 1;
	return (count);
}
