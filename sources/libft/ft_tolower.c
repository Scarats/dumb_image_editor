/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:50:02 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 13:59:13 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

int	ft_tolower(int c)
{
	if (c <= 90 && c >= 65)
		c += 32;
	return (c);
}

/*int main()
{
	char c = 'A';
	c = ft_toupper(c);
	printf("%c", c);
	return (0);
}*/