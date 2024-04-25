#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}



int	key_press(int key, t_game *game)
{
    (void)game;
    printf("%d\n", key);
	if (key == K_ESC)
		exit(0);
	// if (key == K_W)
		
	// if (key == K_S)
		
	// if (key == K_A)
		
	// if (key == K_D)
		
	return (0);
}

void    starting_screen(t_game *game)
{
    void *intro;
    int wt;

    intro = mlx_xpm_file_to_image(game->mlx, "textures/intro.xpm", &wt, &wt);
    mlx_put_image_to_window(game->mlx, game->mlx_win, intro, 0, 0);
}

int	game_loop(t_game	*game)
{
    starting_screen(game);
	return (0);
}

void    init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->mlx_win = mlx_new_window(game->mlx, 1024, 1024, "Mland");
    mlx_hook(game->mlx_win, 2, 1L << 0, key_press, &game);
    //mlx_key_hook(game->win, key_released, &game);
    mlx_loop_hook(game->mlx, game_loop, &game);
    mlx_hook(game->mlx_win, 17, 0, exit_game, &game);
    mlx_loop(game->mlx);
}