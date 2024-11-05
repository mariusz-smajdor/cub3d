#include "cub3d.h"

static void	cast_north_ray(t_game *game, int ray_index)
{
	double	*curr_pos;

	game->rays[ray_index]->y = game->player->y;
	curr_pos = &game->rays[ray_index]->y;
	if (*curr_pos != floor(*curr_pos))
	{
		game->rays[ray_index]->hypotenuse += ceil(*curr_pos) - *curr_pos;
		*curr_pos -= *curr_pos - floor(*curr_pos);
	}
	while (game->map[(int)*curr_pos - 1][(int)game->player->x] != '1')
	{
		game->rays[ray_index]->hypotenuse += 1;
		*curr_pos -= 1;
	}
	game->rays[ray_index]->wall_side = WALL_SOUTH;
}

static void	cast_east_ray(t_game *game, int ray_index)
{
	double	*curr_pos;

	game->rays[ray_index]->x = game->player->x;
	curr_pos = &game->rays[ray_index]->x;
	if (*curr_pos != floor(*curr_pos))
	{
		game->rays[ray_index]->hypotenuse += ceil(*curr_pos) - *curr_pos;
		*curr_pos -= *curr_pos - floor(*curr_pos);
	}
	while (game->map[(int)game->player->y][(int)*curr_pos + 1] != '1')
	{
		game->rays[ray_index]->hypotenuse += 1;
		*curr_pos += 1;
	}
	game->rays[ray_index]->wall_side = WALL_WEST;
}

static void	cast_south_ray(t_game *game, int ray_index)
{
	double	*curr_pos;

	game->rays[ray_index]->y = game->player->y;
	curr_pos = &game->rays[ray_index]->y;
	if (*curr_pos != floor(*curr_pos))
	{
		game->rays[ray_index]->hypotenuse += ceil(*curr_pos) - *curr_pos;
		*curr_pos = ceil(*curr_pos);
	}
	while (game->map[(int)*curr_pos][(int)game->player->x] != '1')
	{
		game->rays[ray_index]->hypotenuse += 1;
		*curr_pos += 1;
	}
	game->rays[ray_index]->wall_side = WALL_NORTH;
}

static void	cast_west_ray(t_game *game, int ray_index)
{
	double	*curr_pos;

	game->rays[ray_index]->x = game->player->x;
	curr_pos = &game->rays[ray_index]->x;
	if (*curr_pos != floor(*curr_pos))
	{
		game->rays[ray_index]->hypotenuse += *curr_pos - floor(*curr_pos);
		*curr_pos = floor(*curr_pos);
	}
	while (game->map[(int)game->player->y][(int)*curr_pos - 1] != '1')
	{
		game->rays[ray_index]->hypotenuse += 1;
		*curr_pos -= 1;
	}
	game->rays[ray_index]->wall_side = WALL_EAST;
}

void	cast_straight_ray(t_game *game, int ray_index, int angle)
{
	if (angle == 0)
		cast_north_ray(game, ray_index);
	else if (angle == 90)
		cast_east_ray(game, ray_index);
	else if (angle == 180)
		cast_south_ray(game, ray_index);
	else if (angle == 270)
		cast_west_ray(game, ray_index);
}
