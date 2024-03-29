/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:50:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/17 09:36:00 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_pixel	pixel(t_vect3d pos, int color)
{
	t_pixel	pixel;

	pixel.pos = pos;
	pixel.color = color;
	return (pixel);
}
