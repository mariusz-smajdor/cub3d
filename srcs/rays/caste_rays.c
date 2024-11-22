/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caste_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:57:42 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/20 19:06:16 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_wall_data(t_ray *ray)
{
	double	wall_height;

	wall_height = (double)WIN_HEIGHT / ray->hypotenuse;
	if (wall_height > WIN_HEIGHT)
		wall_height = WIN_HEIGHT;
	ray->wall_start = ((double)WIN_HEIGHT - wall_height) / 2;
	ray->wall_end = (double)WIN_HEIGHT - ray->wall_start;
}

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
	add_wall_data(game->rays[ray_index]);
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
		angle++;
		i++;
	}
}
