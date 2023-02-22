#include "so_long.h"

int ft_check_items(int fd)
{
	t_map map;
	int i;

	i = 0;
	while (i)
    {
		map.mapita[i] = get_next_line(fd);
		printf("%s", map.mapita[i]);
		i++;
    }
	i = 0;
	while(map.mapita[1][i])
		i++;
	map.map_weight = i;
	i = 0;
	while(map.mapita[i][1])
		i++;
	map.map_height = i;
	return 1;
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
	//if (!ft_check_items(fd))
		//return 0;
	return (1);
}