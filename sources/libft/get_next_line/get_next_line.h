/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:27:45 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/25 19:32:52 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
size_t	ft_gn_strlen(char *s);
char	*ft_gn_strdup(char *s1);
char	*ft_gn_strjoin(char *s1, char *s2);
char	*ft_gn_strstr(char *str, char *tofind);
size_t	ft_gn_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_gn_substr(char *s, unsigned int start, size_t len);

#endif