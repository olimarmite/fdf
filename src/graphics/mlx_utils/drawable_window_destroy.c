/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable_window_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:24:30 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/22 21:12:12 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	drawable_window_destroy(t_drawable_window **drw_win)
{
	image_wrapper_destroy((*drw_win)->mlx, &(*drw_win)->img_wrapper);
	mlx_destroy_window((*drw_win)->mlx, (*drw_win)->mlx_win);
	free(*drw_win);
	*drw_win = NULL;
}
