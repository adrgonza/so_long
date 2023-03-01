#include "so_long.h"

int swap_player(t_map *map, int y, int x, char **copy)
{
	if (x < 0 || x >= map->map_weight || y < 0 || y >= map->map_height)
		return 0;
	if (copy[y][x] == 'C')
	{
		map->c_count_copy--;
		copy[y][x] = '0';
	}
	else if (copy[y][x] == 'E') {
		if(map->c_count_copy == 0)
			return 1;
	}
	if (copy[y][x] == '0' || copy[y][x] == 'P') // verificar que la casilla sea vacía o la casilla inicial del jugador
	{
		copy[y][x] = '1';
		if (swap_player(map, y, x + 1, copy) || 
			swap_player(map, y, x - 1, copy) || 
			swap_player(map, y + 1, x, copy) || 
			swap_player(map, y - 1, x, copy))
			return 1;
	}
	return(0);
}

int ft_check_played(t_map *map, char *file_name)
{
	int i;
	char **copy;
	int fd;
	int x;
	int y;

	x = map->player_x;
	y = map->player_y;
	map->c_count_copy = map->c_count;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return 0;
	copy = malloc(sizeof(char *) * map->map_height + 1);
	if(!copy)
		return 0;
	i = 0;
	while (i <= map->map_height - 1)
		copy[i++] = get_next_line(fd);
	i = swap_player(map, y, x, copy);
	x = 0;
	while(x < map->map_height)
		free(copy[x++]);
	free(copy);
	if (i == 0)
		return 0;
	return (1);
}

int ft_check_items(t_map *map, char *file_name) // check if it has only 1 p e
{
	char m;
	int i;
	int j;
	int p;
	int e;
	
	p = 0;
	map->c_count = 0;
	e = 0;
	i = -1;
	while (++i < map->map_height)
	{
		j = 0;
		while (j < map->map_weight - 1)
		{
			m = map->mapita[i][j];
			if (map->mapita[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				p++;
			}
			if (map->mapita[i][j] == 'C')
				map->c_count++;
			if (map->mapita[i][j++] == 'E')
				e++;
			if (m != '1' && m != '0' && m != 'P' && m != 'C' && m != 'E')
				return 0;			
		}
	}
	if(!ft_check_played(map, file_name) || p != 1 || map->c_count < 1 || e != 1)
		return 0;
	return (1);	
}

int ft_read_map(int fd,char *file_name, t_map *map)
{
	int i;

	fd = open(file_name, O_RDONLY);// reopen file
	if(fd < 0)
		return 0;
	map->mapita = malloc(sizeof(char *) * map->map_height + 1); //allocate memory for map
	if(!map->mapita)
		return 0;
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
	if (!ft_check_items(map, file_name))
		return 0;
	return 1;
}

int ft_check_file(char *file_name, t_map *map)
{
	int i;
	int fd;
	
	fd = open(file_name, O_RDONLY);//open file
	if (fd < 0) //check map exist
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