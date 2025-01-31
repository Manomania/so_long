/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:50:04 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:50:08 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void set_player_position(t_data *data)
{
	int x = 0;
	while (x < data->map.height)
	{
		int y = 0;
		while (y < data->map.width)
		{
			if (data->map.grid[x][y] == 'P')
			{
				data->map.play.pos.x = x;
				data->map.play.pos.y = y;
				return;
			}
			y++;
		}
		x++;
	}
}

void	move_player(int key, t_data *data)
{
	int	x;
	int y;

	if (key != W && key != A && key != S && key != D)
		return;
	x = data->map.play.pos.x;
	y = data->map.play.pos.y;
	if (key == W)
		data->map.play.pos.x--;
	if (key == S)
		data->map.play.pos.x++;
	if (key == D)
		data->map.play.pos.y++;
	if (key == A)
		data->map.play.pos.y--;
	if (data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == '1' || (data->map.exit.open == 0 && data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == 'E'))
	{
		data->map.play.pos.x = x;
		data->map.play.pos.y = y;
		return ;
	}
	if (data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == 'E' && data->count.c_count == 0)
	{
		ft_printf("%sYou won in %d moves!!!!\n", RESET_LINE, data->map.play.movement);
		cleanup_textures(data);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		exit(0);
	}
	if (data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == 'C')
	{
		data->count.c_count--;
	}
	data->map.grid[x][y] = '0';
	data->map.grid[data->map.play.pos.x][data->map.play.pos.y] = 'P';
	data->map.play.movement++;
	ft_printf("%sMovements : %d", RESET_LINE, data->map.play.movement);
}