/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:12:23 by maximart          #+#    #+#             */
/*   Updated: 2024/11/28 12:12:26 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file_lines(const char *file)
{
	int		fd;
	char	**lines;
	char	*temp;
	char	*prev;
	char	*content;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	temp = get_next_line(fd);
	while (temp)
	{
		prev = content;
		content = ft_strjoin(prev, temp);
		free(prev);
		free(temp);
		if (!content)
			return (close(fd), NULL);
		temp = get_next_line(fd);
	}
	close(fd);
	lines = ft_split(content, '\n');
	free(content);
	return (lines);
}

int	count_lines(char **lines)
{
	int	height;

	height = 0;
	if (!lines)
		return (0);
	while (lines[height])
		height++;
	return (height);
}

t_map *init_map(char **lines)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = count_lines(lines);
	map->width = (int)count_words(lines[0], ' ');
	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		return (free(map), NULL);
	return (map);
}

int	init_points(t_point *point, int x, int y, char *value)
{
	point->x = x;
	point->y = y;
	point->z = ft_atoi(value);
	point->colors = malloc(sizeof(t_colors));
	if (!point->colors)
		return (0);
	point->colors->t = 255;
	point->colors->r = 255;
	point->colors->g = 255;
	point->colors->b = 255;
	return (1);
}

int	fill_map_row(t_map *map, char *line, int y)
{
	char **values;
	int x;

	values = ft_split(line, ' ');
	map->points[y] = malloc(sizeof(t_point) * map->width);
	if (!map->points[y])
		return (0);
	x = 0;
	while (x < map->width)
	{
		if (!init_points(&map->points[y][x], x, y, values[x]))
		{
			free_words(values, map->width);
			return (0);
		}
		x++;
	}
	free_words(values, map->width);
	return (1);
}

int	fill_map_points(t_map *map, char **lines)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (!fill_map_row(map, lines[y], y))
			return (0);
		y++;
	}
	return (1);
}

void	free_map(t_map *map)
{
	int	y;
	int	x;

	if (!map)
		return ;
	y = 0;
	while (y < map->height)
	{
		if (map->points[y])
		{
			x = 0;
			while (x < map->width)
			{
				if (map->points[y][x].colors)
					free(map->points[y][x].colors);
				x++;
			}
			free(map->points[y]);
		}
		y++;
	}
	free(map->points);
	free(map);
}

t_map *parse_map(const char *file)
{
	t_map *map;
	char **lines = read_file_lines(file);
	if (!lines)
		return (NULL);

	map = init_map(lines);
	if (!map || !fill_map_points(map, lines))
	{
		free_words(lines, count_lines(lines));
		free_map(map);
		return (NULL);
	}
	free_words(lines, count_lines(lines));
	return (map);
}

 int	main(int ac, char **av)
 {
 	t_map	*map;

 	if (ac != 2)
 	{
 		ft_putstr_fd("Error\nUsage: ./fdf map_file\n", 2);
 		return (1);
 	}
 	map = parse_map(av[1]);
 	if (!map)
 	{
 		ft_putstr_fd("Error\nFailed to parse map\n", 2);
 		return (1);
 	}
 	// Ici tu peux ajouter ton code pour afficher/manipuler la map
 	printf("Map loaded successfully:\n");
 	printf("Height: %d\n", map->height);
 	printf("Width: %d\n", map->width);

 	// Test d'affichage des points (optionnel, pour debug)
 	int y = 0;
 	while (y < map->height)
 	{
 		int x = 0;
 		while (x < map->width)
 		{
 			printf("%3d ", map->points[y][x].z);
 			x++;
 		}
 		printf("\n");
 		y++;
 	}

 	free_map(map);
 	return (0);
 }
