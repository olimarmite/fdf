/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:00:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/22 18:31:20 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_vect3d	isometry_transform(t_point point, t_drawing_params params,
			t_f_vect2d map_size)
{
	t_vect3d	screen_pos;
	double		temp_y;
	double		temp_z;
	double		temp_x;

	screen_pos.x = point.x - map_size.x / 2;
	screen_pos.y = point.y - map_size.y / 2;
	screen_pos.z = point.altitude * params.ratio;
	temp_y = screen_pos.y;
	temp_z = screen_pos.z;
	screen_pos.y = temp_y * cos(params.rot.x) - temp_z * sin(params.rot.x);
	screen_pos.z = temp_y * sin(params.rot.x) + temp_z * cos(params.rot.x);
	temp_x = screen_pos.x;
	temp_z = screen_pos.z;
	screen_pos.x = temp_x * cos(params.rot.y) + temp_z * sin(params.rot.y);
	screen_pos.z = -temp_x * sin(params.rot.y) + temp_z * cos(params.rot.y);
	temp_x = screen_pos.x;
	temp_y = screen_pos.y;
	screen_pos.x = temp_x * cos(params.rot.z) - temp_y * sin(params.rot.z);
	screen_pos.y = temp_x * sin(params.rot.z) + temp_y * cos(params.rot.z);
	screen_pos.x *= params.zoom;
	screen_pos.y *= params.zoom;
	screen_pos = vect3d_add(screen_pos,
			vect3d(params.position.x, params.position.y, 0));
	return (screen_pos);
}

t_f_vect2d	isometry_map_size(t_map map, t_f_vect2d tile_size)
{
	t_f_vect2d	isometry_size;

	isometry_size.x = ((map.width + map.height - 2) * tile_size.x) / 2;
	isometry_size.y = (map.width + map.height - 2) * tile_size.y / 2;
	return (isometry_size);
}
