#include "so_long.h"

int ft_check_items(t_map *map)
{
	int i;

	i = 1;
	while (map->mapita[1][i] == '1')
		i++;
	if(map->mapita[1][++i] != 0)
		return 0;
	i = 1;
	while (map->mapita[map->map_height][i] == '1')
		i++;
	if(map->mapita[map->map_height][++i] != 0)
		return 0;
	return (1);
}

int ft_read_map(int fd,char *file_name, t_map *map)
{
	int i;

	i = 0;
	while (get_next_line(fd))//check map lines for size of char **
		i++;
	map->map_height = i; //giving height map value
	fd = open(file_name, O_RDONLY);// reopen file
	map->mapita = malloc(sizeof(char *) * i); //allocate memory for map
	i = 0;
	while (i++ <= map->map_height) //putting map on map variable
		map->mapita[i] = get_next_line(fd);
	i = 0;
	while (map->mapita[1][++i]); //checking weight
	map->map_weight = i - 1; // giving weight map value
	if (!ft_check_items(map))
		return 0;
	return 1;
}
//ptr a mapa = malloc(sizeof(t_map))

int ft_check_file(char *file_name, t_map *map)
{
	int i;
	int fd;

	fd = open(file_name, O_RDONLY);//open file
	if (fd < 1) //check map exist
		return 0;
	i = 0;
	while (file_name[i])//check map file is .ber
		i++;
	if(file_name[--i] != 'r')
		return 0;
	if(file_name[--i] != 'e')
		return 0;
	if(file_name[--i] != 'b')
		return 0;
	if(file_name[--i] != '.')
		return 0;
	if (!ft_read_map(fd, file_name, map))
		return 0;
	return (1);
}