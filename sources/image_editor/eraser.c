/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eraser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:20 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 15:49:44 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Add null pixels in a large square of like 5px
// it has to put it in the import and the drawing
#include "../fdf.h"

int	eraser(int x, int y, t_data *data, char *img_addr)
{
	int	width;
	int	height;

	width = 10;
	height = 10;
	while (width >= 0)
	{
		while (height >= 0)
		{
			data->curr_color = 0;
			my_mlx_pixel_put(data, x - width, y - height, img_addr);
			height--;
		}
		width--;
		height = 10;
	}
	return (0);
}

void	change_eraser_state(t_data *data)
{
	if (data->eraser_mode == 0)
	{
		ft_printf("Eraser on\n");
		data->eraser_mode = 1;
		data->backup_color = data->pen_color;
		data->pen_color = EMPTY;
		data->backup_state = data->pen_mode_state;
		data->pen_mode_state = 0;
	}
	else if (data->eraser_mode == 1)
	{
		ft_printf("Eraser off\n");
		data->eraser_mode = 0;
		data->pen_color = data->backup_color;
		data->pen_mode_state = data->backup_state;
	}
}
