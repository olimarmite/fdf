/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:30:04 by olivier           #+#    #+#             */
/*   Updated: 2023/04/13 18:45:28 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_logic.h"

void    fdf_move(int x, int y, t_context *context)
{

    context->drawing_params.position.x += x * context->drawing_params.tile_size.x;
    context->drawing_params.position.y += y * context->drawing_params.tile_size.y;
    // redraw_map(context);
		context->is_dirty = 1;

}

void    fdf_zoom(float factor, t_context *context)
{
    context->drawing_params.tile_size.x *= factor;
    context->drawing_params.tile_size.y *= factor;
    // redraw_map(context);
		context->is_dirty = 1;

}

void    fdf_altitude_zoom(float factor, t_context *context)
{
    context->drawing_params.ratio += factor;
    //redraw_map(context);
		context->is_dirty = 1;
}

void    fdf_rot(t_vect3d angle, t_context *context)
{
  context->drawing_params.rot = 
    vect3d_add(context->drawing_params.rot, angle);
	context->is_dirty = 1;
}

