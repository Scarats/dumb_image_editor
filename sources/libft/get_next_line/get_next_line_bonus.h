/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:16:52 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/26 16:08:42 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

char	*get_next_line(int fd);
size_t	ft_gn_strlen(char *s);
char	*ft_gn_strdup(char *s1);
char	*ft_gn_strjoin(char *s1, char *s2);
char	*ft_gn_strstr(char *str, char *tofind);
size_t	ft_gn_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_gn_substr(char *s, unsigned int start, size_t len);

#endif