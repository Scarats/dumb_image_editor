/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:36:10 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/11 15:10:36 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_i(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		type_s("-2147483648");
		return (11);
	}
	else if (nb < 0)
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
