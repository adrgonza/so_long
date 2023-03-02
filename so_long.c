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

int	ft_free_m(t_map *m, t_game *g, int x)
{
	int	i;

	if (x == 0 || x == 1)
		ft_printf("\033[31mError:\nInvalid map");
	if (x == 3)
		ft_printf("\033[31mError:\nMissing files");
	if (x == 2)
		mlx_destroy_window(g->mlx, g->wido);
	if (x == 1 || x == 2)
	{
		i = 0;
		while (i < m->height)
			free (m->map[i++]);
		free (m->map);
	}
	exit(0);
}

void	ft_image_m(t_map *m, t_game *g)
{
	int	i;
	int	j;

	g->x = 1;
	i = -1;
	while (++i < m->height)
	{
		j = 0;
		g->y = 1;
		while (j < m->weight - 1)
		{
			if (m->map[i][j] == '0')
				mlx_put_image_to_window(g->mlx, g->wido, g->floor, g->y, g->x);
			if (m->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->wido, g->wall, g->y, g->x);
			if (m->map[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->wido, g->player, g->y, g->x);
			if (m->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->wido, g->colle, g->y, g->x);
			if (m->map[i][j++] == 'E')
				mlx_put_image_to_window(g->mlx, g->wido, g->exit, g->y, g->x);
			g->y += 32;
		}
		g->x += 32;
	}
}

int	ft_mapove_check(t_game *g, int y, int x)
{
	if (g->m->map[y][x] == '1')
		return (0);
	if (g->m->map[y][x] == 'C')
		g->m->c_cn--;
	if (g->m->map[y][x] == 'E')
	{
		if (g->m->c_cn > 0)
			return (0);
		else
		{
			ft_printf("\nPasos: %d\n", g->m->step_count++);
			ft_printf("\n\n\033[0;32mEnhorabuena!!\n\n");
			ft_free_m(g->m, g, 2);
		}
	}
	ft_printf("\nPasos: %d\n", g->m->step_count++);
	g->m->map[g->m->player_y][g->m->player_x] = '0';
	return (1);
}

int	ft_movement(int key, t_game *g)
{
	int	x;
	int	y;

	x = g->m->player_x;
	y = g->m->player_y;
	if (key == 53)
		ft_free_m(g->m, g, 2);
	if (key == 13 && ft_mapove_check(g, y - 1, x))
		g->m->player_y--;
	if (key == 1 && ft_mapove_check(g, y + 1, x))
		g->m->player_y++;
	if (key == 0 && ft_mapove_check(g, y, x - 1))
		g->m->player_x--;
	if (key == 2 && ft_mapove_check(g, y, x + 1))
		g->m->player_x++;
	if (key != 13 && key != 1 && key != 0 && key != 2)
		return (1);
	g->m->map[g->m->player_y][g->m->player_x] = 'P';
	ft_image_m(g->m, g);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	g;
	t_map	m;

	g.m = &m;
	if (argc != 2 || !ft_check_file(argv[1], &m))
		return (ft_free_m(&m, &g, 0));
	g.mlx = mlx_init();
	g.wido = mlx_new_window(g.mlx, (m.weight - 1) * 32, m.height * 32, "Mland");
	g.floor = mlx_xpm_file_to_image(g.mlx, "textures/floor.xpm", &g.sz, &g.sz);
	g.exit = mlx_xpm_file_to_image(g.mlx, "textures/exit.xpm", &g.sz, &g.sz);
	g.player = mlx_xpm_file_to_image(g.mlx, "textures/plyr.xpm", &g.sz, &g.sz);
	g.colle = mlx_xpm_file_to_image(g.mlx, "textures/colle.xpm", &g.sz, &g.sz);
	g.wall = mlx_xpm_file_to_image(g.mlx, "textures/wall.xpm", &g.sz, &g.sz);
	if (!g.floor || !g.exit || !g.player || !g.colle || !g.wall)
		ft_free_m(&m, &g, 3);
	ft_image_m(&m, &g);
	mlx_hook(g.wido, 17, 0, ft_free_m, &g);
	mlx_key_hook(g.wido, ft_movement, &g);
	mlx_loop(g.mlx);
}
