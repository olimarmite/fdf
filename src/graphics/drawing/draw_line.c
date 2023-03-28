/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:19:00 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/28 08:56:07 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	draw_line(t_line line, t_image_wrapper *img)
{
	double		dx;
	double		dy;
	t_vect2d	cursor;
	double		step;
	double		total_step;

	dx = (line.point_b.pos.x - line.point_a.pos.x);
	dy = (line.point_b.pos.y - line.point_a.pos.y);
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	cursor.x = line.point_a.pos.x;
	cursor.y = line.point_a.pos.y;
	total_step = step;
	while (step > 0)
	{
		draw_pixel(img, cursor.x, cursor.y, color_lerp(line.point_b.color,
				line.point_a.color, step / total_step));
		cursor.x = cursor.x + dx;
		cursor.y = cursor.y + dy;
		step --;
	}
}
