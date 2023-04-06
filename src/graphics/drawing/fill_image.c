/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 00:25:15 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/07 01:12:58 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	fill_image(t_image_wrapper *image, int color)
{
	char				*px;
	unsigned long long	image_size;

	px = image->addr;
	image_size = image->line_length * image->height / image->bits_per_pixel * 8;
	while (image_size > 0)
	{
		*(unsigned int *)px = color;
		px += image->bits_per_pixel / 8;
		image_size --;
	}
}
