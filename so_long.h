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

int	main(int argc, char **argv);
char	*get_next_line(int fd);
int ft_check_map(char *file_name);

#endif
