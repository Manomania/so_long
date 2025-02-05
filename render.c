/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:52:15 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:52:18 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_destroy(t_data *data)
{
	cleanup_textures(data);
	exit(0);
}

int handle_key(int key, t_data* data)
{
	int old_x;
	int old_y;

	old_x = data->map.play.pos.x;
	old_y = data->map.play.pos.y;
	if (key == ESCAPE)
		handle_destroy(data);
	if (key == W || key == A || key == S || key == D)
	{
		move_player(key, data);
		if (old_x != data->map.play.pos.x || old_y != data->map.play.pos.y)
			render_map(data);
	}
	if (data->map.grid[data->map.play.pos.x][data->map.play.pos.y] == 'C')
		data->count.c_count--;
	if (data->count.c_count == 0)
		data->map.exit.open = 1;
	return (0);
}
