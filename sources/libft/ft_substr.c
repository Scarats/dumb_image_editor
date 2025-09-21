/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:32:48 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/29 12:46:00 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len == 0)
		return (ft_strdup(""));
	if (slen - start > len)
		substr = (char *)malloc((sizeof(char)) * (len + 1));
	else
	{
		substr = (char *)malloc(sizeof(char) * (slen - start + 1));
		len = slen - start;
	}
	if (substr == NULL)
		return (NULL);
	ft_memmove(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(void)
{
	char *result;
	char *expected;

	// Test case 1: Normal case
	result = ft_substr("Hello, World!", 7, 5);
	expected = strndup("World!", 5);
	printf("Test 1: %s | Expected: %s\n", result, expected);
		// Expected: "World"
	free(result);
	free(expected);

	// Test case 2: Start index out of bounds
	result = ft_substr("Hello, World!", 20, 5);
	expected = NULL;
	printf("Test 2: %s | Expected: %s\n", result, expected); // Expected: NULL
	free(result);

	// Test case 3: Length is zero
	result = ft_substr("Hello, World!", 5, 0);
	expected = NULL;
	printf("Test 3: %s | Expected: %s\n", result, expected); // Expected: NULL
	free(result);

	// Test case 4: Start index is zero
	result = ft_substr("Hello, World!", 0, 5);
	expected = strndup("Hello, World!", 5);
	printf("Test 4: %s | Expected: %s\n", result, expected);
		// Expected: "Hello"
	free(result);
	free(expected);

	// Test case 5: Length exceeds string length
	result = ft_substr("Hello", 1, 10);
	expected = strndup("ello", 10);
	printf("Test 5: %s | Expected: %s\n", result, expected); // Expected: "ello"
	free(result);
	free(expected);

	// Test case 6: Empty string input
	result = ft_substr("", 0, 5);
	expected = strndup("", 5);
	printf("Test 6: %s | Expected: %s\n", result, expected); // Expected: ""
	free(result);
	free(expected);

	// Test case 7: Start index is at the end of the string
	result = ft_substr("Hello", 5, 3);
	expected = strndup("", 3);
	printf("Test 7: %s | Expected: %s\n", result, expected); // Expected: ""
	free(result);
	free(expected);

	return (0);
}*/