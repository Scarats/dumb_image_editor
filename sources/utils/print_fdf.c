/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:50:04 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:15:17 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	link_dots_rest(t_data *data, int i, int y)
{
	if (y < data->arr_width - 1)
	{
		data->x1 = data->arr2d[i][y].x;
		data->y1 = data->arr2d[i][y].y;
		draw_line(data, data->arr2d[i][y + 1].x, data->arr2d[i][y + 1].y);
	}
	if (i < data->arr_size - 1)
	{
		data->x1 = data->arr2d[i][y].x;
		data->y1 = data->arr2d[i][y].y;
		draw_line(data, data->arr2d[i + 1][y].x, data->arr2d[i + 1][y].y);
	}
}

void	link_dots(t_data *data)
{
	int	i;
	int	y;

	ft_printf("link_dots\n");
	i = 0;
	data->curr_img_addr = data->img_addr;
	while (i < data->arr_size)
	{
		y = 0;
		while (y < data->arr_width)
		{
			link_dots_rest(data, i, y);
			y++;
		}
		i++;
	}
	data->curr_img_addr = NULL;
}

void	to_window(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	ft_printf("to_window\n");
	if (!data->arr2d)
		return ;
	while (i < data->arr_size)
	{
		y = 0;
		while (y < data->arr_width)
		{
			data->curr_color = data->arr2d[i][y].color;
			my_mlx_pixel_put(data, data->arr2d[i][y].x, data->arr2d[i][y].y,
				data->img_addr);
			y++;
		}
		i++;
	}
	link_dots(data);
}
