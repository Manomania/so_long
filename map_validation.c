/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:49:20 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:49:24 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.height)
		if (data->map.grid[i][0] != '1'
			|| (data->map.grid[i][data->map.width - 1] != '1'))
			return (1);
	i = -1;
	while (++i < data->map.width)
		if (data->map.grid[0][i] != '1'
			|| (data->map.grid[data->map.height - 1][i] != '1'))
			return (1);
	return (0);
}

void	count_characters(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.height)
	{
		y = 0;
		while (y < data->map.width)
		{
			if (data->map.grid[x][y] == 'C')
				data->count.c_count++;
			if (data->map.grid[x][y] == 'P')
				data->count.p_count++;
			if (data->map.grid[x][y] == 'E')
				data->count.e_count++;
			y++;
		}
		x++;
	}
	if (data->count.c_count == 0 || data->count.p_count != 1 || data->count.e_count != 1)
		exit(1);
}

static void find_player_position(t_data *data)
{
	int x;
	int y;

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
				return;
			}
			y++;
		}
		x++;
	}
}

int map_is_valid(t_data *data)
{
	char **grid_copy;

	if (check_walls(data) || check_size(data))
	{
		free_tab(data);
		return (1);
	}
	count_characters(data);
	find_player_position(data);
	grid_copy = copy_grid(data);
	if (!grid_copy)
		return (1);
	flood_fill(data->map.play.pos.x, data->map.play.pos.y, data, grid_copy);
	free_grid_copy(grid_copy, data->map.height);
	if (data->map.exit.found != 1 || data->map.collect.collected != data->count.c_count)
		return (1);
	return (0);
}
