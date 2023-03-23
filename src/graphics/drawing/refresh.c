/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:36:34 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 02:38:25 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	refresh(t_drawable_window *drw_win)
{
	mlx_put_image_to_window(drw_win->mlx, drw_win->mlx_win,
		drw_win->img_wrapper->img, 0, 0);
}
