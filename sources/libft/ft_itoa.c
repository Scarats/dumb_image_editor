/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:31:14 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/31 18:14:46 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		nbrs;
	char	*str;
	long	num;

	num = n;
	nbrs = size(n);
	str = (char *)malloc(sizeof(char) * (nbrs + 1));
	if (!str)
		return (NULL);
	str[nbrs] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--nbrs] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	run_test(int n, const char *expected)
{
	char	*result;

	result = ft_itoa(n);
	if (strcmp(result, expected) == 0)
	{
		printf("\033[0;32m"); // Set text color to green
		printf("Test passed: ft_itoa(%d) == %s\n", n, result);
	}
	else
	{
		printf("\033[0;31m"); // Set text color to red
		printf("Test failed: ft_itoa(%d) == %s, expected %s\n", n, result,
			expected);
	}
	printf("\033[0m"); // Reset text color
	free(result);
}

int	main(void)
{
	run_test(123, "123");
	run_test(-456, "-456");
	run_test(0, "0");
	run_test(2147483647, "2147483647");
	run_test(-2147483648, "-2147483648");

	return (0);
}*/