/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:00:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/14 00:22:52 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

#define PI 3.14159265359

t_vect2d	isometry_transform(t_point point, t_drawing_params params)
{
	t_vect3d	screen_pos;
	t_vect2d	screen_pos_2d;
	// double ang_x = PI / 4;
	// double ang_y = PI / 4;
	// double ang_z = PI / 4;

	screen_pos.x = point.x;
	screen_pos.y = point.y;
	screen_pos.z = point.altitude;

	// screen_pos.y = screen_pos.y * cos(params.rot.x) + screen_pos.z * sin(params.rot.x);
	// screen_pos.z = -screen_pos.y * sin(params.rot.x) + screen_pos.z * cos(params.rot.x);
	
	// screen_pos.x = screen_pos.x * cos(params.rot.y) + screen_pos.z * sin(params.rot.y);
	// screen_pos.z = -screen_pos.x * sin(params.rot.y) + screen_pos.z * cos(params.rot.y);

	screen_pos.x -=50;
	screen_pos.y -=50;
	screen_pos.x = screen_pos.x * cos(params.rot.z) - screen_pos.y * sin(params.rot.z);
	screen_pos.y = screen_pos.x * sin(params.rot.z) + screen_pos.y * cos(params.rot.z);

	screen_pos.x *=5;
	screen_pos.y *=5;
	//params.tile_size
	screen_pos.x +=50;
	screen_pos.y +=50;
	screen_pos_2d = vect2d(screen_pos.x, screen_pos.y);
	screen_pos_2d = vect2d_add(screen_pos_2d, params.position);
	//start_pos.x + (point.x - point.y) * tile_size.x / 2;
	// screen_pos.y = start_pos.y + (point.x + point.y) * tile_size.y / 2;
	// screen_pos.y -= point.altitude * altitude_ratio;
	return (screen_pos_2d);
}

// t_vect2d	isometry_transform(t_point point, t_vect2d start_pos,
// 	t_vect2d tile_size, int altitude_ratio)
// {
// 	t_vect2d	screen_pos;

// 	screen_pos.x = start_pos.x + (point.x - point.y) * tile_size.x / 2;
// 	screen_pos.y = start_pos.y + (point.x + point.y) * tile_size.y / 2;
// 	screen_pos.y -= point.altitude * altitude_ratio;
// 	return (screen_pos);
// }

t_vect2d	isometry_map_size(t_map map, t_vect2d tile_size)
{
	t_vect2d	isometry_size;

	isometry_size.x = ((map.width + map.height - 2) * tile_size.x) / 2;
	isometry_size.y = (map.width + map.height - 2) * tile_size.y / 2;
	return (isometry_size);
}
