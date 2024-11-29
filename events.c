/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:40:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/29 15:32:52 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	free_map(data->map);
	exit(0);
}

void	move(t_data *data, int keycode)
{
	t_player	*player;
	short		direction;
	double		step_x;
	double		step_y;

	player = data->player;
	direction = 1;
	if (keycode == S || keycode == A)
		direction = -1;
	step_x = player->dir_x * MOVE_SPEED * direction;
	step_y = player->dir_y * MOVE_SPEED * direction;
	if (keycode == A || keycode == D)
	{
		step_x = player->plane_x * MOVE_SPEED * direction;
		step_y = player->plane_y * MOVE_SPEED * direction;
	}
	if (data->map[(int)player->pos_y][(int)(player->pos_x + step_x)] != '1')
		player->pos_x += step_x;
	if (data->map[(int)(player->pos_y + step_y)][(int)player->pos_x] != '1')
		player->pos_y += step_y;
}

int	handle_key_events(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_game(data);
	else if (keycode == W
		|| keycode == S
		|| keycode == A
		|| keycode == D)
		move(data, keycode);
	printf("keycode: %d\n", keycode);
	return (0);
}