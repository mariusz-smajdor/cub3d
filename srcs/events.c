/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:09:24 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/11 15:59:27 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_angle(t_game *game, int angle)
{
	game->player->angle += angle;
	if (game->player->angle > 359)
		game->player->angle = 0;
	if (game->player->angle < 0)
		game->player->angle = 359;
}

static void	move_player(t_game *game, double x_offset, double y_offset)
{
	double	angle;
	
	angle = game->player->angle;
	if (angle > 180 && angle < 360)
		x_offset *= -1;	
	if (angle < 90 || angle > 270)
		y_offset *= -1;
	if (angle == 180)
		angle = 0;
	while (angle > 90)
		angle -= 90;
	game->player->x += x_offset * sin(angle * M_PI / 180);
	game->player->y += y_offset * cos(angle * M_PI / 180);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game closed\n");
	exit(0);
}

void render(t_game *game)
{
	int x = 0;
	int i = 0;
	int ray_width = WIN_WIDTH / 100;

	mlx_clear_window(game->mlx, game->win);

	while (i < 100)
	{
		for (double y = game->rays[i]->wall_start; y <= game->rays[i]->wall_end; y += 1) {
			for (int w = 0; w < ray_width; w++) {
				mlx_pixel_put(game->mlx, game->win, x + w, y, 0xFFFFFF);
			}
		}
		x += ray_width;
		i++;
	}
}
int	handle_key_events(int keycode, t_game *game)
{
	if (keycode == 97)
		change_angle(game, -3);
	if (keycode == 100)
		change_angle(game, 3);
	if (keycode == 115)
		move_player(game, -STEP, -STEP);
	if (keycode == 119)
		move_player(game, STEP, STEP);
	caste_rays(game);
	render(game);
	return (0);
}