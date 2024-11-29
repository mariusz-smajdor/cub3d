/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:04:16 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/29 14:37:59 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	close_game(t_data *data)
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

static int	handle_key_events(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_game(data);
	else if (keycode == W
		|| keycode == S
		|| keycode == A
		|| keycode == D)
		move(data, keycode);
	return (0);
}

void init_image(t_image *image, void *mlx)
{
    image->ptr = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
    image->addr = mlx_get_data_addr(image->ptr,
                                    &image->bits_per_pixel,
                                    &image->line_length,
                                    &image->endian);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_image(data->image, data->mlx);
	mlx_loop_hook(data->mlx, render, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key_events, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, close_game, data);
	mlx_loop(data->mlx);
}
