/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:27:24 by tcardair          #+#    #+#             */
/*   Updated: 2024/10/28 13:59:02 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
include <stdio.h>*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (0);
	return (1);
}

/*int main()
{
	int c = 'a';
	int result = ft_isalpha(c);
	printf("Le résultat est : %d\n", result);
	return (0);
}*/
