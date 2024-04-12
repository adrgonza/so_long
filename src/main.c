#include "so_long.h"

int	main(int argc, char **argv)
{
    t_map map;
    //t_game game;

    if (argc != 2 || !parse_all(argv[1], &map))
		return (1);
    printf("works\n");
}