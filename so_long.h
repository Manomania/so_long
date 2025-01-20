#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1920
# define HEIGHT 1080

#include "minilibx-linux/mlx.h"
#include "./libft/include/libft.h"

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_colors
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_colors;

typedef struct s_point
{
	int	x; // x is the length
	int	y; // y is the width
	int	z; // z is the height
	t_colors	*colors;
}		t_point;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adrr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_map
{
	t_point	**points;
	int	width;
	int height;
}		t_map;


#endif
