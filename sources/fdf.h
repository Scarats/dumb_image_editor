/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:50:16 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 16:33:39 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000001
# define EMPTY 0x000000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00

typedef struct s_2d
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_2d;

typedef struct s_data
{
	t_list	*list;
	t_list	*temp_list;

	t_2d	**arr2d;
	int		arr_width;

	char	**arr3d;
	int		arr_size;
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	int		z_min;

	int		x_offset;
	int		y_offset;
	int		center_x;
	int		center_y;
	double	scale_factor;
	int		projection_height;
	int		projection_width;

	void	*mlx;
	void	*win;
	int		error;

	int		win_width;
	int		win_height;

	void	*img;
	void	*pen_img;
	// void	*import_img;
	void	*curr_img;

	char	*img_addr;
	char	*pen_img_addr;
	// char	*import_img_addr;
	char	*curr_img_addr;

	int		fd;
	int		f_type; // 0 for none, 1 for fdf, -1 for dumb.
	int		version;
	char	*file_name;
	char	*export_name;
	int		in_export;
	char	*base_name;
	char	*dot_pos;
	char	*v_pos;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;

	int		pen_mode_state;
	int		backup_state;
	int		eraser_mode;
	int		mouse_pressed;
	int		is_first_click;
	int		drawing_line;
	int		pen_color;
	int		backup_color;
	int		curr_color;

	int		x1;
	int		y1;
}			t_data;

typedef struct s_line
{
	int		dx;
	int		dy;

	int		i;
	int		steps;

	float	x_inc;
	float	y_inc;

	double	x;
	double	y;
}			t_line;

void		my_mlx_pixel_put(t_data *data, int x, int y, char *img_addr);
void		draw_line(t_data *data, int x2, int y2);
int			ft_abs(int x);
void		pen_init(t_data *data);
int			key_hook(int keycode, t_data *data);
int			pen_mode(t_data *data);
int			draw(int x, int y, t_data *data, char *img_addr);
void		rendering(t_data *data);
int			mouse_press(int button, int x, int y, t_data *data);
int			mouse_release(int button, int x, int y, t_data *data);
int			mouse_move(int x, int y, t_data *data);
int			pen_mode(t_data *data);
void		setup_hooks(t_data *data);
int			stop_fdf(t_data *data);
void		export(t_data *data);
void		set_export_name(t_data *data);
void		check_input(int ac, char **av, t_data *data);
char		*merge_images(t_data *data, char *img1, char *img2);
void		init(t_data *data);
void		import(t_data *data);
int			eraser(int x, int y, t_data *data, char *img_addr);
void		change_eraser_state(t_data *data);
void		parse_arr(t_data *data);
void		to_window(t_data *data);
void		check_array_size(t_data *data);
int			stop_fdf(t_data *data);
void		list_init(t_data *data);
void		put_text(t_data *data);
double		scale_calculation(int proj_hei, int win_hei, int proj_wi,
				int win_wi);
void		calculate_scale_factor(t_data *data);
void		calculate_offsets(t_data *data);
void		apply_transformations(t_data *data);

#endif