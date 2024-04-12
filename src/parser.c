#include "so_long.h"

int parse_game(t_map *map)
{
    char    **cpy_map;
    int     i;
    int     return_value;
    int     c_count_aux;

    cpy_map = ft_calloc(sizeof(char *), map->height + 1);
    if (!cpy_map)
		return (0);
    i = -1;
	while (map->map[++i])
    {
		cpy_map[i] = ft_strdup(map->map[i]);
        if (!cpy_map[i])
            return (0);
    }
    c_count_aux = map->c_count;
    return_value = floodfill(map, cpy_map, map->player_y, map->player_x);
    map->c_count = c_count_aux;
    i = -1;
    while (cpy_map[++i])
        free(cpy_map[i]);
    free(cpy_map);
    return (return_value);
}

int parse_items(t_map *map)
{
    int i;
    int j;

    i = -1;
    while (map->map[++i])
    {
        j = -1;
        while (map->map[i][++j])
        {
            if (map->map[i][j] == 'P')
                map->player_x = ((map->player_y = i, map->p_count++, j));
            else if (map->map[i][j] == 'C')
                map->c_count++;
            else if (map->map[i][j] == 'E')
                map->e_count++;
            else if (map->map[i][j] == '1' || map->map[i][j] == '0')
                continue ;
            else
                return (0);
        }
    }
    if (map->p_count != 1 || map->c_count < 1 || map->e_count != 1)
		return (0);
	return (1);
}

int parse_map(char *file_name, t_map *map)
{
    int i;
    char *aux;

    map->fd = open(file_name, O_RDONLY);
    map->map = ft_calloc(sizeof(char *), map->height + 1);
    if (!map->map)
        return (0);
    i = -1;
    while (++i <= map->height - 1)
    {
        aux = get_next_line(map->fd);
        map->map[i] = ft_strtrim(aux, "\n");
        free(aux);
        if (!map->map[i] || (int)ft_strlen(map->map[i]) != map->lenght)
            return (0);
    }
    i = -1;
    while (map->map[0][++i])
        if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
            return (0)/*free map*/;
    i = -1;
    while (map->map[++i])
        if (map->map[i][0] != '1' || map->map[i][map->lenght - 1] != '1')
            return (0/*free map*/);
    return (1);
}

int	parse_file(char *file_name, t_map *map)
{
    int     file_len;
    char    *aux;

    ft_bzero(map, sizeof(map));
    map->fd = open(file_name, O_RDONLY);
    if (map->fd == -1)
        return (0);
    file_len = ft_strlen(file_name);
    if (file_name[--file_len] != 'r' || file_name[--file_len] != 'e'
		|| file_name[--file_len] != 'b' || file_name[--file_len] != '.')
		return (0);
    aux = get_next_line(map->fd);
    map->lenght = ft_strlen(aux) - 1;
    while (aux)
	{
		free(aux);
		aux = get_next_line(map->fd);  
        map->height++;
	}
    close(map->fd);
    if (map->height == 0)
        return (0);
    return (1);
}

int parse_all(char *file_name, t_map *map)
{
    if (!parse_file(file_name, map))
        return (0);
    if (!parse_map(file_name, map))
        return (0);
    if (!parse_items(map))
        return (0);
    if (!parse_game(map))
        return (0);
    return (1);
}