/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:37:37 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/07 01:21:08 by olimarti         ###   ########.fr       */
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
	printf("%i\n", key);
	if (key == KEY_ESC)
	{
		fdf_exit(context);
	}
	else if (key == 65362)
	{
		context->drawing_params.ratio ++;
		fill_image(context->drw_win->img_wrapper, 0);
		draw_map(context);
		refresh(context->drw_win);
	}
	else if (key == 65364)
	{
		context->drawing_params.ratio --;
		fill_image(context->drw_win->img_wrapper, 0);
		draw_map(context);
		refresh(context->drw_win);
	}
}

void	register_close_events(t_context *context)
{
	mlx_hook(context->drw_win->mlx_win, DESTROY_NOTIFY_EVENT,
		STRUCTURE_NOTIFY_MASK, on_window_closed, context);
	mlx_hook(context->drw_win->mlx_win, KEYPRESS_EVENT, KEYPRESS_MASK,
		on_key_pressed, context);
}
