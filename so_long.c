#include "so_long.h"

int ft_free_map(t_map *map, t_game *game, int x)
{
	int i;

	if(x == 0)
		write(1, "\033[31mError:\nInvalid Map", 23);
	else
		mlx_destroy_window(game->mlx, game->window);
	i = 0;
	while(i < map->map_height)
		free(map->mapita[i++]);
	free(map->mapita);
	return (0);
}

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
		while(j < map->map_weight - 1)// hacer check que la imagen existe
		{
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
	return(1);
}

int ft_move_check(t_map *map, int y, int x)
{
	if(map->mapita[y][x] == '1')
		return(0);
	if(map->mapita[y][x] == 'C')
		map->c_count--;
	if(map->mapita[map->player_y][map->player_x] == 'E')
	{
		if(map->c_count > 0)
			return(0);
		else
			printf("\n\nhols\n");//salir del programa.
	}
	return (1);
}

int ft_movement(int key,t_game *game)
{
	int x;
	int y;

	x = game->map_data->player_x;
	y = game->map_data->player_y;
	if(key == 53) //esc
		return (0);
	if(key == 13 && ft_move_check(game->map_data, y - 1, x)) //up
		game->map_data->player_y--;
	if(key == 1 && ft_move_check(game->map_data, y + 1, x)) //down
		game->map_data->player_y++;
	if(key == 0 && ft_move_check(game->map_data, y, x - 1)) //left
		game->map_data->player_x--;
	if(key == 2 && ft_move_check(game->map_data, y, x + 1)) //right
		game->map_data->player_x++;
	if (key != 13 && key != 1 && key != 0 && key != 2)
		return (1);
	game->map_data->mapita[game->map_data->player_y][game->map_data->player_x] = 'P';
	game->map_data->mapita[y][x] = '0';
	ft_image_map(game->map_data, game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map map; 

	game.map_data = &map;
	if (argc != 2 || !ft_check_file(argv[1], &map))
		return(ft_free_map(&map, &game, 0));
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, ((map.map_weight - 1) * 32), (map.map_height * 32), "Midlands v0.3"); //create windows
	game.floor = mlx_xpm_file_to_image(game.mlx, "textures/floor.xpm", &game.image_size, &game.image_size);
	game.exit = mlx_xpm_file_to_image(game.mlx, "textures/exit.xpm", &game.image_size, &game.image_size);
	game.player = mlx_xpm_file_to_image(game.mlx, "textures/player.xpm", &game.image_size, &game.image_size);
	game.collect = mlx_xpm_file_to_image(game.mlx, "textures/collect.xpm", &game.image_size, &game.image_size);
	game.wall = mlx_xpm_file_to_image(game.mlx, "textures/wall.xpm", &game.image_size, &game.image_size);
	ft_image_map(&map, &game);
	mlx_key_hook(game.window, ft_movement, &game);
	mlx_loop(game.mlx);
}
