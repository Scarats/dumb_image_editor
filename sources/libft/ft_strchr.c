/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:30:16 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 15:52:28 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tf;
	int		i;

	i = 0;
	tf = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == tf)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == tf)
		return ((char *)&s[i]);
	return (NULL);
}

/*int main()
{
	char *s = "Hello";
	char c = '0';
	char b = *ft_strchr(s, c);
	printf("%c\n", b);
	return (0);
}*/