/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:53:38 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:53:41 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static int	get_dimensions(int fd, t_data *data)
{
	char* line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		if (!data->map.width)
			data->map.width = my_strlen(line);
		else if (my_strlen(line) != data->map.width)
		{
			free(line);
			ft_printf("%sError:\nMap isn't rectangular%s\n", RED, RESET);
			close(fd);
			exit(1);
		}
		data->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

static int	fill_map(int fd, t_data *data)
{
	char* line;
	int i;

	i = 0;
	data->map.grid = malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.grid)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		data->map.grid[i++] = line;
		line = get_next_line(fd);
	}
	data->map.grid[i] = NULL;
	return (0);
}

int	read_map(t_data *data, const char *file)
{
	int	fd;

	init_map_data(data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free_tab(data), 1);
	if (get_dimensions(fd, data))
		return (close(fd), 1);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (fill_map(fd, data))
		return (close(fd), 1);
	close(fd);
	return (0);
}
