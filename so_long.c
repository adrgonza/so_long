#include "so_long.h"
int  ft_image_map(t_map *map, t_game *game)
{
	int i;
	int j;
	int k;
	int l;

	i = 1;
	k = 0;
	while(k++ < map->map_height) //fill window with floor
	{
		j = 1;
		l = -1;
		while(l++ <= map->map_weight)
		{
			if(map->mapita[k][l] == '0' || map->mapita[k][l] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->floor, j, i);
			if(map->mapita[k][l] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, j, i);
			if(map->mapita[k][l] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->player, j, i);
			if(map->mapita[k][l] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collect, j, i);
			if(map->mapita[k][l] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, j, i);
			j += 32;
		}
		i += 32;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map map; 

	if (argc != 2 || !ft_check_file(argv[1], &map)) //check map
		return(write(1, "\033[31mError:\nInvalid Map", 24)); 
	game.mlx = mlx_init(); //start minilib
	game.window = mlx_new_window(game.mlx, (map.map_weight * 32), (map.map_height * 32), "Midlands v0.1"); //create window
	game.floor = mlx_xpm_file_to_image(game.mlx, "textures/floor.xpm", &game.image_size, &game.image_size);
	game.exit = mlx_xpm_file_to_image(game.mlx, "textures/exit.xpm", &game.image_size, &game.image_size);
	game.player = mlx_xpm_file_to_image(game.mlx, "textures/player.xpm", &game.image_size, &game.image_size);
	game.collect = mlx_xpm_file_to_image(game.mlx, "textures/collect.xpm", &game.image_size, &game.image_size);
	game.wall = mlx_xpm_file_to_image(game.mlx, "textures/wall.xpm", &game.image_size, &game.image_size);
	ft_image_map(&map, &game);
	mlx_loop(game.mlx);

}





//0,1,p,c,e








/*

	int i;
	int j;
	int k;
	int l;

	i = 1;
	k = 0;
	l = 0;
	while(k < 20) //fill window with floor
	{
		j = 1;
		while(l < 20)
		{
			mlx_put_image_to_window(game.mlx, game.window, game.floor, j, i);
			j += 32;
			l++;
		}
		l = 0;
		i += 32;
		k++;
	}*/