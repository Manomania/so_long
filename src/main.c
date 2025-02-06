/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:53:17 by maximart          #+#    #+#             */
/*   Updated: 2025/01/31 08:53:20 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_error(int argc, char **argv)
{
	const char	*ptr;

	if (argc != 2)
	{
		ft_printf("%sError:\nUsage: %s <map_file>%s\n", RED, argv[0], RESET);
		return (1);
	}
	ptr = ft_strnstr(argv[1], ".ber", INT_MAX);
	if (!ptr || ptr[4] != '\0')
	{
		ft_printf("%sError:\nInvalid extension\n%s", RED, RESET);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_error(argc, argv))
		return (1);
	read_map(&data, argv[1]);
	init_display(&data);
	return (0);
}
