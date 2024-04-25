/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:38:08 by adrgonza          #+#    #+#             */
/*   Updated: 2024/04/25 12:11:06 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "libft.h"
# include <mlx.h>

# define K_A 0
# define K_W 13
# define K_S 1
# define K_D 2
# define K_ESC 53
# define K_NTR 36
# define K_AR_L 123
# define K_AR_R 124
# define K_AR_U 126
# define K_AR_D 125

typedef struct map{
	char	**map;
	int		fd;
	int		height;
	int		lenght;
	int		p_count;
	int		c_count;
	int		e_count;
	int		player_x;
	int		player_y;
}				t_map;

typedef struct game{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
}	t_game;

/*  main  */
int	main(int argc, char **argv);

/* parser */
int parse_all(char *file_name, t_map *map);
int	parse_file(char *file_name, t_map *map);
int parse_map(char *file_name, t_map *map);
int parse_items(t_map *map);
int parse_game(t_map *map);

/* floodfill */
int floodfill(t_map *map, char **copy, int y, int x);

/* game */
void    init_game(t_game *game);