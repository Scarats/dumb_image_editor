/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:05:30 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/29 14:43:17 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*s3;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	length = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (length + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, length + 1);
	return (s3);
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
	{
		char *result;
		char *expected;

		// Test 1: Both strings are non-empty
		result = ft_strjoin("Hello, ", "World!");
		expected = "Hello, World!";
		printf("Test 1: %s\n", strcmp(result,
				expected) == 0 ? "Passed" : "Failed");
		free(result);

		// Test 2: First string is empty
		result = ft_strjoin("", "World!");
		expected = "World!";
		printf("Test 2: %s\n", strcmp(result,
				expected) == 0 ? "Passed" : "Failed");
		free(result);

		// Test 3: Second string is empty
		result = ft_strjoin("Hello, ", "");
		expected = "Hello, ";
		printf("Test 3: %s\n", strcmp(result,
				expected) == 0 ? "Passed" : "Failed");
		free(result);

		// Test 4: Both strings are empty
		result = ft_strjoin("", "");
		expected = "";
		printf("Test 4: %s\n", strcmp(result,
				expected) == 0 ? "Passed" : "Failed");
		free(result);

		// Test 5: First string is NULL
		result = ft_strjoin(NULL, "World!");
		printf("Test 5: %s\n", result == NULL ? "Passed" : "Failed");

		// Test 6: Second string is NULL
		result = ft_strjoin("Hello, ", NULL);
		printf("Test 6: %s\n", result == NULL ? "Passed" : "Failed");

		// Test 7: Both strings are NULL
		result = ft_strjoin(NULL, NULL);
		printf("Test 7: %s\n", result == NULL ? "Passed" : "Failed");

		return (0);
	}*/