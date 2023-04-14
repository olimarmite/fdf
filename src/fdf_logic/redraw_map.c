/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:45:47 by olivier           #+#    #+#             */
/*   Updated: 2023/04/15 00:32:54 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_logic.h"

void	redraw_map(t_context *context)
{
    fill_image(context->drw_win->img_wrapper, 0);
    draw_map(context);
    refresh(context->drw_win);
}

int		refresh_if_needed(t_context *context)
{
	if (context->is_dirty)
	{
		redraw_map(context);
		context->is_dirty = 0;
	}
	return (0);
}