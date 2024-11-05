/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:46:50 by mwiacek           #+#    #+#             */
/*   Updated: 2024/11/05 21:25:08 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*xpm_to_img(t_game *game, char *path)
{
	t_img	*img;
	int		fd;
	int		x;
	int		y;

	img = malloc(sizeof(t_img));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Wrong texture path\n");
	close (fd);
	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&x, &y);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	return (img);
}

static int	rgb_to_hex(char *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(color);
	color = ft_strchr(color, ',') + 1;
	g = ft_atoi(color);
	color = ft_strchr(color, ',') + 1;
	b = ft_atoi(color);
	return ((r << 16) | (g << 8) | b);
}

bool	validate_texture(t_txt *txt, char *s)
{
	if (!ft_strncmp(s, "NO", len_to_space(s)) && !txt->NO)
		return (true);
	else if (!ft_strncmp(s, "SO", len_to_space(s)) && !txt->SO)
		return (true);
	else if (!ft_strncmp(s, "WE", len_to_space(s)) && !txt->WE)
		return (true);
	else if (!ft_strncmp(s, "EA", len_to_space(s)) && !txt->EA)
		return (true);
	else if (!ft_strncmp(s, "F", len_to_space(s)) && !txt->F)
		return (true);
	else if (!ft_strncmp(s, "C", len_to_space(s)) && !txt->C)
		return (true);
	return (false);
}

void	parse_texture(t_game *game, t_txt *txt, char *s)
{
	if (!ft_strncmp(s, "NO", len_to_space(s)))
	{
		txt->NO = xpm_to_img(game, s + 3);
		return ;
	}
	else if (!ft_strncmp(s, "SO", len_to_space(s)))
		txt->SO = xpm_to_img(game, s + 3);
	else if (!ft_strncmp(s, "WE", len_to_space(s)))
		txt->WE = xpm_to_img(game, s + 3);
	else if (!ft_strncmp(s, "EA", len_to_space(s)))
		txt->EA = xpm_to_img(game, s + 3);
	else if (!ft_strncmp(s, "F", len_to_space(s)))
		txt->F = rgb_to_hex(s + 2);
	else if (!ft_strncmp(s, "C", len_to_space(s)))
		txt->C = rgb_to_hex(s + 2);
}

t_txt	*parse_textures(t_game *game, char **map, int *i)
{
	t_txt	*txt;
	char	*tmp;
	int		txt_count;

	txt = malloc(sizeof(t_txt));
	txt_count = 0;
	while (txt_count < 6)
	{
		tmp = fix_spaces(map[*i]);
		if (tmp[0] != '\n' && validate_texture(txt, tmp))
		{
			parse_texture(game, txt, tmp);
			txt_count++;
		}
		else if (tmp[0] != '\n')
			return (NULL);
		free(tmp);
		++(*i);
	}
	return (txt);
}
