/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:46:30 by mwiacek           #+#    #+#             */
/*   Updated: 2024/10/03 13:09:42 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_txt(t_game *game, t_txt *txt)
{
	if (txt->NO)
		mlx_destroy_image(game->mlx, txt->NO);
	if (txt->SO)
		mlx_destroy_image(game->mlx, txt->SO);
	if (txt->WE)
		mlx_destroy_image(game->mlx, txt->WE);
	if (txt->EA)
		mlx_destroy_image(game->mlx, txt->EA);
	free(txt);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i++])
		free(arr[i]);
	free(arr);
}
