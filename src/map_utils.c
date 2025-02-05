/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:49:44 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:49:47 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(int x, int y, t_data *data, char **grid_copy)
{
	if (!grid_copy || x < 0 || y < 0
		|| (x >= data->map.height || y >= data->map.width))
		return ;
	if (grid_copy[x][y] == '1' || grid_copy[x][y] == 'V')
		return ;
	if (grid_copy[x][y] == 'C')
		data->map.collect.collected++;
	else if (grid_copy[x][y] == 'E')
	{
		data->map.exit.found = 1;
		return ;
	}
	grid_copy[x][y] = 'V';
	flood_fill(x + 1, y, data, grid_copy);
	flood_fill(x - 1, y, data, grid_copy);
	flood_fill(x, y + 1, data, grid_copy);
	flood_fill(x, y - 1, data, grid_copy);
}

char	**copy_grid(t_data *data)
{
	char	**grid_copy;
	int		i;

	grid_copy = malloc(sizeof(char *) * (data->map.height + 1));
	if (!grid_copy)
		return (NULL);
	i = 0;
	while (i < data->map.height)
	{
		grid_copy[i] = ft_strdup(data->map.grid[i]);
		if (!grid_copy[i])
		{
			while (--i >= 0)
				free(grid_copy[i]);
			free(grid_copy);
			return (NULL);
		}
		i++;
	}
	grid_copy[i] = NULL;
	return (grid_copy);
}
