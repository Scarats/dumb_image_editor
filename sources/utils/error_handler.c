/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:55 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:04:52 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_arr(t_data *data)
{
	int	i;

	i = 0;
	if (data->arr3d != NULL)
	{
		while (data->arr3d[i])
		{
			free(data->arr3d[i]);
			data->arr3d[i] = NULL;
			i++;
		}
		data->arr3d = NULL;
	}
}

void	stop_fdf_rest(t_data *data)
{
	if (data->error == 1)
		ft_printf("Error: at stop_fdf\n");
	else if (data->error == 2)
		ft_printf("Error: too many inputs.\n"
			"Program can handle one file only.\n");
	else if (data->error == 3)
		ft_printf("Error: wrong file type.\n"
			"Accepted file types: .fdf & .dumb\n");
	else if (data->error == 4)
		ft_printf("Error: issue while reading %s\n", data->file_name);
	else if (data->error == 5)
		ft_printf("Error: memory allocation failed\n");
	else if (data->error == 6)
		ft_printf("Error: Failed to get image address\n");
	else if (data->error == 7)
		ft_printf("Error: Map too small, it has to "
			"contain at least 2 points in width and height\n");
	else if (data->error == 7)
		ft_printf("Error: window width or height, or projection "
			"too small.\nCannot be equal to 0 or under 200px\n");
	else if (data->error == 8)
		ft_printf("Error: file not readable as .dumb\n");
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
}

int	stop_fdf(t_data *data)
{
	ft_printf("stop_fdf\n");
	if (data->pen_img_addr)
	{
		mlx_destroy_image(data->mlx, data->pen_img);
		data->pen_img = NULL;
		data->pen_img_addr = NULL;
	}
	stop_fdf_rest(data);
	if (data->curr_img)
		mlx_destroy_image(data->mlx, data->curr_img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->arr3d != NULL)
		free_arr(data);
	if (data->list)
		my_free(&(data->list));
	if (data->temp_list)
		my_free(&(data->temp_list));
	exit(0);
}

void	check_array_size(t_data *data)
{
	if (data->arr_size < 2 || data->arr_width < 2)
	{
		data->error = 7;
		stop_fdf(data);
	}
}
