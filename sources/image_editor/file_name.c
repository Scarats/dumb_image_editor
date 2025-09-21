/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:49:25 by tcardair          #+#    #+#             */
/*   Updated: 2025/06/04 11:00:04 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_version(char *name)
{
	int	i;

	ft_printf("get version\n");
	i = 0;
	while (name[i])
	{
		if (name[i] == '_' && name[i + 1] == 'V' && name[i + 2] >= '1' && name[i
				+ 2] <= '9')
			return (ft_atoi(&name[i + 2]));
		i++;
	}
	return (0);
}

char	*gen_rand_name(t_data *data)
{
	int				i;
	char			*name;
	unsigned long	addr;

	name = my_malloc(&(data->list), 11);
	if (!name)
		return (NULL);
	ft_printf("get rand\n");
	i = 0;
	while (i < 10)
	{
		addr = (unsigned long)name * (i + 1);
		name[i] = 'a' + (addr % 26);
		i++;
	}
	name[9] = '\0';
	ft_printf("Name: %s\n", name);
	return (name);
}

void	extract_base_name(t_data *data, int *version)
{
	ft_printf("extract base name\n");
	if (!data->file_name)
	{
		data->base_name = gen_rand_name(data);
		data->base_name[0] = '@';
		return ;
	}
	data->dot_pos = ft_strrchr(data->file_name, '.');
	data->v_pos = ft_strstr(data->file_name, "_V");
	if (data->v_pos && data->dot_pos && data->v_pos < data->dot_pos)
	{
		data->base_name = ft_substr(data->file_name, 0, data->v_pos
				- data->file_name);
		*version = get_version(data->file_name) + 1;
	}
	else
	{
		if (data->dot_pos)
			data->base_name = ft_substr(data->file_name, 0, data->dot_pos
					- data->file_name);
		else
			data->base_name = ft_strdup(data->file_name);
	}
	my_addtolist(&data->list, data->base_name);
}

int	build_version_filename(t_data *data, int version)
{
	char	*version_str;
	char	*temp;

	ft_printf("build version filename\n");
	version_str = ft_itoa(version);
	if (!version_str)
		return (0);
	data->export_name = ft_strjoin(data->base_name, "_V");
	if (!data->export_name)
		return (my_addtolist(&data->list, version_str), 0);
	temp = data->export_name;
	data->export_name = ft_strjoin(temp, version_str);
	my_addtolist(&data->list, temp);
	my_addtolist(&data->list, version_str);
	my_addtolist(&data->list, data->export_name);
	if (!data->export_name)
		return (0);
	temp = data->export_name;
	data->export_name = ft_strjoin(temp, ".dumb");
	my_addtolist(&data->list, temp);
	my_addtolist(&data->list, data->export_name);
	return (data->export_name != NULL);
}

void	set_export_name(t_data *data)
{
	ft_printf("set export name\n");
	data->version++;
	if (!data->base_name)
	{
		extract_base_name(data, &data->version);
		if (!data->base_name)
			return ;
	}
	if (!build_version_filename(data, data->version))
		return ;
}
