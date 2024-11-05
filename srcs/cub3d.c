#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game game;
	// t_img	img;

	if (ac != 2)
		print_error("Wrong amount of arguments\n");
	init_game(&game, av[1]);
	cast_rays(&game);
	debug_map(game);
	debug_player(*game.player);
	debug_rays(game.rays);
	
	return (0);
}
