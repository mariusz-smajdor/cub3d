#include "cub3d.h"

typedef struct s_ray
{
	double	x;
	double	y;
	double	unit;
	double	hypotenuse;
}	t_ray;

void initiate_ray(t_game *game, t_ray *ray)
{
	ray->x = game->player->x;
	ray->y = game->player->y;
	ray->unit = 1;
	ray->hypotenuse = 0;
}

static double	calculate_ray_0_90_len(t_game *game)
{
	t_ray	x_unit_ray;
	t_ray	y_unit_ray;

	initiate_ray(game, &x_unit_ray);
	initiate_ray(game, &y_unit_ray);
	while (true)
	{
		if (x_unit_ray.x != floor(x_unit_ray.x))
			x_unit_ray.unit = ceil(x_unit_ray.x) - x_unit_ray.x;
		if (y_unit_ray.y != floor(y_unit_ray.y))
			y_unit_ray.unit = ceil(y_unit_ray.y) - y_unit_ray.y;
		if (x_unit_ray.unit / cos(game->player->angle * M_PI / 180) <
			y_unit_ray.unit / sin(game->player->angle * M_PI / 180))
		{
			x_unit_ray.hypotenuse += x_unit_ray.unit / cos(game->player->angle * M_PI / 180);
			x_unit_ray.y += x_unit_ray.hypotenuse * sin(game->player->angle * M_PI / 180);
			x_unit_ray.x += x_unit_ray.unit;
			x_unit_ray.unit = 1;
			if (game->map[(int)x_unit_ray.y][(int)x_unit_ray.x] == '1')
				return (x_unit_ray.hypotenuse);
		}
		else
		{
			y_unit_ray.hypotenuse += y_unit_ray.unit / sin(game->player->angle * M_PI / 180);
			y_unit_ray.x += y_unit_ray.hypotenuse * cos(game->player->angle * M_PI / 180);
			y_unit_ray.y += y_unit_ray.unit;
			y_unit_ray.unit = 1;
			if (game->map[(int)y_unit_ray.y][(int)y_unit_ray.x] == '1')
				return (y_unit_ray.hypotenuse);
		}
	}
	return (0);
}

static double	calculate_diagonal_ray_len(t_game *game)
{
	// Calculate the length of ray between 0 and 90 degrees
	if (game->player->angle > 0 && game->player->angle < 90)
		return (calculate_ray_0_90_len(game));
	// Calculate the length of ray between 90 and 180 degrees

	// Calculate the length of ray between 180 and 270 degrees

	// Calculate the length of ray between 270 and 360 degrees
	return (0); // Return the length of the ray
}

double	calculate_ray_len(t_game *game)
{
	if (game->player->angle == 0 || game->player->angle == 90
		|| game->player->angle == 180 || game->player->angle == 270)
		return (calculate_straight_ray_len(game));
	return (calculate_diagonal_ray_len(game));
}
