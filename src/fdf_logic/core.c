/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:43:48 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/13 18:41:11 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_logic.h"

void	draw_line_column(int x, int y, t_vect2d screen_pos, t_context *context)
{
	t_vect2d			screen_pos_next;
	t_drawing_params	drw_params;
	t_map				map;

	map = context->map;
	if (y != map.height - 1)
	{
		drw_params = context->drawing_params;
		screen_pos_next = isometry_transform(map.content[y + 1][x], drw_params);
		draw_line(
			line(pixel(screen_pos, map.content[y][x].color),
				pixel(screen_pos_next, map.content[y + 1][x].color)),
			context->drw_win->img_wrapper
			);
	}
}

void	draw_line_row(int x, int y, t_vect2d screen_pos, t_context *context)
{
	t_vect2d			screen_pos_next;
	t_drawing_params	drw_params;
	t_map				map;

	map = context->map;
	if (x != map.width - 1)
	{
		drw_params = context->drawing_params;
		screen_pos_next = isometry_transform(map.content[y][x + 1], drw_params);
		draw_line(
			line(pixel(screen_pos, map.content[y][x].color),
				pixel(screen_pos_next, map.content[y][x + 1].color)),
			context->drw_win->img_wrapper);
	}
}

void	draw_point_line_neighbour(int x, int y, t_context *context)
{
	t_vect2d			screen_pos;

	screen_pos = isometry_transform(context->map.content[y][x],
			context->drawing_params);
	draw_line_column(x, y, screen_pos, context);
	draw_line_row(x, y, screen_pos, context);
}

void	draw_map(t_context *context)
{
	t_map		map;
	int			y;
	int			x;

	map = context->map;
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			draw_point_line_neighbour(x, y, context);
			x++;
		}
		y++;
	}
}

void	main_graphics(t_context *context)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		map_destroy(&context->map);
		exit(1);
	}
	context->mlx = mlx;
	context->drw_win = drawable_window_create(mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Fdf");
	if (context->drw_win == NULL)
	{
		map_destroy(&context->map);
		free(context->mlx);
		exit(1);
	}
	context->drawing_params.rot = vect3d(0, 0, 0);
	context->drawing_params.ratio = 1;
	context->drawing_params.tile_size = calc_iso_tile_size_fitted(context);
	context->drawing_params.position = center_position(context);
	context->is_dirty = 1;
	mlx_loop_hook(mlx, refresh_if_needed, context);
}

