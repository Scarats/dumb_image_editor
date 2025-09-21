/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:59 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:07:22 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	list_init(t_data *data)
{
	ft_printf("list_init\n");
	data->list = NULL;
	data->temp_list = NULL;
}

void	screen_dimentions(t_data *data)
{
	ft_printf("Initializing screen dimentions\n");
	data->win_width = 1400 / 2;
	data->win_height = 1050;
	mlx_get_screen_size(data->mlx, &data->win_width, &data->win_height);
	if (data->win_width < 200 || data->win_height < 200)
	{
		data->error = 7;
		stop_fdf(data);
	}
}

void	init_part2(t_data *data)
{
	data->win = NULL;
	data->img = NULL;
	data->curr_img = NULL;
	data->img_addr = NULL;
	data->file_name = NULL;
	data->base_name = NULL;
	data->pen_img = NULL;
	data->pen_img_addr = NULL;
	data->export_name = NULL;
	data->in_export = 0;
	data->curr_img_addr = NULL;
	data->x_min = INT_MAX;
	data->x_max = INT_MIN;
	data->y_min = INT_MAX;
	data->y_max = INT_MIN;
	data->z_min = 0;
	data->scale_factor = 1;
	data->x_offset = 0;
	data->y_offset = 0;
	data->center_x = 0;
	data->center_y = 0;
	data->error = 0;
	data->version = 0;
	data->pen_mode_state = 0;
	data->backup_state = 0;
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->arr2d = NULL;
	data->arr3d = NULL;
	data->arr_width = 0;
	data->arr_size = 0;
	data->fd = 0;
	data->f_type = 0;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->eraser_mode = 0;
	data->mouse_pressed = 0;
	data->is_first_click = 0;
	data->drawing_line = 0;
	data->backup_color = WHITE;
	data->x1 = 0;
	data->y1 = 0;
	data->projection_height = 0;
	data->projection_width = 0;
	data->color = WHITE;
	data->pen_color = WHITE;
	init_part2(data);
	screen_dimentions(data);
	list_init(data);
}
