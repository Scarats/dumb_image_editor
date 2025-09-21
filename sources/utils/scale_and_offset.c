/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_and_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:50:07 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:27:09 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Find the biggest and calculate the scale factor at 80% of the screen.
double	scale_calculation(int proj_hei, int win_hei, int proj_wi, int win_wi)
{
	double	height_ratio;
	double	width_ratio;

	height_ratio = (double)proj_hei / (double)win_hei;
	width_ratio = (double)proj_wi / (double)win_wi;
	printf("height ratio = %f\nwidth ratio = %f\n", height_ratio, width_ratio);
	if (height_ratio > width_ratio)
		return (height_ratio / 0.8);
	return (width_ratio / 0.8);
}

void	calculate_scale_factor(t_data *data)
{
	data->projection_height = (data->y_max - data->y_min);
	data->projection_width = (data->x_max - data->x_min);
	data->scale_factor = scale_calculation(data->projection_height,
			data->win_height, data->projection_width, data->win_width);
	ft_printf("Scale factor: %f\n", data->scale_factor);
}

void	calculate_offsets(t_data *data)
{
	double	scaled_width;
	double	scaled_height;

	scaled_width = (data->x_max - data->x_min) / data->scale_factor;
	scaled_height = (data->y_max - data->y_min) / data->scale_factor;
	data->x_offset = (data->win_width - scaled_width) / 2;
	data->y_offset = (data->win_height - scaled_height) / 2;
	if (data->x_min < 0)
		data->x_offset -= data->x_min / data->scale_factor;
	if (data->y_min < 0)
		data->y_offset -= data->y_min / data->scale_factor;
	ft_printf("Offsets - X: %f, Y: %f\n", data->x_offset, data->y_offset);
}

void	apply_transformations(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	while (i < data->arr_size)
	{
		y = 0;
		while (y < data->arr_width)
		{
			data->arr2d[i][y].x = data->arr2d[i][y].x / data->scale_factor;
			data->arr2d[i][y].y = data->arr2d[i][y].y / data->scale_factor;
			data->arr2d[i][y].x += data->x_offset;
			data->arr2d[i][y].y += data->y_offset;
			y++;
		}
		i++;
	}
}
