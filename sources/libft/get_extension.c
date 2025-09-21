/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:52:54 by tcardair          #+#    #+#             */
/*   Updated: 2025/05/28 17:17:19 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_extension(const char *source, const char *target)
{
	char	*dot;

	if (!source || !target)
		return (NULL);
	dot = ft_strrchr(source, '.');
	if (!dot)
		return (NULL);
	if (ft_strncmp(dot, target, ft_strlen(target)) == 0)
		return (dot);
	return (NULL);
}
