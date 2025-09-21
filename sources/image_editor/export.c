/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:23 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 10:22:06 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	merge_loop(int size, unsigned int *dest, unsigned int *src1,
		unsigned int *src2)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (src2[i] != 0)
			dest[i] = src2[i];
		else
			dest[i] = src1[i];
		i++;
	}
}

// Blend images in data->curr_img_addr
// The base image is img1
// The drawing is img2
char	*merge_images(t_data *data, char *img1, char *img2)
{
	int				size;
	unsigned int	*dest;
	unsigned int	*src1;
	unsigned int	*src2;

	if (!img1 || !img2)
		return (NULL);
	if (data->curr_img && data->mlx)
		mlx_destroy_image(data->mlx, data->curr_img);
	if (data->curr_img_addr != NULL)
		data->curr_img_addr = NULL;
	data->curr_img = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	data->curr_img_addr = mlx_get_data_addr(data->curr_img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	if (!data->curr_img_addr)
		return (NULL);
	dest = (unsigned int *)data->curr_img_addr;
	src1 = (unsigned int *)img1;
	src2 = (unsigned int *)img2;
	size = data->win_width * data->win_height;
	merge_loop(size, dest, src1, src2);
	return (data->curr_img_addr);
}

int	export_rest(t_data *data)
{
	if (data->pen_img_addr)
	{
		if (!merge_images(data, data->img_addr, data->pen_img_addr))
		{
			close(data->fd);
			return (1);
		}
	}
	if (!data->pen_img_addr)
	{
		if (!data->img_addr)
		{
			close(data->fd);
			return (1);
		}
		data->curr_img_addr = data->img_addr;
	}
	write(data->fd, &data->win_width, 4);
	write(data->fd, &data->win_height, 4);
	write(data->fd, data->curr_img_addr, data->win_width * data->win_height
		* (data->bits_per_pixel / 8));
	if (data->curr_img_addr && data->curr_img_addr != data->img_addr)
		data->curr_img_addr = NULL;
	data->in_export = 0;
	return (0);
}

void	export(t_data *data)
{
	ft_printf("export\n");
	set_export_name(data);
	if (!data->export_name)
		return ;
	if (open(data->export_name, O_RDONLY) != -1)
	{
		ft_printf("Trying to open %s\n", data->export_name);
		if (data->export_name)
			my_addtolist(&data->list, data->export_name);
		return (export(data));
	}
	ft_printf("Trying to create file at: %s\n", data->export_name);
	data->fd = open(data->export_name, O_WRONLY | O_CREAT, 0644);
	if (data->fd == -1)
		return ;
	data->curr_img_addr = NULL;
	if (export_rest(data) != 1)
		return ;
	close(data->fd);
}
