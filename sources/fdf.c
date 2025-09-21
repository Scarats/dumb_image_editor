/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:20:55 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:28:20 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	rendering(t_data *data)
{
	if (data->pen_img_addr != NULL)
	{
		merge_images(data, data->img_addr, data->pen_img_addr);
		mlx_put_image_to_window(data->mlx, data->win, data->curr_img, 0, 0);
		put_text(data);
		data->curr_img_addr = NULL;
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		put_text(data);
	}
}

void	gen_win(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"LOOK MOM I CAN CODE");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	main(int ac, char **av)
{
	t_data	data;

	init(&data);
	check_input(ac, av, &data);
	if (data.error > 0)
		stop_fdf(&data);
	if (!data.mlx)
		return (1);
	if (data.f_type == 1)
		parse_arr(&data);
	if (!data.win)
		gen_win(&data);
	if (!data.img_addr)
	{
		data.error = 6;
		stop_fdf(&data);
	}
	to_window(&data);
	pen_init(&data);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
