/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pen_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:31 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 15:43:53 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 1 && (data->pen_mode_state == 1 || data->eraser_mode == 1)
		&& data->pen_img != NULL)
	{
		data->mouse_pressed = 1;
		if (!data->drawing_line)
		{
			data->x1 = x;
			data->y1 = y;
			data->drawing_line = 1;
		}
		else
		{
			data->curr_img_addr = data->pen_img_addr;
			draw_line(data, x, y);
			data->curr_img_addr = NULL;
			data->drawing_line = 0;
			data->x1 = -1;
			data->y1 = -1;
		}
		draw(x, y, data, data->pen_img_addr);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	if (button == 1 && (data->pen_mode_state == 1 || data->eraser_mode == 1))
	{
		data->mouse_pressed = 0;
		if (!data->drawing_line)
		{
			data->x1 = -1;
			data->y1 = -1;
		}
	}
	x = y;
	y = x;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	if (data->mouse_pressed && (data->pen_mode_state == 1
			|| data->eraser_mode == 1))
	{
		data->is_first_click = 0;
		data->drawing_line = 0;
		data->x1 = -1;
		data->y1 = -1;
		draw(x, y, data, data->pen_img_addr);
	}
	return (0);
}

int	pen_mode(t_data *data)
{
	if (data->pen_mode_state == 0 && data->pen_img_addr == NULL
		&& data->eraser_mode == 0)
	{
		ft_printf("Init pen mode\n");
		data->pen_mode_state = 1;
		data->pen_img = mlx_new_image(data->mlx, data->win_width,
				data->win_height);
		data->pen_img_addr = mlx_get_data_addr(data->pen_img,
				&data->bits_per_pixel, &data->line_length, &data->endian);
	}
	else if (data->pen_mode_state == 0 && data->eraser_mode == 0)
		data->pen_mode_state = 1;
	else if (data->pen_mode_state == 1)
		data->pen_mode_state = 0;
	return (0);
}

void	pen_init(t_data *data)
{
	data->mouse_pressed = 0;
	data->eraser_mode = 0;
	data->is_first_click = 0;
	data->drawing_line = 0;
	data->x1 = -1;
	data->y1 = -1;
	data->pen_mode_state = 0;
}
