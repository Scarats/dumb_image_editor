/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:50:34 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 13:50:37 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

int	ft_toupper(int c)
{
	if (c <= 122 && c >= 97)
		c -= 32;
	return (c);
}

/*int main()
{
	char c = 'a';
	c = ft_toupper(c);
	printf("%c", c);
	return (0);
}*/