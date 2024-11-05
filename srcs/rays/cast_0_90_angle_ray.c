#include "cub3d.h"

static t_ray	move_by_x_unit(t_ray ray)
{
	double	unit_hypotenuse;

	if (ray.x != ceil(ray.x))
		ray.unit = ceil(ray.x) - ray.x;
	else
		ray.unit = 1;
	unit_hypotenuse = ray.unit / ray.sin_angle;
	ray.hypotenuse += unit_hypotenuse;
	ray.y -= unit_hypotenuse * ray.cos_angle;
	ray.x += ray.unit;
	ray.wall_side = WALL_WEST;
	return (ray);
}

static t_ray	move_by_y_unit(t_ray ray)
{
	double	unit_hypotenuse;

	if (ray.y != floor(ray.y))
		ray.unit = ray.y - floor(ray.y);
	else
		ray.unit = 1;
	unit_hypotenuse = ray.unit / ray.cos_angle;
    ray.hypotenuse += unit_hypotenuse;
    ray.x += unit_hypotenuse * ray.sin_angle;
    ray.y -= ray.unit;
	ray.wall_side = WALL_SOUTH;
    return (ray);
}

void	cast_0_90_angle_ray(t_game *game, int ray_index, int angle)
{
	t_ray	*ray;
	t_ray	x_unit_ray;
	t_ray	y_unit_ray;

	ray = game->rays[ray_index];
	initiate_ray(game, ray_index, angle);
	while (game->map[(int)ceil(ray->y) - 1][(int)floor(ray->x)] != '1')
	{
		if (ray->x == floor(ray->x) && ray->y == floor(ray->y)
		&& game->map[(int)ray->y][(int)ray->x] == '1'
		&& game->map[(int)ray->y - 1][(int)ray->x - 1] == '1')
			break ;
		x_unit_ray = move_by_x_unit(*ray);
		y_unit_ray = move_by_y_unit(*ray);
		if (x_unit_ray.hypotenuse < y_unit_ray.hypotenuse)
			*ray = x_unit_ray;
		else
			*ray = y_unit_ray;
	}
}