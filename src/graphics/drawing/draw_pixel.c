/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:59:22 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 02:52:01 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	draw_pixel(t_image_wrapper *image, int x, int y, int color)
{
	char	*px;

	if (image->height > y && image->width > x)
	{
		px = image->addr + ((image->line_length * y)
				+ (x * (image->bits_per_pixel / 8)));
		*(unsigned int *)px = color;
	}
}
