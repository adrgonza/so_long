#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int ft_check_items(int fd)
{
	char **map;
	int i;

	i = 0;
	while (fd)
    {
		map[i] = get_next_line(fd);
		printf("%s", map[i]);
		i++;
    }
}


int ft_check_map(char *file_name)
{
	int i;
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		return 0;
	i = 0;
	while (file_name[i])
		i++;
	if(file_name[--i] != 'r')
		return 0;
	if(file_name[--i] != 'e')
		return 0;
	if(file_name[--i] != 'b')
		return 0;
	if(file_name[--i] != '.')
		return 0;
	ft_check_items(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc != 2 || !ft_check_map(argv[1]))
		return(write(1, "\033[31mError:\nInvalid Map", 24));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Midlands v0.1");
	mlx_loop(mlx);
}