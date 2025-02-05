/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:52:49 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:52:52 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_map_condition(t_data *data, int x, int y)
{
	if (data->map.grid[x][y] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
			y * BLOCK, x * BLOCK);
	else if (data->map.grid[x][y] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.floor,
			y * BLOCK, x * BLOCK);
	else if (data->map.grid[x][y] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			y * BLOCK, x * BLOCK);
	else if (data->map.grid[x][y] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collect,
			y * BLOCK, x * BLOCK);
	else if (data->map.grid[x][y] == 'E' && data->count.c_count == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit_open,
			y * BLOCK, x * BLOCK);
	else if (data->map.grid[x][y] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit_closed,
			y * BLOCK, x * BLOCK);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.height)
	{
		y = 0;
		while (y < data->map.width)
		{
			render_map_condition(data, x, y);
			y++;
		}
		x++;
	}
}
