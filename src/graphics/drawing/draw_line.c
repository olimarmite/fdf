/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:19:00 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/22 17:35:36 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	draw_line(t_line line, t_image_wrapper *img)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	step;

	dx = (line.x2 - line.x1);
	dy = (line.y2 - line.y1);
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = line.x1;
	y = line.y1;
	while (step > 0)
	{
		draw_pixel(img, x, y, line.color);
		x = x + dx;
		y = y + dy;
		step --;
	}
}
