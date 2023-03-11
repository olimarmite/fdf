/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:19:28 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/11 21:26:07 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Free content of a [map] and set size to 0
 * @param map t_map to be destroyed
 */
void	map_destroy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (i < map->height)
	{
		free(map->content[i]);
		i++;
	}
	free(map->content);
	map->content = NULL;
	map->height = 0;
	map->width = 0;
}
