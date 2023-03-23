/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:37:37 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 00:52:56 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static int	on_window_closed(t_drawable_window *drw_win)
{
	fdf_exit(drw_win);
	return (0);
}

static int	on_key_pressed(int key, t_drawable_window *drw_win)
{
	if (key == KEY_ESC)
	{
		fdf_exit(drw_win);
	}
}

void	register_close_events(t_drawable_window *drw_win)
{
	mlx_hook(drw_win->mlx_win, DESTROY_NOTIFY_EVENT, STRUCTURE_NOTIFY_MASK,
		on_window_closed, drw_win);
	mlx_hook(drw_win->mlx_win, KEYPRESS_EVENT, KEYPRESS_MASK,
		on_key_pressed, drw_win);
}
