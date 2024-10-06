#include "cub3d.h"

static t_ray	calculate_x_ray(t_ray ray)
{
	double	unit_hypotenuse;

	if (ray.x != floor(ray.x))
		ray.unit = ray.x - floor(ray.x);
	else
		ray.unit = 1;
	unit_hypotenuse = ray.unit / ray.sin_angle;
	ray.hypotenuse += unit_hypotenuse;
	ray.y += unit_hypotenuse * ray.cos_angle;
	ray.x -= ray.unit;
	return (ray);
}

static t_ray	calculate_y_ray(t_ray ray)
{
	double	unit_hypotenuse;

	if (ray.y != floor(ray.y))
		ray.unit = ray.y - floor(ray.y);
	else
		ray.unit = 1;
	unit_hypotenuse = ray.unit / ray.cos_angle;
    ray.hypotenuse += unit_hypotenuse;
    ray.x -= unit_hypotenuse * ray.sin_angle;
    ray.y += ray.unit;
    return (ray);
}

double	calculate_ray_180_270_len(t_game *game)
{
	t_ray	ray;
	t_ray	x_unit_ray;
	t_ray	y_unit_ray;
	initiate_ray(game, &ray);
	while (game->map[(int)floor(ray.y)][(int)ceil(ray.x) - 1] != '1')
	{
		x_unit_ray = calculate_x_ray(ray);
		y_unit_ray = calculate_y_ray(ray);
		if (x_unit_ray.hypotenuse < y_unit_ray.hypotenuse)
			ray = x_unit_ray;
		else
			ray = y_unit_ray;
	}
	return (ray.hypotenuse);
}