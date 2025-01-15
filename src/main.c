#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map map;
	t_game game;

	ft_bzero(&map, sizeof(map));
	if (argc != 2 || !parse_all(argv[1], &map))
	{
		ft_printf("There is a problem in the map\n");
		return (1);
	}
	ft_bzero(&game, sizeof(game));
	game.map = &map;
	init_game(&game);
	return (0);
}