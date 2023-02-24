#include "so_long.h"

int ft_check_played(t_map *map)
{
	return (1);
}

int ft_check_items(t_map *map) // check if it has only 1 p e
{
	char m;
	int i;
	int j;
	int p;
	int c;
	int e;
	
	p = 0;
	c = 0;
	e = 0;
	i = -1;
	while (++i < map->map_height)
	{
		j = 0;
		while (j < map->map_weight - 1)
		{
			m = map->mapita[i][j];
			if (map->mapita[i][j] == 'P')
				p++;
			if (map->mapita[i][j] == 'C')
				c++;
			if (map->mapita[i][j++] == 'E')
				e++;
			if (m != '1' && m != '0' && m != 'P' && m != 'C' && m != 'E')
				return 0;			
		}
	}
	if(!ft_check_played(map) || p != 1 || c < 1 || e != 1)
		return 0;
	return (1);	
}

int ft_read_map(int fd,char *file_name, t_map *map)
{
	int i;

	fd = open(file_name, O_RDONLY);// reopen file
	map->mapita = malloc(sizeof(char *) * map->map_height + 1); //allocate memory for map
	if(!map->mapita)
		return 0;
	map->mapita[i + 1] = NULL; 
	i = 0;
	while (i <= map->map_height - 1) //putting map on map variable
		map->mapita[i++] = get_next_line(fd);
	i = 0;
	while (map->mapita[1][++i]); //checking weight
	map->map_weight = i; // giving weight map value
	i = 0;
	while (map->mapita[0][i] && map->mapita[map->map_height - 1][i])//check 1  on sides
		if(map->mapita[0][i] != '1' || map->mapita[map->map_height - 1][i++] != '1')
			return (0);
	i = 0;
	while (i < map->map_height) // same of before
		if(map->mapita[i][0] != '1' || map->mapita[i++][map->map_weight - 2] != '1')
			return (0);
	if (!ft_check_items(map))
		return 0;
	return 1;
}

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
	i = 0;
	while (get_next_line(fd))//check map lines for size of char **
		i++;
	map->map_height = i; //giving height map value
	if (!ft_read_map(fd, file_name, map))
		return 0;
	return (1);
}