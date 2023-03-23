/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:00:31 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 03:03:25 by olimarti         ###   ########.fr       */
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
	void				*mlx;
	t_line				line;

	mlx = mlx_init();
	context->mlx = mlx;
	context->drw_win = drawable_window_create(mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Hello World");
	if (context->drw_win == NULL)
	{
		return ;
	}
	//draw_pixel(context->drw_win->img_wrapper, 5, 5, 0x00FF0000);
	//draw_pixel(context->drw_win->img_wrapper, 5, 15, 0x00FF0000);
	line.x1 = 100;
	line.y1 = 100;
	line.x2 = 150;
	line.y2 = 200;
	line.color = 0x00FF0000;
	draw_line(line, context->drw_win->img_wrapper);
	mlx_put_image_to_window(mlx, context->drw_win->mlx_win,
		context->drw_win->img_wrapper->img, 0, 0);
	draw_map_test(context);
	register_close_events(context);
	mlx_loop(mlx);
	fdf_exit(context);
}


void	draw_map_test(t_context *context)
{
	t_map	map;
	int		y;
	int		x;
	t_line				line;

	map = context->map;
	y = 0;
	while (y < map.height - 1)
	{
		x = 0;
		while (x < map.width - 1)
		{
			line.x1 = x * 10;
			line.y1 = y * 10;
			line.x2 = (x + 1) * 10;
			line.y2 = (y) * 10;
			line.color = 0x0000FF00 * map.content[y][x + 1].altitude *  map.content[y][x].altitude;//0x00FF0000;
			draw_line(line, context->drw_win->img_wrapper);
			line.x1 = x * 10;
			line.y1 = y * 10;
			line.x2 = (x) * 10;
			line.y2 = (y + 1) * 10;
			line.color = 0x0000FF00 * map.content[y + 1][x].altitude * map.content[y][x].altitude;//0x00FF0000;
			draw_line(line, context->drw_win->img_wrapper);
			draw_pixel(context->drw_win->img_wrapper, x * 10, y * 10, 0x00FF0000 * map.content[y][x].altitude );//map.content[y][x].altitude);
			refresh(context->drw_win);

			x++;
		}
		y++;
	}
	refresh(context->drw_win);
}
