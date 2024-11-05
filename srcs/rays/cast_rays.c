#include "cub3d.h"

static void cast_diagonal_ray(t_game *game, int ray_index, int angle)
{
	if (angle > 0 && angle < 90)
		cast_0_90_angle_ray(game, ray_index, angle);
	else if (angle > 90 && angle < 180)
		cast_90_180_angle_ray(game, ray_index, angle);
	else if (angle > 180 && angle < 270)
		cast_180_270_angle_ray(game, ray_index, angle);
	else if (angle > 270 && angle < 360)
		cast_270_360_angle_ray(game, ray_index, angle);
}

static void	cast_ray(t_game *game, int ray_index, int angle)
{
	if (angle % 90 == 0)
		cast_straight_ray(game, ray_index, angle);
	else
		cast_diagonal_ray(game, ray_index, angle);
}

void	cast_rays(t_game *game)
{
	int	angle;
	int	i;

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
		cast_ray(game, i, angle);
		angle++;
		i++;
	}
}
