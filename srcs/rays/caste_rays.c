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
	int		i;
	int		angle;

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
			printf("angle %d: %f\n", angle, game->rays[i]->hypotenuse);
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
