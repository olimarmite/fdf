/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:58:20 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 00:54:09 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_exit.h"

void	fdf_exit(t_drawable_window *drw_win)
{
	void	*mlx;

	mlx = drw_win->mlx;
	drawable_window_destroy(&drw_win);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(0);
}
