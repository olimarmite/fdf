/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:30:04 by olivier           #+#    #+#             */
/*   Updated: 2023/04/20 21:35:16 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_logic.h"

void	fdf_move(int x, int y, t_context *context)
{
	context->drawing_params.position.x += x * context->drawing_params.zoom;
	context->drawing_params.position.y += y * context->drawing_params.zoom;
	context->is_dirty = 1;
}

void	fdf_zoom(float factor, t_context *context)
{
	context->drawing_params.zoom += factor * context->drawing_params.zoom * 0.1;
	context->is_dirty = 1;
}

void	fdf_altitude_zoom(float factor, t_context *context)
{
	context->drawing_params.ratio += factor * 0.1;
	context->is_dirty = 1;
}

void	fdf_rot(t_vect3d angle, t_context *context)
{
	context->drawing_params.rot = vect3d_add(context->drawing_params.rot,
			vect3d_multiply(angle, vect3d(3, 3, 3)));
	context->is_dirty = 1;
	printf("%f %f %f\n", context->drawing_params.rot.x,
		context->drawing_params.rot.y, context->drawing_params.rot.z);
}
