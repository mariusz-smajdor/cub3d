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
    return (ray);
}

// double	calculate_ray_0_90_len(t_game *game)
// {
// 	t_ray	ray;
// 	t_ray	x_unit_ray;
// 	t_ray	y_unit_ray;

// 	initiate_ray(game, &ray);
// 	while (game->map[(int)ceil(ray.y) - 1][(int)floor(ray.x)] != '1')
// 	{
// 		if (ray.x == floor(ray.x) && ray.y == floor(ray.y)
// 		&& game->map[(int)ray.y][(int)ray.x] == '1'
// 		&& game->map[(int)ray.y - 1][(int)ray.x - 1] == '1')
// 			break ;
// 		x_unit_ray = calculate_x_ray(ray);
// 		y_unit_ray = calculate_y_ray(ray);
// 		if (x_unit_ray.hypotenuse < y_unit_ray.hypotenuse)
// 			ray = x_unit_ray;
// 		else
// 			ray = y_unit_ray;
// 	}
// 	return (ray.hypotenuse);
// }

void	caste_0_90_angle_ray(t_game *game, int ray_index, double angle)
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

static void caste_diagonal_ray(t_game *game, int ray_index, double angle)
{
	if (angle > 0 && angle < 90)
		caste_0_90_angle_ray(game, ray_index, angle);
}

static void	caste_ray(t_game *game, int ray_index, double angle)
{
	if (angle == 0 || angle == 90 || angle == 180 || angle == 270)
		caste_straight_ray(game, ray_index, angle);
	else
		caste_diagonal_ray(game, ray_index, angle);
}

void	caste_rays(t_game *game)
{
	int		i;
	double	angle;

	i = 0;
	angle = game->player->angle - FOV / 2;
	if (angle < 0)
		angle = 360 + angle;
	while (i <= FOV)
	{
		if (angle == 360)
			angle = 0;
		game->rays[i] = malloc(sizeof(t_ray));
		game->rays[i]->hypotenuse = 0;
		caste_ray(game, i, angle);

		// Temporary check
		// if (game->rays[i]->wall_side != 0) {
			printf("angle %f: %f\n", angle, game->rays[i]->hypotenuse);
			printf("wall side: %d\n", game->rays[i]->wall_side);
		// }
		i++;
		angle += 1;
	}
}

// static double	calculate_diagonal_ray_len(t_game *game)
// {
// 	// Calculate the length of ray between 0 and 90 degrees
// 	if (game->player->angle > 0 && game->player->angle < 90)
// 		return (calculate_ray_0_90_len(game));
// 	// Calculate the length of ray between 90 and 180 degrees
// 	if (game->player->angle > 90 && game->player->angle < 180)
// 		return (calculate_ray_90_180_len(game));
// 	// Calculate the length of ray between 180 and 270 degrees
// 	if (game->player->angle > 180 && game->player->angle < 270)
// 		return (calculate_ray_180_270_len(game));
// 	// Calculate the length of ray between 270 and 360 degrees
// 	if (game->player->angle > 270 && game->player->angle < 360)
// 		return (calculate_ray_270_360_len(game));
// 	return (0); // Return the length of the ray
// }

// t_ray	*calculate_ray_len(t_game *game)
// {
// 	if (game->player->angle == 0 || game->player->angle == 90
// 		|| game->player->angle == 180 || game->player->angle == 270)
// 		return (calculate_straight_ray_len(game));
// 	return (calculate_diagonal_ray_len(game));
// }
