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

# define WALL_NORTH 1
# define WALL_EAST 2
# define WALL_SOUTH 3
# define WALL_WEST 4

typedef struct s_ray
{
	double	x;
	double	y;
	double	unit;
	double	hypotenuse;
	int 	wall_side;
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
	t_ray		**rays;
	t_player	*player;
}	t_game;

// void	calculate_ray_len(t_game *game);
// void	calculate_straight_ray_len(t_game *game);
// void	calculate_ray_0_90_len(t_game *game);
// void	calculate_ray_90_180_len(t_game *game);
// void	calculate_ray_180_270_len(t_game *game);
// void	calculate_ray_270_360_len(t_game *game);

// void	initiate_ray(t_game *game, t_ray *ray);
void	caste_rays(t_game *game);

#endif
