/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:00:31 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/11 21:24:05 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int	main(void)
{
	t_map	map;
	t_point	*line;
	int		i;
	int		j;

	map.width = 10;
	map.height = 0;
	map.content = NULL;
	i = 0;
	while (i < 10)
	{
		j = 0;
		line = malloc(map.width * sizeof(t_point));
		while (j < map.width)
		{
			line[j] = point_create(j, 0, j, map.height + 1);
			j++;
		}
		map_line_add(line, &map);
		i ++;
	}
	map_print(map);
	map_destroy(&map);
}
