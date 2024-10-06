#include "cub3d.h"

void	initiate_ray(t_game *game, t_ray *ray)
{
	ray->x = game->player->x;
	ray->y = game->player->y;
	ray->unit = 1;
	ray->hypotenuse = 0;
	ray->angle_radians = game->player->angle * M_PI / 180;
	ray->sin_angle = sin(ray->angle_radians);
	ray->cos_angle = cos(ray->angle_radians);
}
