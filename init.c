/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:46:05 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:46:09 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_map_data(t_data* data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map.grid = NULL;
	data->map.height = 0;
	data->map.width = 0;
	data->count.c_count = 0;
	data->count.p_count = 0;
	data->count.e_count = 0;
	data->map.collect.collected = 0;
	data->map.exit.found = 0;
	data->map.exit.open = 0;
	data->map.play.pos.x = 0;
	data->map.play.pos.y = 0;
	data->map.play.movement = 0;
	data->map.play.collected = 0;
	data->img.wall = NULL;
	data->img.player = NULL;
	data->img.collect = NULL;
	data->img.exit_closed = NULL;
	data->img.exit_open = NULL;
	data->img.floor = NULL;
}

void	init_display(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_1(data);
	if (map_is_valid(data))
		exit_1(data);
	set_player_position(data);
	data->win = mlx_new_window(data->mlx, data->map.width * BLOCK,
								data->map.height * BLOCK, TITLE);
	if (!data->win)
		exit_1(data);
	if (load_textures(data))
		exit_1(data);
	render_map(data);
	mlx_hook(data->win, 2, 1L << 0, handle_key, data);
	mlx_hook(data->win, ON_DESTROY, 0, handle_destroy, data);
	mlx_loop(data->mlx);
}
