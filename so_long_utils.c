/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:38:18 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/01 19:38:20 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_p(t_map *m, int y, int x, char **copy)
{
	if (m->c_count_copy == 0 && m->e_cn == 1)
		return (1);
	if (x < 0 || x >= m->weight || y < 0 || y >= m->height)
		return (0);
	if (copy[y][x] == 'C')
	{
		m->c_count_copy--;
		copy[y][x] = '0';
	}
	if (copy[y][x] == 'E')
		m->e_cn = 1;
	if (copy[y][x] == '0' || copy[y][x] == 'P')
	{
		copy[y][x] = '1';
		if (fill_p(m, y, x + 1, copy) || fill_p(m, y, x - 1, copy)
			|| fill_p(m, y + 1, x, copy) || fill_p(m, y - 1, x, copy))
			return (1);
	}
	return (0);
}

int	ft_playable(t_map *m, char *file_n)
{
	int		i;
	char	**copy;

	m->e_cn = 0;
	m->x = m->player_x;
	m->y = m->player_y;
	m->c_count_copy = m->c_cn;
	m->fd = open(file_n, O_RDONLY);
	copy = malloc(sizeof(char *) * m->height + 1);
	if (!copy)
		return (0);
	i = 0;
	while (i <= m->height - 1)
		copy[i++] = get_next_line(m->fd);
	i = fill_p(m, m->y, m->x, copy);
	m->x = 0;
	while (m->x < m->height)
		free(copy[m->x++]);
	free(copy);
	if (i == 0)
		return (0);
	return (1);
}

int	ft_check_items(t_map *m, char *file_n)
{
	m->y = -1;
	while (++m->y < m->height)
	{
		m->x = -1;
		while (++m->x < m->weight - 1)
		{
			if (m->map[m->y][m->x] == 'P')
			{
				m->player_x = m->x;
				m->player_y = m->y;
				m->p_cn++;
			}
			if (m->map[m->y][m->x] == 'C')
				m->c_cn++;
			if (m->map[m->y][m->x] == 'E')
				m->e_cn++;
			if (m->map[m->y][m->x] != '1' && m->map[m->y][m->x] != '0'
				&& m->map[m->y][m->x] != 'P' && m->map[m->y][m->x] != 'C'
				&& m->map[m->y][m->x] != 'E')
				return (0);
		}
	}
	if (m->p_cn != 1 || m->c_cn < 1 || m->e_cn != 1 || !ft_playable(m, file_n))
		return (0);
	return (1);
}

int	ft_read_m(char *file_n, t_map *m)
{
	m->step_count = 1;
	m->c_cn = 0;
	m->fd = open(file_n, O_RDONLY);
	m->map = malloc(sizeof(char *) * m->height + 1);
	if (!m->map)
		return (0);
	m->y = 0;
	while (m->y <= m->height - 1)
		m->map[m->y++] = get_next_line(m->fd);
	m->y = 0;
	while (m->map[1][m->y])
		m->y++;
	m->weight = m->y;
	m->y = 0;
	while (m->map[0][m->y] && m->map[m->height - 1][m->y])
		if (m->map[0][m->y] != '1' || m->map[m->height - 1][m->y++] != '1')
			return (0);
	m->y = 0;
	while (m->y < m->height)
		if (m->map[m->y][0] != '1' || m->map[m->y++][m->weight - 2] != '1')
			return (0);
	if (!ft_check_items(m, file_n))
		return (0);
	return (1);
}

int	ft_check_file(char *file_n, t_map *m)
{
	m->p_cn = 0;
	m->e_cn = 0;
	m->y = 0;
	m->fd = open(file_n, O_RDONLY);
	while (file_n[m->y])
		m->y++;
	if (file_n[--m->y] != 'r' || file_n[--m->y] != 'e'
		|| file_n[--m->y] != 'b' || file_n[--m->y] != '.' || m->fd < 0)
		return (0);
	m->y = 0;
	m->str = get_next_line(m->fd);
	while (m->str)
	{
		free(m->str);
		m->str = get_next_line(m->fd);
		m->y++;
	}
	if (!m->y)
		return (0);
	m->height = m->y;
	if (!ft_read_m(file_n, m))
		return (ft_free_m(m, NULL, 1));
	return (1);
}
