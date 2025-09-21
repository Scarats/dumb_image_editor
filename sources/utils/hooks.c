/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:57 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:06:40 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	loop_hook(t_data *data)
{
	rendering(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	ft_printf("keycode: %i\n", keycode);
	if (keycode == 65307)
		stop_fdf(data);
	else if (keycode == 112)
		pen_mode(data);
	else if (keycode == 101)
	{
		data->in_export = 1;
		put_text(data);
		export(data);
	}
	else if (keycode == 114 && data->eraser_mode == 0)
		data->pen_color = RED;
	else if (keycode == 103 && data->eraser_mode == 0)
		data->pen_color = GREEN;
	else if (keycode == 98 && data->eraser_mode == 0)
		data->pen_color = BLUE;
	else if (keycode == 48 && data->eraser_mode == 0)
		data->pen_color = BLACK;
	else if (keycode == 119 && data->eraser_mode == 0)
		data->pen_color = WHITE;
	else if (keycode == 100)
		change_eraser_state(data);
	return (0);
}

void	setup_hooks(t_data *data)
{
	ft_printf("setup_hooks\n");
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 4, 1L << 2, mouse_press, data);
	mlx_hook(data->win, 5, 1L << 3, mouse_release, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->win, 17, 1L << 17, stop_fdf, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
}
