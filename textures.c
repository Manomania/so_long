/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:48:39 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:48:42 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int load_textures(t_data* data)
{
	int b;

	b = BLOCK;
	data->img.wall = mlx_xpm_file_to_image(data->mlx,
											"assets/wall.xpm", &b, &b);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
											"assets/player.xpm", &b, &b);
	data->img.collect = mlx_xpm_file_to_image(data->mlx,
											"assets/clt.xpm", &b, &b);
	data->img.exit_closed = mlx_xpm_file_to_image(data->mlx,
												"assets/exit.xpm", &b, &b);
	data->img.exit_open = mlx_xpm_file_to_image(data->mlx,
												"assets/exit_open.xpm", &b, &b);
	data->img.floor = mlx_xpm_file_to_image(data->mlx,
											"assets/floor.xpm", &b, &b);
	if (!data->img.wall || !data->img.player || !data->img.collect
		|| (!data->img.exit_closed || !data->img.floor || !data->img.exit_open))
	{
		ft_printf("%sError:\nYour file image isn´t readable%s\n", RED, RESET);
		exit_1(data);
	}
	return (0);
}

int cleanup_textures(t_data* data)
{
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.collect)
		mlx_destroy_image(data->mlx, data->img.collect);
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->img.exit_open)
		mlx_destroy_image(data->mlx, data->img.exit_open);
	if (data->img.exit_closed)
		mlx_destroy_image(data->mlx, data->img.exit_closed);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_tab(data);
	return (0);
}
