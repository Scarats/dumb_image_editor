/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:44:44 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 14:08:48 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;
	size_t	total;

	total = count * size;
	if (size != 0 && total / size != count)
		return (NULL);
	pt = malloc(total);
	if (pt == NULL)
		return (NULL);
	ft_memset(pt, 0, total);
	return (pt);
}
/*
int	main(void)
{
	size_t count = 5;
	size_t size = sizeof(int);
	int *array;

	array = (int *)ft_calloc(count, size);
	if (array == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	// Print the allocated memory content
	for (size_t i = 0; i < count; i++)
	{
		printf("array[%zu] = %d\n", i, array[i]);
	}

	// Free the allocated memory
	free(array);

	return (0);
}*/