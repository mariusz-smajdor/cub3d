#include "cub3d.h"

void	initiate_ray(t_game *game, int ray_index, int angle)
{
	t_ray	*ray;

	ray = game->rays[ray_index];
	ray->x = game->player->x;
	ray->y = game->player->y;
	ray->unit = 1;
	ray->hypotenuse = 0;
	while (angle > 90)
		angle -= 90;
	ray->angle_radians = angle * M_PI / 180;
	ray->sin_angle = sin(ray->angle_radians);
	ray->cos_angle = cos(ray->angle_radians);
}
