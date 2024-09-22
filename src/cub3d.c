#include "cub3d.h"

// Temporary function
// We will init player position and direction in parsing
static void	init_player(t_player *player)
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == 'P') {
				player->x = j + 0.5;
				player->y = i + 0.5;
			}
		}
	}
	player->angle = 0;
}

int	main()
{
	printf("%s\n", MAP[0]);
	return (0);
}
