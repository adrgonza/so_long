#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
#include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806L
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct	map {
	char **mapita;
	int map_height;
	int map_weight;
}				t_map;

typedef struct	game {
	
	void	*mlx;
	void	*window;
	int 	image_size;
	void 	*floor;
	void 	*exit;
	void 	*player;
	void 	*wall;
	void 	*collect;
}				t_game;

int	main(int argc, char **argv);
char	*get_next_line(int fd);
int ft_check_file(char *file_name, t_map *map);

#endif
