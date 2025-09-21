/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dto2D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:50 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 11:12:18 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	to_iso(t_data *data, int x, int y)
{
	data->arr2d[x][y].x = (x * 2 + y * 2) / sqrt(2);
	data->arr2d[x][y].y = (x * 2 - y * 2) / sqrt(6) - data->arr2d[x][y].z * 2;
	if (data->arr2d[x][y].x > data->x_max)
		data->x_max = data->arr2d[x][y].x;
	if (data->arr2d[x][y].x < data->x_min)
		data->x_min = data->arr2d[x][y].x;
	if (data->arr2d[x][y].y > data->y_max)
		data->y_max = data->arr2d[x][y].y;
	if (data->arr2d[x][y].y < data->y_min)
		data->y_min = data->arr2d[x][y].y;
}

int	get_arr_width(t_data *data)
{
	int	i;
	int	arr_width;

	ft_printf("Get arr_width\n");
	if (!data || !data->arr3d || !data->arr3d[0])
		return (0);
	i = 0;
	arr_width = 0;
	while (data->arr3d[0][i])
	{
		while (data->arr3d[0][i] && data->arr3d[0][i] == ' ')
			i++;
		if (data->arr3d[0][i] && data->arr3d[0][i] != '\n')
		{
			arr_width++;
			while (data->arr3d[0][i] && data->arr3d[0][i] != ' '
				&& data->arr3d[0][i] != '\n')
				i++;
		}
		else if (data->arr3d[0][i])
			i++;
	}
	return (arr_width);
}

// Fill the list of points with the current value.
int	fill_list(t_data *data, char *buff, int i)
{
	int	y;

	data->arr2d[i][data->arr_width].z = ft_atoi(buff);
	if (data->arr2d[i][data->arr_width].z < data->z_min)
		data->z_min = data->arr2d[i][data->arr_width].z * -1;
	data->arr2d[i][data->arr_width].color = WHITE;
	data->arr2d[i][data->arr_width].x = 0;
	data->arr2d[i][data->arr_width].y = 0;
	y = 0;
	while ((buff[y] && ft_isdigit(buff[y])) || (y == 0 && buff[y] == '-'))
		y++;
	if (buff[y] == ',')
	{
		y++;
		data->arr2d[i][data->arr_width].color = ft_atoi(&buff[y]);
		while (buff[y] && buff[y] != ' ' && buff[y] != '\n')
			y++;
	}
	to_iso(data, i, data->arr_width);
	data->arr_width++;
	return (y);
}

void	parse_arr_rest(t_data *data, int temp)
{
	data->arr_width = temp;
	calculate_scale_factor(data);
	calculate_offsets(data);
	apply_transformations(data);
	ft_printf("arr size = %i\n", data->arr_size);
}

void	parse_arr(t_data *data)
{
	int	i;
	int	y;
	int	temp;

	ft_printf("Parser array\n");
	i = 0;
	y = 0;
	temp = get_arr_width(data);
	data->arr2d = my_malloc(&(data->list), sizeof(t_2d *) * (data->arr_size
				+ 1));
	while (i < data->arr_size && data->arr3d[i] != NULL)
	{
		data->arr2d[i] = my_malloc(&(data->list), sizeof(t_2d) * (temp + 1));
		y = 0;
		data->arr_width = 0;
		while (data->arr_width < temp && data->arr3d[i][y])
		{
			if (data->arr3d[i][y] == ' ')
				y++;
			else
				y += fill_list(data, &data->arr3d[i][y], i);
		}
		i++;
	}
	parse_arr_rest(data, temp);
}
