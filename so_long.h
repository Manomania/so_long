/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:49:55 by maximart          #+#    #+#             */
/*   Updated: 2025/01/30 21:09:19 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1920
# define HEIGHT 1080
# define BLOCK 60
# define TITLE "so_long"
# define RESET_LINE "\033[H\033[J"
# define RED "\033[091m"
# define RESET "\033[039m"
# define GREEN "\033[092m"
# define YELLOW "\033[093m"

# include "./minilibx-linux/mlx.h"
# include "./libft/include/libft.h"
# include <limits.h>

enum	e_keyboard
{
	W = 119,
	S = 115,
	D = 100,
	A = 97,
	ESCAPE = 65307,
};

enum	e_key
{
	ON_DESTROY = 17,
};

typedef char	t_bool;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_exit
{
	t_pos	pos;
	t_bool	open;
	t_bool	found;
}			t_exit;

typedef struct s_play
{
	t_pos	pos;
	int		movement;
	int		collected;
}			t_play;

typedef struct s_coll
{
	t_pos	pos;
	int		collected;
}			t_coll;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit_closed;
	void	*exit_open;
	void	*floor;
}			t_img;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_exit		exit;
	t_play		play;
	t_coll		collect;
}				t_map;

typedef struct s_count
{
	int	c_count;
	int	e_count;
	int	p_count;
}		t_count;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*adrr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_img		img;
	t_map		map;
	t_count		count;
}				t_data;

int check_size(t_data* data);
void	free_grid_copy(char **grid_copy, int height);
int exit_correctly(t_data* data);
void	free_tab(t_data *data);
int load_textures(t_data* data);
int cleanup_textures(t_data* data);
void	render_map(t_data *data);
int handle_key(int key, t_data* data);
int handle_destroy(t_data* data);
int read_map(t_data* data, const char* file);
void move_player(int key, t_data* data);
void set_player_position(t_data* data);
void count_characters(t_data* data);
int map_is_valid(t_data* data);
void flood_fill(int x, int y, t_data* data, char** grid_copy);
char** copy_grid(t_data* data);
void init_display(t_data* data);
void init_map_data(t_data* data);
void	render_map(t_data *data);
void exit_1(t_data* data);
#endif
