#include "cub3d.h"

// Temporary function
// We will init all game properties in the parsing part

static char MAP[6][6] = {
    {'1', '1', '1', '1', '1', '1'},
    {'1', '0', 'P', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1'}
};

static void	init_game(t_game *game)
{


	game->player = malloc(sizeof(t_player));
	game->rays = malloc(sizeof(t_ray) * FOV);
	// temporary player angle to for testing, later read it from the map
	game->player->angle = 0;

	// To change / remove
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (MAP[i][j] == 'P') {
				game->player->x = j + 0.5;
				game->player->y = i + 0.5;
			}
		}
	}
	game->map = malloc(sizeof(char *) * 6);
	for (int i = 0; i < 6; i++) {
		game->map[i] = malloc(sizeof(char) * 6);
		for (int j = 0; j < 6; j++) {
			game->map[i][j] = MAP[i][j];
		}
	}

}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game closed\n");
	exit(0);
}

void change_angle(t_game *game, int angle)
{
	game->player->angle += angle;
	if (game->player->angle > 359)
		game->player->angle = 0;
	if (game->player->angle < 0)
		game->player->angle = 359;
}

int handle_key_events(int keycode, t_game *game)
{
	// printf("%d\n", keycode);
	if (keycode == 97)
		change_angle(game, -1);
	if (keycode == 100)
		change_angle(game, 1);
	caste_rays(game);
	int i = 0;
	while (game->rays[i]) {
		printf("Ray %d %f %f\n", game->player->angle - 50 + i, game->rays[i]->hypotenuse, game->rays[i]->wall_height);
		i++;
	}
	return (0);
}

int	main()
{
	t_game game;

	init_game(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	mlx_hook(game.win, 17, 0, close_game, &game);
	caste_rays(&game);
	mlx_loop(game.mlx);
	return (0);
}
