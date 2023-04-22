/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_calcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:23:30 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/22 18:17:01 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_logic.h"

t_f_vect2d	center_position(t_context *context)
{
	t_f_vect2d	center;

	center = f_vect2d(context->drw_win->img_wrapper->width / 2,
			context->drw_win->img_wrapper->height / 2);
	return (center);
}

double	calc_zoom_factor(t_context *context)
{
	double	factor;

	factor = ft_min(context->drw_win->img_wrapper->width / context->map.width,
			context->drw_win->img_wrapper->height / context->map.height);
	factor /= 2;
	return (factor);
}
