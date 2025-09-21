/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:29 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 11:05:18 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	copy_image(char *from, char *to, int size)
{
	ft_printf("Copy image\n");
	if (!from || !to || !size)
		return ;
	ft_memcpy(to, from, size);
}

void	import_rest(t_data *data)
{
	if (!data->win_width || !data->win_height)
	{
		data->error = 8;
		stop_fdf(data);
	}
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"LOOK MOM I CAN CODE");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	import(t_data *data)
{
	void	*buff;
	void	*copy;
	int		size;

	buff = NULL;
	ft_printf("import\n");
	data->fd = open(data->file_name, O_RDONLY);
	ft_printf("%s\n", data->file_name);
	if (data->fd < 0)
		return ;
	buff = my_malloc(&(data->list), sizeof(int));
	read(data->fd, buff, 4);
	data->win_width = *(int *)buff;
	ft_printf("Width = %i\n", data->win_width);
	read(data->fd, buff, 4);
	data->win_height = *(int *)buff;
	ft_printf("Height = %i\n", data->win_height);
	import_rest(data);
	size = data->win_width * data->win_height * (data->bits_per_pixel / 8);
	copy = my_malloc(&(data->list), size);
	read(data->fd, copy, size);
	copy_image(copy, data->img_addr, size);
}
