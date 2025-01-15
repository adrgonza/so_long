/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:37:56 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/01 19:37:58 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(t_map *m, t_game *g, int x)
{
	int	i;

	if (x == 0 || x == 1)
		ft_printf("\033[31mError:\nInvalid map");
	if (x == 3)
		ft_printf("\033[31mError:\nMissing files");
	if (x == 2)
		mlx_destroy_window(g->mlx, g->mlx_win);
	if (x == 1 || x == 2)
	{
		i = 0;
		while (i < m->height)
			free(m->map[i++]);
		free(m->map);
	}
	exit(0);
}

void	printmap(t_map *m, t_game *g)
{
	int	i;
	int	j;

	g->x = 0;
	i = -1;
	while (++i < m->height)
	{
		j = 0;
		g->y = 1;
		while (j < m->lenght - 1)
		{
			if (m->map[i][j] == '0')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->floor, g->y, g->x);
			if (m->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->wall, g->y, g->x);
			if (m->map[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->player, g->y, g->x);
			if (m->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->colle, g->y, g->x);
			if (m->map[i][j++] == 'E')
				mlx_put_image_to_window(g->mlx, g->mlx_win, g->exit, g->y, g->x);
			g->y += 32;
		}
		g->x += 32;
	}
}

int	move_check(t_game *g, int y, int x)
{
	if (g->map->map[y][x] == '1')
		return (0);
	if (g->map->map[y][x] == 'C')
		g->map->c_count--;
	if (g->map->map[y][x] == 'E')
	{
		if (g->map->c_count > 0)
			return (0);
		else
		{
			ft_printf("\nSteps: %d\n", g->map->step_count++);
			ft_printf("\n\n\033[0;32mEnhorabuena!!\n\n");
			free_map(g->map, g, 2);
		}
	}
	ft_printf("\nSteps: %d\n", g->map->step_count++);
	g->map->map[g->map->player_y][g->map->player_x] = '0';
	return (1);
}

int	manage_move(int key, t_game *g)
{
	int	x;
	int	y;

	x = g->map->player_x;
	y = g->map->player_y;
	if (key == 53)
		free_map(g->map, g, 2);
	if (key == 13 && move_check(g, y - 1, x))
		g->map->player_y--;
	if (key == 1 && move_check(g, y + 1, x))
		g->map->player_y++;
	if (key == 0 && move_check(g, y, x - 1))
		g->map->player_x--;
	if (key == 2 && move_check(g, y, x + 1))
		g->map->player_x++;
	if (key != 13 && key != 1 && key != 0 && key != 2)
		return (1);
	g->map->map[g->map->player_y][g->map->player_x] = 'P';
	printmap(g->map, g);
	return (1);
}

void	init_game(t_game *game)
{
	t_map *map;

	map = game->map;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, (map->lenght - 1) * 32, map->height * 32, "Midland");
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->sz, &game->sz);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->sz, &game->sz);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/plyr.xpm", &game->sz, &game->sz);
	game->colle = mlx_xpm_file_to_image(game->mlx, "textures/colle.xpm", &game->sz, &game->sz);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->sz, &game->sz);
	if (!game->floor || !game->exit || !game->player || !game->colle || !game->wall)
		free_map(map, game, 3);
	map->step_count = 1;
	printmap(map, game);
	mlx_hook(game->mlx_win, 17, 0, free_map, game);
	mlx_key_hook(game->mlx_win, manage_move, game);
	mlx_loop(game->mlx);
}
