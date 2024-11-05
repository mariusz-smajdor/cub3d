#include "../../includes/cub3d.h"

void	debug_rays(t_ray **rays)
{
	printf("\033[1;31m[DEBUG] RAYS [DEBUG]\n\033[0m");
	for (int i = 0; i < 101; i++)
		printf("Ray[%d] = %f\n", i, rays[i]->hypotenuse);
}

void	debug_player(t_player player)
{
	printf("\033[1;31m[DEBUG] PLAYER [DEBUG]\n\033[0m");
	printf("Pos-x: %f\n", player.x);
	printf("Pos-y: %f\n", player.y);
}

void	debug_map(t_game game)
{
	printf("\033[1;31m[DEBUG] TEXTURES [DEBUG]\n\033[0m");
	printf("EA: %d\n", *(game.txt->EA->addr));
	printf("WE: %d\n", *(game.txt->WE->addr));
	printf("NO: %d\n", *(game.txt->NO->addr));
	printf("SO: %d\n", *(game.txt->SO->addr));
	printf("\033[1;31m[DEBUG] COLORS [DEBUG]\n\033[0m");
	printf("C: %d\n", game.txt->C);
	printf("F: %d\n", game.txt->F);
	printf("\033[1;31m[DEBUG] MAP [DEBUG]\n\033[0m");
	for (int i = 0; game.map[i]; i++)
		printf("%s\n", game.map[i]);
}