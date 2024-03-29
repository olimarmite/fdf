/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:36:34 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/12 21:02:55 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	refresh(t_drawable_window *drw_win)
{
	mlx_put_image_to_window(drw_win->mlx, drw_win->mlx_win,
		drw_win->img_wrapper->img, 0, 0);
}
