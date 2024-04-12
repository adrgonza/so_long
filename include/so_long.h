/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:38:08 by adrgonza          #+#    #+#             */
/*   Updated: 2024/04/11 19:08:35 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>

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

/*  main  */
int	main(int argc, char **argv);

/* parser */
int	parse_file(char *file_name, t_map *map);

#endif
