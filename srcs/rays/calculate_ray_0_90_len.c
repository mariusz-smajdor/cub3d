#include "cub3d.h"

static double calculate_x_ray(t_game *game, t_ray *ray)
{
	double unit_hypotenuse;

	unit_hypotenuse = ray->unit / sin(game->player->angle * M_PI / 180);
    ray->hypotenuse += unit_hypotenuse;
    ray->y -= unit_hypotenuse * cos(game->player->angle * M_PI / 180);
    ray->x += ray->unit;
    ray->unit = 1;
    if (game->map[(int)ray->y][(int)ray->x] == '1')
        return (ray->hypotenuse);
    return (-1);
}

static double calculate_y_ray(t_game *game, t_ray *ray)
{
	double unit_hypotenuse;

	unit_hypotenuse = ray->unit / cos(game->player->angle * M_PI / 180);
    ray->hypotenuse += unit_hypotenuse;
    ray->x += unit_hypotenuse * sin(game->player->angle * M_PI / 180);
    ray->y -= ray->unit;
    ray->unit = 1;
    if (game->map[(int)ray->y - 1][(int)ray->x] == '1')
        return (ray->hypotenuse);
    return (-1);
}

double	calculate_ray_0_90_len(t_game *game)
{
	double	result;
	t_ray	x_unit_ray;
	t_ray	y_unit_ray;

	initiate_ray(game, &x_unit_ray);
	initiate_ray(game, &y_unit_ray);
	if (x_unit_ray.x != floor(x_unit_ray.x))
		x_unit_ray.unit = ceil(x_unit_ray.x) - x_unit_ray.x;
	if (y_unit_ray.y != floor(y_unit_ray.y))
		y_unit_ray.unit = y_unit_ray.y - floor(y_unit_ray.y);
	while (true)
	{
		if (x_unit_ray.unit / cos(game->player->angle * M_PI / 180) <
			y_unit_ray.unit / sin(game->player->angle * M_PI / 180))
			result = calculate_y_ray(game, &y_unit_ray);
		else
			result = calculate_x_ray(game, &x_unit_ray);
		if (result != -1)
			return (result);
	}
}
