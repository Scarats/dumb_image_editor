/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:58:36 by tcardair          #+#    #+#             */
/*   Updated: 2024/11/26 16:08:45 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_gn_strdup(char *s1)
{
	char	*dest;
	size_t	i;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(ft_gn_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	frite(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*read_to_remainder(int fd, char *remainder)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	if (!remainder)
		remainder = ft_gn_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_gn_strstr(remainder, "\n") && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (frite(&buffer), frite(&remainder), NULL);
		buffer[bytes_read] = '\0';
		temp = remainder;
		remainder = ft_gn_strjoin(remainder, buffer);
		frite(&temp);
	}
	return (frite(&buffer), remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];
	char		*line;
	char		*temp;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = read_to_remainder(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	if (remainder[fd][0] == '\0')
		return (frite(&remainder[fd]), NULL);
	len = 0;
	while (remainder[fd][len] && remainder[fd][len] != '\n')
		len++;
	line = ft_gn_substr(remainder[fd], 0, len + (remainder[fd][len] == '\n'));
	if (!line)
		return (NULL);
	temp = remainder[fd];
	remainder[fd] = ft_gn_strdup(remainder[fd] + len
			+ (remainder[fd][len] == '\n'));
	return (frite(&temp), line);
}
/*
int	main(void){
	char	*str;
	int		fd;

	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("line 1: %s\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("line 2: %s\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("line 3: %s\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("line 4: %s\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("line 5: %s\n\n", str);
	free(str);
	str = get_next_line(fd);
	printf("line 6: %s\n\n", str);
	free(str);
	str = get_next_line(0);
	printf("in: %s\n\n", str);
	free(str);
	str = get_next_line(-1);
	close(fd);
	return (0);
}*/