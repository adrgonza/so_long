#include "so_long.h"

int floodfill(t_map *map, char **copy, int y, int x)
{
	if (map->c_count == 0 && map->e_count == 0)
		return (1);
	if (x < 0 || x >= map->lenght || y < 0 || y >= map->height)
		return (0);
	if (copy[y][x] == 'C')
	{
		map->c_count--;
		copy[y][x] = '0';
	}
	if (copy[y][x] == 'E')
		map->e_count = 0;
	if (copy[y][x] == '0' || copy[y][x] == 'P')
	{
		copy[y][x] = '1';
		if (floodfill(map, copy, y, x + 1) || floodfill(map, copy, y, x - 1)
			|| floodfill(map, copy, y + 1, x) || floodfill(map, copy, y - 1, x))
			return (1);
	}
	return (0);
}