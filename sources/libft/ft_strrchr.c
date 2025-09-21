/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:50:21 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 15:58:59 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tf;
	int		i;

	i = ft_strlen(s);
	tf = (char)c;
	while (i >= 0)
	{
		if (s[i] == tf)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*int main()
{
	char *s = "Hello";
	char c = 0;
	char b = *ft_strchr(s, c);
	printf("%c\n", b);
	return (0);
}*/