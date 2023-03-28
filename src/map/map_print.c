/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:35:29 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/28 09:02:41 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Display altitude points of [map]
 *
 * @param map t_map to display
 */
void	map_print(t_map map)
{
	int	i;
	int	j;

	i = 0;
	printf("heigth : %i; width : %i\n", map.height, map.width);
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			// printf("%i", map.content[i][j].altitude, map.content[i][j].color);
			printf("%i ", map.content[i][j].altitude);
			j++;
		}
		printf("\n");
		i++;
	}
}
