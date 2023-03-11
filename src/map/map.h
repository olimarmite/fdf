/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:06:05 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/11 21:23:37 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../utils/utils.h"
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	altitude;
	int	color;
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	t_point	**content;
}	t_map;

void	map_print(t_map map);
int		map_line_add( t_point *line, t_map *map);
void	map_destroy(t_map *map);
t_point	point_create(int altitude, int color, int x, int y);

#endif
