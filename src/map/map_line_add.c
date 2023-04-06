/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:04:24 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/06 21:32:59 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * Resize map and add [line] at the end of [map]
 * In case of error map is unchanged
 * Return 0 if success
 */
int	map_line_add(t_point *line, t_map *map)
{
	t_point	**new_content;
	int		i;

	i = 0;
	new_content = malloc((map->height + 1) * sizeof(t_point *));
	if (new_content == NULL)
	{
		errmsg("map_line_add, malloc error", 0);
		return (1);
	}
	while (i < map->height)
	{
		new_content[i] = map->content[i];
		i ++;
	}
	new_content[i] = line;
	map->height ++;
	free(map->content);
	map->content = new_content;
	return (0);
}
