/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:41:30 by olivier           #+#    #+#             */
/*   Updated: 2023/04/22 19:47:49 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	map_create(int height, int width, t_point **content)
{
	t_map	map;

	map.content = content;
	map.height = height;
	map.width = width;
	return (map);
}
