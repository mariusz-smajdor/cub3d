#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <stdlib.h> // Can remove it later since we will use libft
# include "../libs/minilibx/mlx.h"

# define FOV 100
# define WIN_WIDTH 1440
# define WIN_HEIGHT 900

typedef struct s_ray
{
	double	x;
	double	y;
	double	unit;
	double	hypotenuse;
	double	angle_radians;
	double	sin_angle;
	double	cos_angle;
}	t_ray;

typedef struct s_player
{
	double x;
	double y;
	double angle;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	double		walls[FOV];
	t_player	*player;
}	t_game;

double	calculate_ray_len(t_game *game);
double	calculate_straight_ray_len(t_game *game);
double	calculate_ray_0_90_len(t_game *game);
double	calculate_ray_90_180_len(t_game *game);
double	calculate_ray_180_270_len(t_game *game);
double	calculate_ray_270_360_len(t_game *game);

void	initiate_ray(t_game *game, t_ray *ray);

#endif
