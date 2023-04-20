/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:37:37 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/20 21:42:39 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static int	on_window_closed(t_context *context)
{
	fdf_exit(context);
	return (0);
}

static int	rotation_keys(int key, t_context *context)
{
	if (key == 113)
		fdf_rot(vect3d(0.01, 0, 0), context);
	else if (key == 115)
		fdf_rot(vect3d(0, 0.01, 0), context);
	else if (key == 100)
		fdf_rot(vect3d(0, 0, 0.01), context);
	else if (key == 119)
		fdf_rot(vect3d(-0.01, 0, 0), context);
	else if (key == 120)
		fdf_rot(vect3d(0, -0.01, 0), context);
	else if (key == 99)
		fdf_rot(vect3d(0, 0, -0.01), context);
	else
		return (0);
	return (1);
}

static int	on_key_pressed(int key, t_context *context)
{
	if (key == KEY_ESC)
		fdf_exit(context);
	else if (key == 97)
		fdf_zoom(-1, context);
	else if (key == 122)
		fdf_zoom(1, context);
	else if (key == 106)
		fdf_altitude_zoom(-1, context);
	else if (key == 107)
		fdf_altitude_zoom(1, context);
	else if (key == 65361)
		fdf_move(-1, 0, context);
	else if (key == 65362)
		fdf_move(0, -1, context);
	else if (key == 65363)
		fdf_move(1, 0, context);
	else if (key == 65364)
		fdf_move(0, 1, context);
	else
		rotation_keys(key, context);
	return (0);
}

void	register_close_events(t_context *context)
{
	mlx_hook(context->drw_win->mlx_win, DESTROY_NOTIFY_EVENT,
		STRUCTURE_NOTIFY_MASK, on_window_closed, context);
	mlx_hook(context->drw_win->mlx_win, KEYPRESS_EVENT, KEYPRESS_MASK,
		on_key_pressed, context);
}
