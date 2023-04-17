/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:19:00 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/17 12:26:54 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

#define INSIDE 0 // Inside the viewing frustum
#define LEFT 1   // Left boundary of the viewing frustum
#define RIGHT 2  // Right boundary of the viewing frustum
#define BOTTOM 4 // Bottom boundary of the viewing frustum
#define TOP 8    // Top boundary of the viewing frustum

int point_in_view(t_vect3d pixel,  t_image_wrapper *img)
{
    int code = INSIDE;

    if (pixel.x < 0)
        code |= LEFT;
    else if (pixel.x > img->width)
        code |= RIGHT;
    if (pixel.y < 0)
        code |= BOTTOM;
    else if (pixel.y > img->height)
        code |= TOP;

    return code;
}

// Function to check if a line is fully outside the viewing frustum
int is_line_outside(t_line line, t_image_wrapper *img)
{
    int outcode0;
	int outcode1;

    outcode0 = point_in_view(line.point_a.pos, img);
    outcode1 = point_in_view(line.point_b.pos, img);
    if ((outcode0 & outcode1) != 0)
        return 1;
    return 0;
}



void	draw_line(t_line line, t_image_wrapper *img)
{
	double		dx;
	double		dy;
	t_vect2d	cursor;
	double		step;
	double		total_step;

	if (is_line_outside(line, img))
		return;
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
		draw_pixel_depth(img, cursor, ft_lerp(line.point_a.pos.z, line.point_b.pos.z, step / total_step), color_lerp(line.point_b.color,
				line.point_a.color, step / total_step));
		cursor.x = cursor.x + dx;
		cursor.y = cursor.y + dy;
		step --;
	}
}


