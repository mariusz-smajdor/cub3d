// #include "cub3d.h"

// static void calculate_north_ray_len(t_game *game, double *ray_len, double *curr_pos)
// {
// 	*curr_pos = game->player->y;
// 	if (*curr_pos != floor(*curr_pos))
// 	{
// 		*ray_len += ceil(*curr_pos) - *curr_pos;
// 		*curr_pos -= *curr_pos - floor(*curr_pos);
// 	}
// 	while (game->map[(int)*curr_pos - 1][(int)game->player->x] != '1')
// 	{
// 		*ray_len += 1;
// 		*curr_pos -= 1;
// 	}
// }

// static void calculate_east_ray_len(t_game *game, double *ray_len, double *curr_pos)
// {
// 	*curr_pos = game->player->x;
// 	if (*curr_pos != floor(*curr_pos))
// 	{
// 		*ray_len += ceil(*curr_pos) - *curr_pos;
// 		*curr_pos -= *curr_pos - floor(*curr_pos);
// 	}
// 	while (game->map[(int)game->player->y][(int)*curr_pos + 1] != '1')
// 	{
// 		*ray_len += 1;
// 		*curr_pos += 1;
// 	}
// }

// static void calculate_south_ray_len(t_game *game, double *ray_len, double *curr_pos)
// {
// 	*curr_pos = game->player->y;
// 	if (*curr_pos != floor(*curr_pos))
// 	{
// 		*ray_len += ceil(*curr_pos) - *curr_pos;
// 		*curr_pos = ceil(*curr_pos);
// 	}
// 	while (game->map[(int)*curr_pos][(int)game->player->x] != '1')
// 	{
// 		*ray_len += 1;
// 		*curr_pos += 1;
// 	}
// }

// static void calculate_west_ray_len(t_game *game, double *ray_len, double *curr_pos)
// {
// 	*curr_pos = game->player->x;
// 	if (*curr_pos != floor(*curr_pos))
// 	{
// 		*ray_len += *curr_pos - floor(*curr_pos);
// 		*curr_pos = floor(*curr_pos);
// 	}
// 	while (game->map[(int)game->player->y][(int)*curr_pos - 1] != '1')
// 	{
// 		*ray_len += 1;
// 		*curr_pos -= 1;
// 	}
// }

// double	calculate_straight_ray_len(t_game *game)
// {
// 	double	curr_pos;
// 	double	ray_len;

// 	ray_len = 0;
// 	if (game->player->angle == 0)
// 		calculate_north_ray_len(game, &ray_len, &curr_pos);
// 	else if (game->player->angle == 90)
// 		calculate_east_ray_len(game, &ray_len, &curr_pos);
// 	else if (game->player->angle == 180)
// 		calculate_south_ray_len(game, &ray_len, &curr_pos);
// 	else if (game->player->angle == 270)
// 		calculate_west_ray_len(game, &ray_len, &curr_pos);
// 	return (ray_len);
// }
