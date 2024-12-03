/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:40:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/12/03 14:01:44 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move(t_data *data, int keycode)
{
	t_player	*player;
	short		direction;
	double		step_x;
	double		step_y;

	player = data->player;
	direction = 1;
	if (keycode == S_KEY || keycode == A_KEY)
		direction = -1;
	step_x = player->dir_x * MOVE_SPEED * direction;
	step_y = player->dir_y * MOVE_SPEED * direction;
	if (keycode == A_KEY || keycode == D_KEY)
	{
		step_x = player->plane_x * MOVE_SPEED * direction;
		step_y = player->plane_y * MOVE_SPEED * direction;
	}
	if (data->map[(int)player->pos_y][(int)(player->pos_x + step_x * 3)] != '1')
		player->pos_x += step_x;
	if (data->map[(int)(player->pos_y + step_y * 3)][(int)player->pos_x] != '1')
		player->pos_y += step_y;
}

static void	rotate(t_player *player, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	if (keycode == LEFT_KEY)
		angle = -ROTATE_SPEED;
	else if (keycode == RIGHT_KEY)
		angle = ROTATE_SPEED;
	else if (keycode == MOUSE_LEFT)
		angle = -ROTATE_SPEED / 2;
	else if (keycode == MOUSE_RIGHT)
		angle = ROTATE_SPEED / 2;
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(angle)
		- player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle)
		+ player->dir_y * cos(angle);
	player->plane_x = player->plane_x * cos(angle)
		- player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle)
		+ player->plane_y * cos(angle);
}

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	free_map(data->map);
	exit(0);
}

int	handle_mouse_events(int x, int y, t_data *data)
{
	t_player	*player;
	t_wall		*wall;

	player = data->player;
	wall = data->wall;
	if (wall->side == 'N' || wall->side == 'S')
	{
		if (x > WIN_WIDTH * 0.8)
			rotate(player, MOUSE_RIGHT);
		else if (x < WIN_WIDTH * 0.2)
			rotate(player, MOUSE_LEFT);
	}
	else
	{
		if (x > (WIN_WIDTH * 0.8))
			rotate(player, MOUSE_RIGHT);
		else if (x < WIN_WIDTH * 0.2)
			rotate(player, MOUSE_LEFT);
	}
	return (y);
}

int	handle_key_events(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_game(data);
	else if (keycode == W_KEY
		|| keycode == S_KEY
		|| keycode == A_KEY
		|| keycode == D_KEY)
		move(data, keycode);
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		rotate(data->player, keycode);
	return (0);
}
