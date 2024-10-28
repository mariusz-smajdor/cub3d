#include "cub3d.h"

static void caste_diagonal_ray(t_game *game, int ray_index, int angle)
{
	if (angle > 0 && angle < 90)
		caste_0_90_angle_ray(game, ray_index, angle);
	else if (angle > 90 && angle < 180)
		caste_90_180_angle_ray(game, ray_index, angle);
	else if (angle > 180 && angle < 270)
		caste_180_270_angle_ray(game, ray_index, angle);
	else if (angle > 270 && angle < 360)
		caste_270_360_angle_ray(game, ray_index, angle);
}

static void	caste_ray(t_game *game, int ray_index, int angle)
{
	if (angle % 90 == 0)
		caste_straight_ray(game, ray_index, angle);
	else
		caste_diagonal_ray(game, ray_index, angle);
}

void	caste_rays(t_game *game)
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
		caste_ray(game, i, angle);
		game->rays[i]->wall_height = (WIN_HEIGHT / game->rays[i]->hypotenuse);
		angle++;
		i++;
	}
}
