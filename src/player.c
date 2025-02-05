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

#include "../include/so_long.h"

void	set_player_position(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.height)
	{
		y = 0;
		while (y < data->map.width)
		{
			if (data->map.grid[x][y] == 'P')
			{
				data->map.play.pos.x = x;
				data->map.play.pos.y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static void	move_data(t_data *data, int x, int y)
{
	if (data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == 'E'
		&& (data->count.c_count == 0))
	{
		data->map.play.movement++;
		ft_printf("%s%sYou won in %d moves!!!!%s\n",
			RESET_LINE, GREEN, data->map.play.movement, RESET);
		cleanup_textures(data);
		exit(0);
	}
	if (data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == 'C')
	{
		data->count.c_count--;
	}
	data->map.grid[x][y] = '0';
	data->map.grid[data->map.play.pos.x][data->map.play.pos.y] = 'P';
	data->map.play.movement++;
	ft_printf("%s%sMovements : %d%s", RESET_LINE, YELLOW,
		data->map.play.movement, RESET);
}

void	move_player(int key, t_data *data)
{
	int	x;
	int	y;

	if (key != W && key != A && key != S && key != D)
		return ;
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
	if (data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == '1'
		|| (data->map.exit.open == 0
		&& (data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == 'E')))
	{
		data->map.play.pos.x = x;
		data->map.play.pos.y = y;
		return ;
	}
	move_data(data, x, y);
}
