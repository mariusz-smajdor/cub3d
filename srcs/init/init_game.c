/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:32:40 by mwiacek           #+#    #+#             */
/*   Updated: 2024/11/05 22:16:25 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_game(t_game *game, char *map_path)
{
	game->mlx = mlx_init();
	parse_map(game, map_path);
	
	game->player = malloc(sizeof(t_player));
	game->rays = malloc(sizeof(t_ray) * FOV);
	// temporary player angle to for testing, later read it from the map
	game->player->angle = 0;
	// To change / remove
	for (int i = 0; game->map[i]; i++) {
		for (int j = 0; game->map[i][j]; j++) {
			if (game->map[i][j] == 'N') {
				game->player->x = j + 0.5;
				game->player->y = i + 0.5;
			}
		}
	}
}
