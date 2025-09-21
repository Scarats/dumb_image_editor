/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:19:27 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:14:54 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_text_rest(t_data *data)
{
	if (data->pen_color == RED)
		mlx_string_put(data->mlx, data->win, 30, 100, YELLOW, "Red    (R)");
	else
		mlx_string_put(data->mlx, data->win, 30, 100, WHITE, "Red    (R)");
	if (data->pen_color == GREEN)
		mlx_string_put(data->mlx, data->win, 30, 120, YELLOW, "Green  (G)");
	else
		mlx_string_put(data->mlx, data->win, 30, 120, WHITE, "Green  (G)");
	if (data->pen_color == BLUE)
		mlx_string_put(data->mlx, data->win, 30, 140, YELLOW, "Blue   (B)");
	else
		mlx_string_put(data->mlx, data->win, 30, 140, WHITE, "Blue   (B)");
	if (data->pen_color == WHITE)
		mlx_string_put(data->mlx, data->win, 30, 160, YELLOW, "White  (W)");
	else
		mlx_string_put(data->mlx, data->win, 30, 160, WHITE, "White  (W)");
	if (data->pen_color == BLACK)
		mlx_string_put(data->mlx, data->win, 30, 180, YELLOW, "Black  (0)");
	else
		mlx_string_put(data->mlx, data->win, 30, 180, WHITE, "Black  (0)");
}

void	put_text(t_data *data)
{
	if (data->pen_mode_state == 1)
		mlx_string_put(data->mlx, data->win, 20, 20, YELLOW, "Pen    (P)");
	else
		mlx_string_put(data->mlx, data->win, 20, 20, WHITE, "Pen    (P)");
	if (data->in_export == 1)
		mlx_string_put(data->mlx, data->win, 20, 40, YELLOW, "Export (E)");
	else
		mlx_string_put(data->mlx, data->win, 20, 40, WHITE, "Export (E)");
	if (data->eraser_mode == 1)
		mlx_string_put(data->mlx, data->win, 20, 60, YELLOW, "Eraser (D)");
	else
		mlx_string_put(data->mlx, data->win, 20, 60, WHITE, "Eraser (D)");
	mlx_string_put(data->mlx, data->win, 20, 80, WHITE, "Colors:");
	put_text_rest(data);
}
