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

# define STEP 0.1

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
	double 	wall_height;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	int 	angle;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_ray		**rays;
	t_player	*player;
}	t_game;

void	caste_rays(t_game *game);
void	caste_straight_ray(t_game *game, int ray_index, int angle);
void	caste_0_90_angle_ray(t_game *game, int ray_index, int angle);
void	caste_90_180_angle_ray(t_game *game, int ray_index, int angle);
void	caste_180_270_angle_ray(t_game *game, int ray_index, int angle);
void	caste_270_360_angle_ray(t_game *game, int ray_index, int angle);

void	initiate_ray(t_game *game, int ray_index, int angle);
void	caste_rays(t_game *game);

int		handle_key_events(int keycode, t_game *game);
int		close_game(t_game *game);

#endif
