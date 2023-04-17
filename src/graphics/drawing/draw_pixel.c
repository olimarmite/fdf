/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:59:22 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/17 13:06:39 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	draw_pixel(t_image_wrapper *image, int x, int y, int color)
{
	char	*px;

	if (image->height > y && y >= 0 && image->width > x && x >= 0)
	{
		px = image->addr + ((image->line_length * y)
				+ (x * (image->bits_per_pixel / 8)));
		*(unsigned int *)px = color;
	}
}

void	draw_pixel_depth(t_image_wrapper *image, t_vect2d position,
	double depth, int color)
{
	char	*px;

	if (image->height > position.y && position.y >= 0 && image->width > position.x && position.x >= 0)
	{
		// printf("depth : %f ; y:%i x:%i\n", image->z_buff[(int)position.y * image->width + (int)position.x], (int)position.y, (int)position.x);
		if (image->z_buff[(int)position.y * image->width + (int)position.x] <= depth)
		{
		px = image->addr + (int)((image->line_length * (int)position.y)
				+ ((int)position.x * (image->bits_per_pixel / 8)));
		*(unsigned int *)px = color;// color_lerp(color, 0 , 1 - (1 / depth));
		image->z_buff[(int)position.y * image->width + (int)position.x] = depth;
		} else {
			
		}
	}
}