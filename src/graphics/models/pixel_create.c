/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:50:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/05 01:01:04 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_pixel	pixel(t_vect2d pos, int color)
{
	t_pixel	pixel;

	pixel.pos = pos;
	pixel.color = color;
	return (pixel);
}
