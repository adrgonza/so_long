#include <mlx.h>
#include <unistd.h>
# include <fcntl.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int ft_check_map(char *map)
{
	int fd;
	
	fd = open(map, O_RDONLY);
	if (fd == -1) //check map file exist
		return 0;
	if (".ber") //check if map file type is correct
	return 1;
}

int	main(int argc, char **argv)
{
	if (argc != 2/* || !ft_check_map(argv[1])*/)
		return(write(1, "\033[31mError:\nInvalid Map", 24));
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Midlands v0.1");
	mlx_loop(mlx);
	return 0;
}