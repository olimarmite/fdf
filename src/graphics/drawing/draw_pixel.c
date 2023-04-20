/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:59:22 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:32:13 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	draw_pixel(t_image_wrapper *image, int x, int y, int color)
{
	char	*px;

	if (image->height > y && y >= 0 && image->width > x && x >= 0)
	{
		px = image->addr + ((image->line_length * y) + (x
					* (image->bits_per_pixel / 8)));
		*(unsigned int *)px = color;
	}
}

void	draw_pixel_depth(t_image_wrapper *image, t_vect2d position,
		double depth, int color)
{
	char	*px;

	if (image->height > position.y && position.y >= 0
		&& image->width > position.x && position.x >= 0)
	{
		if (image->z_buff[position.y * image->width + position.x]
			<= depth)
		{
			px = image->addr + ((image->line_length * position.y)
					+ (position.x * (image->bits_per_pixel / 8)));
			*(unsigned int *)px = color;
			image->z_buff[position.y * image->width
				+ position.x] = depth;
		}
	}
}
