#include "so_long.h"
int  ft_image_map(t_map *map, t_game *game)
{
	int i = 0;
	int j = 0;
	int k = 1;
	int l = 1;

	while(i < map->map_height)
	{
		j = 0;
		k = 1;
		while(j < map->map_weight - 1)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->floor, k, l);
			if(map->mapita[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->floor, k, l);
			if(map->mapita[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, k, l);
			if(map->mapita[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->player, k, l);
			if(map->mapita[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collect, k, l);
			if(map->mapita[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, k, l);
			k += 32;
			j++;
		}
		l += 32;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map map; 

	if (argc != 2 || !ft_check_file(argv[1], &map)) //check map
		return(write(1, "\033[31mError:\nInvalid Map", 23)); 
	game.mlx = mlx_init(); //start minilib
	game.window = mlx_new_window(game.mlx, ((map.map_weight - 1) * 32), (map.map_height * 32), "Midlands v0.2"); //create window
	game.floor = mlx_xpm_file_to_image(game.mlx, "textures/floor.xpm", &game.image_size, &game.image_size);
	game.exit = mlx_xpm_file_to_image(game.mlx, "textures/exit.xpm", &game.image_size, &game.image_size);
	game.player = mlx_xpm_file_to_image(game.mlx, "textures/player.xpm", &game.image_size, &game.image_size);
	game.collect = mlx_xpm_file_to_image(game.mlx, "textures/collect.xpm", &game.image_size, &game.image_size);
	game.wall = mlx_xpm_file_to_image(game.mlx, "textures/wall.xpm", &game.image_size, &game.image_size);
	ft_image_map(&map, &game);
	mlx_loop(game.mlx);

}