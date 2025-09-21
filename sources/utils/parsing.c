/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:50:02 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:10:11 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_size(t_data *data)
{
	char	*line;
	t_list	*temp;

	ft_printf("get_size\n");
	data->arr_size = 0;
	data->fd = open(data->file_name, O_RDONLY);
	if (data->fd < 0)
	{
		data->error = 4;
		return ;
	}
	line = get_next_line(data->fd);
	while (line != NULL)
	{
		data->arr_size++;
		temp = ft_lstnew(line);
		ft_lstadd_back(&(data->temp_list), temp);
		line = get_next_line(data->fd);
	}
	if (line)
		free(line);
	close(data->fd);
}

void	parser_rest(t_data *data, int i)
{
	ft_printf("%s\n", data->file_name);
	while (i < data->arr_size)
	{
		data->arr3d[i] = get_next_line(data->fd);
		i++;
	}
	data->arr3d[i] = get_next_line(data->fd);
	close(data->fd);
}

void	parser(t_data *data)
{
	int	i;

	ft_printf("parser\n");
	i = 0;
	if (data->f_type == 1)
	{
		get_size(data);
		my_free(&(data->temp_list));
		data->arr3d = my_malloc(&(data->list), sizeof(char *) * (data->arr_size
					+ 1));
		if (!data->arr3d)
		{
			data->error = 5;
			return ;
		}
		data->fd = open(data->file_name, O_RDONLY);
		if (data->fd < 0)
		{
			data->error = 4;
			return ;
		}
		parser_rest(data, i);
	}
	else if (data->f_type == -1)
		import(data);
}

void	check_input(int ac, char **av, t_data *data)
{
	ft_printf("Check_input\n");
	if (ac > 2)
		data->error = 2;
	else if (ac == 1)
		data->f_type = 0;
	else if (get_extension(av[1], ".fdf"))
	{
		data->f_type = 1;
		data->file_name = av[1];
		parser(data);
	}
	else if (get_extension(av[1], ".dumb"))
	{
		ft_printf(".dumb\n");
		data->file_name = av[1];
		data->f_type = -1;
		parser(data);
	}
	else
		data->error = 3;
}
