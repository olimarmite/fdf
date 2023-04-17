/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable_window_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:48:19 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/17 09:09:01 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_drawable_window
	*drawable_window_create(void *mlx, int width, int height, char *title)
{
	t_drawable_window	*drw_win;

	if (mlx == NULL)
		return (warnmsg("Drawable_window_create -> mlx musn't be null"), NULL);
	drw_win = malloc(sizeof(t_drawable_window));
	if (drw_win == 0)
	{
		errmsg("Drawable_window_create -> failed malloc :", 0);
		return (NULL);
	}
	drw_win->mlx = mlx;
	drw_win->mlx_win = mlx_new_window(mlx, width, height, title);
	if (drw_win->mlx_win == 0)
	{
		errmsg("Drawable_window_create -> Failed (mlx_new_window):", 0);
		return (free(drw_win), NULL);
	}
	drw_win->img_wrapper = image_wrapper_create(mlx, width, height);
	if (drw_win->img_wrapper == 0)
	{
		errmsg("Drawable_window_create -> Failed (image_wrapper_create):", 0);
		return (free(drw_win->mlx_win), free(drw_win), NULL);
	}
	return (drw_win);
}
