#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h> // Can remove it later since we will use libft

typedef struct s_player
{
	double x;
	double y;
	double angle;
}	t_player;

typedef struct s_game
{
	char		**map;
	t_player	*player;
}	t_game;

double	calculate_ray_len(t_game *game);
double	calculate_straight_ray_len(t_game *game);

#endif
