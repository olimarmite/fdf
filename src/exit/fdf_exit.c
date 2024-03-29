/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:58:20 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 02:20:33 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_exit.h"

void	fdf_exit(t_context *context)
{
	map_destroy(&context->map);
	drawable_window_destroy(&context->drw_win);
	mlx_destroy_display(context->mlx);
	free(context->mlx);
	exit(0);
}
