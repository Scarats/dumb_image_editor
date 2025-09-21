/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:29:06 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 15:29:08 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		tf;
	size_t				i;
	const unsigned char	*ps;

	ps = (const unsigned char *)s;
	tf = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ps[i] == tf)
			return ((void *)&ps[i]);
		i++;
	}
	return (NULL);
}
/*int main()
{
	const char *s = "Hello";
	char c = 'e';
	char *b = ft_memchr(s, c, 5);
	if (b != NULL)
		printf("%c\n", *b);
	else
		printf("Character not found\n");
	return (0);
}*/
