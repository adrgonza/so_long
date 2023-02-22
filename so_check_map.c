#include "so_long.h"

int ft_check_items(int fd,char *file_name)
{
	t_map map;
	int i;

	i = 0;
	while (get_next_line(fd))//check map lines fosize of char **
		i++;
	printf("\n\n%d\n\n", i);
	map.map_height = i; //giving height map value
	printf("\n\n%d\n\n", map.map_weight);
	fd = open(file_name, O_RDONLY);// reopen file to 
	map.mapita = malloc(sizeof(char *) * i); //allocate memory for map
	while (i) //putting map on map variable
    {
		map.mapita[i] = get_next_line(fd);
		printf("%s", map.mapita[i]);
		i--;
    }
	i = 0;
	while (map.mapita[1][++i]); //checking weight
	map.map_weight = i; // giving weight map value
	printf("\n\n%d\n\n", map.map_weight);
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
	if (!ft_check_items(fd, file_name))
		return 0;
	return (1);
}