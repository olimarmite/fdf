/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:00:31 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 06:46:19 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
//# define DEC_ALPHABET "0123456789"
#include <fcntl.h>

#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 1200

void	main_graphics(t_context *context);

int	main(int argc, char **argv)
{
	t_context	context;
	int			fd;

	context.drw_win = NULL;

	if (argc != 2)
	{
		return (1);
	}
	fd = open(argv[1], O_RDONLY);

	if (parse_file(fd, &context.map) != 0)
	{
		return (1);
	}
	map_print(context.map);
	main_graphics(&context);
	return (0);
}

// int	on_mouse_move(int button, int x, int y, t_drawable_window *drw_win)
// {
// 	t_line	line;

// 	printf("mouse : %i ; %i\n", x, y);
// 	line.x1 = WINDOW_WIDTH / 2;
// 	line.y1 = WINDOW_HEIGHT / 2;
// 	line.x2 = x;
// 	line.y2 = y;
// 	line.color = 0x00FF0000;
// 	draw_line(line, drw_win->img_wrapper);
// 	draw_pixel(drw_win->img_wrapper, x, y, 0x0000FF00);
// 	mlx_put_image_to_window(drw_win->mlx, drw_win->mlx_win, drw_win->img_wrapper->img, 0, 0);

// 	return (0);
// }

void	draw_map_test(t_context *context);

void	main_graphics(t_context *context)
{
	void	*mlx;

	mlx = mlx_init();
	context->mlx = mlx;
	context->drw_win = drawable_window_create(mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Hello World");
	if (context->drw_win == NULL)
	{
		return ;
	}
	mlx_put_image_to_window(mlx, context->drw_win->mlx_win,
		context->drw_win->img_wrapper->img, 0, 0);
	draw_map_test(context);
	register_close_events(context);
	mlx_loop(mlx);
	fdf_exit(context);
}


t_vect2d center_position(t_vect2d map_size, t_vect2d tile_size)
{
	t_vect2d position;

	position.x = (map_size.y - 1) * tile_size.x / 2;
	position.y = 0;
	return (position);
}


void	draw_map_test(t_context *context)
{
	t_map		map;
	int			y;
	int			x;
	t_line		line;
	int			ratio;
	t_vect2d	screen_pos;
	t_vect2d	screen_pos_next;
	t_vect2d	start_pos;
	int			tile_width;

	map = context->map;
	ratio = 30;
	tile_width = 30;
	start_pos = center_position(vect2d(map.width, map.height), vect2d(tile_width, tile_width*0.58));
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			screen_pos = isometry_transform(map.content[y][x], start_pos, tile_width);
			if (y != map.height - 1)
			{
				screen_pos_next = isometry_transform(map.content[y + 1][x], start_pos, tile_width);
				line.x1 = screen_pos.x;
				line.y1 = screen_pos.y;
				line.x2 = screen_pos_next.x ;
				line.y2 = screen_pos_next.y ;
				line.color = 0x00FF0000;
				draw_line(line, context->drw_win->img_wrapper);
			}
			if (x != map.width - 1)
			{
				screen_pos_next = isometry_transform(map.content[y][x + 1], start_pos, tile_width);
				line.x1 = screen_pos.x;
				line.y1 = screen_pos.y;
				line.x2 = screen_pos_next.x ;
				line.y2 = screen_pos_next.y ;
				line.color = 0x00FF0000;
				draw_line(line, context->drw_win->img_wrapper);
			}
		//	draw_pixel(context->drw_win->img_wrapper, x * ratio , y * ratio , 0x00FF0000 * map.content[y][x].altitude );//map.content[y][x].altitude);
			printf("%i, %i\n", screen_pos.x, screen_pos.y, ratio);
			draw_pixel(context->drw_win->img_wrapper, screen_pos.x , screen_pos.y, 0x00FF0000);// * map.content[y][x].altitude );//map.content[y][x].altitude);

			x++;
		}
			refresh(context->drw_win);
		y++;
	}
	refresh(context->drw_win);
}
