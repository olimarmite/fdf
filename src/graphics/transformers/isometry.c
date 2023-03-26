/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:00:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 06:32:45 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_vect2d	isometry_transform(t_point point, t_vect2d start_pos,
	float tile_width)
{
	t_vect2d	screen_pos;
	float		height;

	height = tile_width * 0.58;
	screen_pos.x = start_pos.x + (point.x - point.y) * tile_width / 2;
	screen_pos.y = (start_pos.y + (point.x + point.y) * height / 2);
	screen_pos.y += (10 - point.altitude);
	return (screen_pos);
}
