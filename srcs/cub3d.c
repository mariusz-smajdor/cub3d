#include "cub3d.h"

// Temporary function
// We will init all game properties in the parsing part

static char MAP[6][6] = {
    {'1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', 'P', '0', '1'},
    {'1', '1', '1', '1', '1', '1'}
};

static void	init_game(t_game *game)
{
	game->player = malloc(sizeof(t_player));

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (MAP[i][j] == 'P') {
				game->player->x = j + 0.5;
				game->player->y = i + 0.5;
			}
		}
	}
	game->player->angle = 89;
	/////////////////////
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
	printf("%f\n", calculate_ray_len(&game));
	return (0);
}
