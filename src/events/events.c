/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:37:37 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/14 22:41:18 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static int	on_window_closed(t_context *context)
{
	fdf_exit(context);
	return (0);
}

static int	on_key_pressed(int key, t_context *context)
{
//	printf("%i\n", key);
	if (key == KEY_ESC)
		fdf_exit(context);
	else if (key == 97)
		fdf_zoom(0.5, context);
	else if (key == 122)
		fdf_zoom(2, context);
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
	else if (key == 113)
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
}

void	register_close_events(t_context *context)
{
	mlx_hook(context->drw_win->mlx_win, DESTROY_NOTIFY_EVENT,
		STRUCTURE_NOTIFY_MASK, on_window_closed, context);
	mlx_hook(context->drw_win->mlx_win, KEYPRESS_EVENT, KEYPRESS_MASK,
		on_key_pressed, context);
}
