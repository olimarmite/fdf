/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:19:00 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/24 00:37:00 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

static int	point_in_view(t_vect3d pixel, t_image_wrapper *img)
{
	int	code;

	code = INSIDE;
	if (pixel.x < 0)
		code |= LEFT;
	else if (pixel.x > img->width)
		code |= RIGHT;
	if (pixel.y < 0)
		code |= BOTTOM;
	else if (pixel.y > img->height)
		code |= TOP;
	return (code);
}

static int	is_line_outside(t_line line, t_image_wrapper *img)
{
	int	outcode0;
	int	outcode1;

	outcode0 = point_in_view(line.point_a.pos, img);
	outcode1 = point_in_view(line.point_b.pos, img);
	if ((outcode0 & outcode1) != 0)
		return (1);
	return (0);
}

static t_f_vect2d	calc_delta(t_line line)
{
	t_f_vect2d	delta;

	delta.x = (line.point_b.pos.x - line.point_a.pos.x);
	delta.y = (line.point_b.pos.y - line.point_a.pos.y);
	return (delta);
}

void	draw_line(t_line line, t_image_wrapper *img)
{
	t_f_vect2d	delta;
	t_f_vect2d	cursor;
	double		step;
	double		total_step;

	delta = calc_delta(line);
	if (fabs(delta.x) >= fabs(delta.y))
		step = fabs(delta.x);
	else
		step = fabs(delta.y);
	delta.x = delta.x / step;
	delta.y = delta.y / step;
	cursor.x = line.point_a.pos.x;
	cursor.y = line.point_a.pos.y;
	total_step = step;
	while (step > 0)
	{
		draw_pixel_depth(img, vect2d(cursor.x, cursor.y),
			ft_lerp(line.point_a.pos.z, line.point_b.pos.z, step / total_step),
			color_lerp(line.point_b.color,
				line.point_a.color, step / total_step));
		cursor.x = cursor.x + delta.x;
		cursor.y = cursor.y + delta.y;
		step--;
	}
}

void	draw_line_if_in_win(t_line line, t_image_wrapper *img)
{
	if (is_line_outside(line, img) == 0)
	{
		draw_line(line, img);
	}
}
