/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:09:24 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/09 22:12:25 by msmajdor         ###   ########.fr       */
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
	printf("Player angle: %d\n", game->player->angle);
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
	printf("Player position: x: %f y: %f\n", game->player->x, game->player->y);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game closed\n");
	exit(0);
}

int	handle_key_events(int keycode, t_game *game)
{
	printf("%d\n", keycode);
	if (keycode == 97)
		change_angle(game, -1);
	if (keycode == 100)
		change_angle(game, 1);
	if (keycode == 115) // s
		move_player(game, -STEP, -STEP);
	if (keycode == 119)
		move_player(game, STEP, STEP);
	caste_rays(game);
	// int i = 0;
	// while (game->rays[i]) {
	// 	printf("Ray %d %f %f\n", game->player->angle - 50 + i, game->rays[i]->hypotenuse, game->rays[i]->wall_height);
	// 	i++;
	// }
	return (0);
}
