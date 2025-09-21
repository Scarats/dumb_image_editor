/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:53:27 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/11 15:13:14 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_u(unsigned int nb)
{
	unsigned long	count;

	count = 0;
	if (nb < 0)
	{
		type_c('-');
		count = type_i(-nb) + 1;
	}
	else if (nb >= 10)
	{
		count = type_i(nb / 10) + 1;
		type_c(nb % 10 + '0');
	}
	else
	{
		type_c(nb + '0');
		count += 1;
	}
	return (count);
}
