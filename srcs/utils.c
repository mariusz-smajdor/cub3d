#include "cub3d.h"

void	initiate_ray(t_game *game, t_ray *ray)
{
	ray->x = game->player->x;
	ray->y = game->player->y;
	ray->unit = 1;
	ray->hypotenuse = 0;
}
