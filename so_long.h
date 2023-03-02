/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:38:08 by adrgonza          #+#    #+#             */
/*   Updated: 2023/03/01 19:38:09 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806L
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct m{
	char			**map;
	int				height;
	int				weight;
	int				player_x;
	int				player_y;
	unsigned int	step_count;
	int				c_cn;
	int				c_count_copy;
	int				p_cn;
	int				e_cn;
	char			*file;
	int				fd;
	int				x;
	int				y;
	char			*str;
}				t_map;

typedef struct g {
	void	*mlx;
	void	*wido;
	void	*floor;
	void	*exit;
	void	*player;
	void	*wall;
	void	*colle;
	int		sz;
	int		x;
	int		y;
	t_map	*m;
}				t_game;

int		main(int argc, char **argv);
char	*get_next_line(int fd);
int		ft_check_file(char *file_n, t_map *m);
int		ft_printf(char const *s, ...);
int		ft_free_m(t_map *m, t_game *g, int x);

#endif
