#include "cub3d.h"

// Temporary function
// We will init all game properties in the parsing part

static char MAP[6][6] = {
    {'1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', 'P', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1'}
};

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 500, 500, "Cub3D");
	game->player = malloc(sizeof(t_player));

	// To change / remove
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (MAP[i][j] == 'P') {
				game->player->x = j + 0.5;
				game->player->y = i + 0.5;
			}
		}
	}
	game->player->angle = 0;
	game->map = malloc(sizeof(char *) * 6);
	for (int i = 0; i < 6; i++) {
		game->map[i] = malloc(sizeof(char) * 6);
		for (int j = 0; j < 6; j++) {
			game->map[i][j] = MAP[i][j];
		}
	}
}

int	main()
{
	t_game game;

	init_game(&game);
	// calculate length of all rays
	int i;

	i = 0;
	while (i < FOV)
	{
		game.walls[i] = calculate_ray_len(&game);
		game.player->angle += 1;
		if (game.player->angle == 360)
			game.player->angle = 0;
		i++;
	}

	// print all rays (for debug)

	for (int i = 0; i < FOV; i++)
	{
		printf("angle %f: %f\n", game.player->angle, game.walls[i]);
	}

	// printf("%f\n", calculate_ray_len(&game));
	return (0);
}
