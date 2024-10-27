#include "cub3d.h"

static t_ray	move_by_x_unit(t_ray ray)
{
	double	unit_hypotenuse;

	if (ray.x != ceil(ray.x))
		ray.unit = ceil(ray.x) - ray.x;
	else
		ray.unit = 1;
	unit_hypotenuse = ray.unit / ray.cos_angle;
	ray.hypotenuse += unit_hypotenuse;
	ray.y += unit_hypotenuse * ray.sin_angle;
	ray.x += ray.unit;
	return (ray);
}

static t_ray	move_by_y_unit(t_ray ray)
{
	double	unit_hypotenuse;

	if (ray.y != ceil(ray.y))
		ray.unit = ceil(ray.y) - ray.y;
	else
		ray.unit = 1;
	unit_hypotenuse = ray.unit / ray.sin_angle;
    ray.hypotenuse += unit_hypotenuse;
    ray.x += unit_hypotenuse * ray.cos_angle;
    ray.y += ray.unit;
    return (ray);
}

void	caste_90_180_angle_ray(t_game *game, int ray_index, int angle)
{
	t_ray	*ray;
	t_ray	x_unit_ray;
	t_ray	y_unit_ray;

    ray = game->rays[ray_index];
	initiate_ray(game, ray_index, angle);
	while (game->map[(int)floor(ray->y)][(int)floor(ray->x)] != '1')
	{
		if (ray->x == floor(ray->x) && ray->y == floor(ray->y)
		&& game->map[(int)ray->y - 1][(int)ray->x] == '1'
		&& game->map[(int)ray->y][(int)ray->x - 1] == '1')
			break ;
		x_unit_ray = move_by_x_unit(*ray);
		y_unit_ray = move_by_y_unit(*ray);
		if (x_unit_ray.hypotenuse < y_unit_ray.hypotenuse)
			*ray = x_unit_ray;
		else
			*ray = y_unit_ray;
	}
}
