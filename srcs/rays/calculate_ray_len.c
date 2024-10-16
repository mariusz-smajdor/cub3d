#include "cub3d.h"

static double	calculate_diagonal_ray_len(t_game *game)
{
	// Calculate the length of ray between 0 and 90 degrees
	if (game->player->angle > 0 && game->player->angle < 90)
		return (calculate_ray_0_90_len(game));
	// Calculate the length of ray between 90 and 180 degrees
	if (game->player->angle > 90 && game->player->angle < 180)
		return (calculate_ray_90_180_len(game));
	// Calculate the length of ray between 180 and 270 degrees
	if (game->player->angle > 180 && game->player->angle < 270)
		return (calculate_ray_180_270_len(game));
	// Calculate the length of ray between 270 and 360 degrees
	if (game->player->angle > 270 && game->player->angle < 360)
		return (calculate_ray_270_360_len(game));
	return (0); // Return the length of the ray
}

double	calculate_ray_len(t_game *game)
{
	if (game->player->angle == 0 || game->player->angle == 90
		|| game->player->angle == 180 || game->player->angle == 270)
		return (calculate_straight_ray_len(game));
	return (calculate_diagonal_ray_len(game));
}
