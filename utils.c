/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:53:56 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:54:03 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size(t_data *data)
{
	if (data->map.height >= 36 || data->map.width >= 65)
		exit_correctly(data);
	return (0);
}

void	free_grid_copy(char **grid_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(grid_copy[i++]);
	free(grid_copy);
}

int	exit_correctly(t_data *data)
{
	cleanup_textures(data);
	free_tab(data);
	return (1);
}

void	free_tab(t_data *data)
{
	int	i;

	if (data->map.grid)
	{
		i = -1;
		while (++i < data->map.height)
			free(data->map.grid[i]);
		free(data->map.grid);
	}
	exit(1);
}