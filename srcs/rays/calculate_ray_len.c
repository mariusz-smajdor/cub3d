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

double calculate_x_ray(t_game *game, t_ray *ray)
{
    ray->hypotenuse += ray->unit / sin(game->player->angle * M_PI / 180);
    ray->y -= (ray->unit / sin(game->player->angle * M_PI / 180)) * cos(game->player->angle * M_PI / 180);
    ray->x += ray->unit;
    ray->unit = 1;
    
    if (game->map[(int)ray->y][(int)ray->x] == '1')
	{
		printf("x: %f, y: %f\n", ray->x, ray->y);
        return (ray->hypotenuse);
	}
    return (-1);
}

double calculate_y_ray(t_game *game, t_ray *ray)
{
    ray->hypotenuse += ray->unit / cos(game->player->angle * M_PI / 180);
    ray->x += (ray->unit / cos(game->player->angle * M_PI / 180)) * sin(game->player->angle * M_PI / 180);
    ray->y -= ray->unit;
    ray->unit = 1;
    
    if (game->map[(int)ray->y - 1][(int)ray->x] == '1')
	{
		printf("yyyyyyx: %f, y: %f\n", ray->x, ray->y);
        return (ray->hypotenuse);
	}
    return (-1);
}

static double	calculate_ray_0_90_len(t_game *game)
{
    double	result;
	t_ray	x_unit_ray;
	t_ray	y_unit_ray;

	initiate_ray(game, &x_unit_ray);
	initiate_ray(game, &y_unit_ray);
	while (true)
	{
		if (x_unit_ray.x != floor(x_unit_ray.x))
			x_unit_ray.unit = ceil(x_unit_ray.x) - x_unit_ray.x;
		if (y_unit_ray.y != floor(y_unit_ray.y))
			y_unit_ray.unit = y_unit_ray.y - floor(y_unit_ray.y);

		if (x_unit_ray.unit / cos(game->player->angle * M_PI / 180) <
			y_unit_ray.unit / sin(game->player->angle * M_PI / 180))
			result = calculate_y_ray(game, &y_unit_ray);
		else
		{

			result = calculate_x_ray(game, &x_unit_ray);
		}
		printf("x_ray.x: %f, x_ray.y: %f\n", x_unit_ray.x, x_unit_ray.y);
		printf("y_ray.x: %f, y_ray.y: %f\n\n", y_unit_ray.x, y_unit_ray.y);
		if (result != -1)
			return (result);
	}
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
