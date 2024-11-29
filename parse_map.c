/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:08:55 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/29 13:49:24 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_data(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			if (data->map[y][x] == 'P')
			{
				data->player->pos_x = x + 0.5;
				data->player->pos_y = y + 0.5;
			}
			x++;
		}
		y++;
	}	
	data->player->plane_x = -0.66;
	data->player->plane_y = 0;

	// N
	// data->player->dir_x = 0;
	// data->player->dir_y = -1;
	// S
	data->player->dir_x = 0;
	data->player->dir_y = 1;
	// W
	// data->player->dir_x = -1;
	// data->player->dir_y = 0;
	// E
	// data->player->dir_x = 1;
	// data->player->dir_y = 0;
}

void	parse_map(t_data *data)
{	
	data->player = malloc(sizeof(t_player));
	data->ray = malloc(sizeof(t_ray));
	data->wall = malloc(sizeof(t_wall));
	data->image = malloc(sizeof(t_image));
	data->map = malloc(sizeof(char *) * 7);
	data->map[0] = ft_strdup("111111");
	data->map[1] = ft_strdup("100001");
	data->map[2] = ft_strdup("100P01");
	data->map[3] = ft_strdup("100001");
	data->map[4] = ft_strdup("100001");
	data->map[5] = ft_strdup("111111");
	data->map[6] = NULL;
	init_player_data(data);
}
