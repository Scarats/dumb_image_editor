/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:53 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 15:57:08 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:53 by tcardair          #+#    #+#             */
/*   Updated: 2025/05/28 17:53:42 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

// Put a pixel to an image.
void	my_mlx_pixel_put(t_data *data, int x, int y, char *curr_img_addr)
{
	char	*dst;

	if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
	{
		dst = curr_img_addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = data->curr_color;
	}
}

void	draw_line_rest(t_line a, t_data *data)
{
	while (a.i <= a.steps)
	{
		if (data->pen_mode_state == 1 || data->eraser_mode == 1)
		{
			data->curr_color = data->pen_color;
			my_mlx_pixel_put(data, round(a.x), round(a.y), data->curr_img_addr);
		}
		else
		{
			data->curr_color = data->color;
			my_mlx_pixel_put(data, round(a.x), round(a.y), data->curr_img_addr);
		}
		a.x += a.x_inc;
		a.y += a.y_inc;
		a.i++;
	}
}

// WARNING : Set data->curr_img_addr before using it
void	draw_line(t_data *data, int x2, int y2)
{
	t_line	a;

	if (data->eraser_mode == 1)
		return ;
	a.i = 0;
	a.dx = x2 - data->x1;
	a.dy = y2 - data->y1;
	if (ft_abs(a.dx) > ft_abs(a.dy))
		a.steps = ft_abs(a.dx);
	else
		a.steps = ft_abs(a.dy);
	a.x_inc = (float)a.dx / (float)a.steps;
	a.y_inc = (float)a.dy / (float)a.steps;
	a.x = data->x1;
	a.y = data->y1;
	draw_line_rest(a, data);
}

int	draw(int x, int y, t_data *data, char *img_addr)
{
	if (data->eraser_mode == 1)
		return (eraser(x, y, data, img_addr));
	if (data->pen_mode_state == 1)
	{
		data->curr_color = data->pen_color;
		my_mlx_pixel_put(data, x, y, img_addr);
	}
	else
	{
		data->curr_color = data->color;
		my_mlx_pixel_put(data, x, y, img_addr);
	}
	return (0);
}
