/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:00:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:24:43 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_vect3d    isometry_transform(t_point point, t_drawing_params params, t_f_vect2d map_size)
{
    t_vect3d screen_pos;
    // t_f_vect2d screen_pos_2d;

    // Convert rotation angles from degrees to radians
    double ang_x = params.rot.x; //*(PI / 180.0);
    double ang_y = params.rot.y; //*(PI / 180.0);
    double ang_z = params.rot.z; //*(PI / 180.0);

    screen_pos.x = point.x  - map_size.x / 2;
    screen_pos.y = point.y  - map_size.y / 2;
    screen_pos.z = point.altitude * params.ratio;

    // Apply x-axis rotation
    double temp_y = screen_pos.y;
    double temp_z = screen_pos.z;
    screen_pos.y = temp_y * cos(ang_x) - temp_z * sin(ang_x);
    screen_pos.z = temp_y * sin(ang_x) + temp_z * cos(ang_x);

    // Apply y-axis rotation
    double temp_x = screen_pos.x;
    temp_z = screen_pos.z;
    screen_pos.x = temp_x * cos(ang_y) + temp_z * sin(ang_y);
    screen_pos.z = -temp_x * sin(ang_y) + temp_z * cos(ang_y);

    // Apply z-axis rotation
    temp_x = screen_pos.x;
    temp_y = screen_pos.y;
    screen_pos.x = temp_x * cos(ang_z) - temp_y * sin(ang_z);
    screen_pos.y = temp_x * sin(ang_z) + temp_y * cos(ang_z);

    // Scale and translate the point
    screen_pos.x += map_size.x / 2;
    screen_pos.y += map_size.y / 2;

    screen_pos.x *= params.zoom;
    screen_pos.y *= params.zoom;

    // Convert to 2D screen position
    screen_pos = vect3d_add(screen_pos, vect3d(params.position.x,params.position.y, 0));
    return screen_pos;
}

t_f_vect2d	isometry_map_size(t_map map, t_f_vect2d tile_size)
{
	t_f_vect2d	isometry_size;

	isometry_size.x = ((map.width + map.height - 2) * tile_size.x) / 2;
	isometry_size.y = (map.width + map.height - 2) * tile_size.y / 2;
	return (isometry_size);
}
