#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	

	if (argc != 2 || !ft_check_map(argv[1]))
		return(write(1, "\033[31mError:\nInvalid Map", 24)); 
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 400, 400, "Midlands v0.1");
	game.floor = mlx_xpm_file_to_image(game.mlx, "./textures/floor.xpm", &game.image_size, &game.image_size);
	mlx_put_image_to_window(game.mlx, game.window, game.floor, 31, 1);
	mlx_loop(game.mlx);
}
