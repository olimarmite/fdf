/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:35:29 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/24 20:52:04 by olimarti         ###   ########.fr       */
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
	ft_printf("heigth : %i; width : %i\n", map.height, map.width);
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			ft_printf("%i ", map.content[i][j].altitude);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
