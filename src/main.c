/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:00:31 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/22 20:03:57 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
//# define DEC_ALPHABET "0123456789"
#include <fcntl.h>

int	validate_filename(char *path)
{
	int	i;
	int	j;

	i = 0;
	while (path[i])
	{
		j = 0;
		while (path[i + j] == FILE_EXT[j])
		{
			if (path[i + j] == 0)
			{
				return (i == 0);
			}
			j ++;
		}
		i ++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	context;
	int			fd;

	context.drw_win = NULL;
	if (argc != 2)
	{
		errmsg("Usage : ./fdf path_to_map/map.fdf", 0);
		return (1);
	}
	if (validate_filename(argv[1]))
		ft_fatal_error("Invalid map filename : map must be in .fdf format", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_fatal_error("Can't open map file", 0);
	if (parse_file(fd, &context.map) != 0)
		return (1);
	map_print(context.map);
	main_graphics(&context);
	register_close_events(&context);
	mlx_loop(context.mlx);
	fdf_exit(&context);
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
// 	mlx_put_image_to_window(drw_win->mlx, drw_win->mlx_win,
//	drw_win->img_wrapper->img, 0, 0);

// 	return (0);
// }

// void	draw_map_test(t_context *context);

// void	main_graphics(t_context *context)
// {
// 	void	*mlx;

// 	mlx = mlx_init();
// 	context->mlx = mlx;
// 	context->drw_win = drawable_window_create(mlx, WINDOW_WIDTH,
// 			WINDOW_HEIGHT, "Hello World");
// 	if (context->drw_win == NULL)
// 	{
// 		return ;
// 	}
// 	mlx_put_image_to_window(mlx, context->drw_win->mlx_win,
// 		context->drw_win->img_wrapper->img, 0, 0);
// 	draw_map_test(context);
// 	register_close_events(context);
// 	mlx_loop(mlx);
// 	fdf_exit(context);
// }

// void	draw_map_test(t_context *context)
// {
// 	t_map		map;
// 	int			y;
// 	int			x;
// 	t_line		line;
// 	int			ratio;
// 	t_f_vect2d	screen_pos;
// 	t_f_vect2d	screen_pos_next;
// 	t_f_vect2d	start_pos;
// 	t_f_vect2d	tile_size;

// 	map = context->map;
// 	ratio = 1;
// 	tile_size.x = calc_tile_size(context).x;
// 	tile_size.y = tile_size.x * ISOMETRY_RATIO;
// 	if (tile_size.y * context->map.height
//		> context->drw_win->img_wrapper->height)
// 	{
// 		tile_size.y = calc_tile_size(context).y;
// 		tile_size.x = tile_size.y / ISOMETRY_RATIO;
// 	}
// 	start_pos = center_position(context, tile_size);
// 	y = 0;
// 	while (y < map.height)
// 	{
// 		x = 0;
// 		while (x < map.width)
// 		{
// 			screen_pos = isometry_transform(map.content[y][x],
//				start_pos, tile_size, ratio);
// 			if (y != map.height - 1)
// 			{
// 				screen_pos_next = isometry_transform(map.content[y + 1][x],
//					start_pos, tile_size, ratio);
// 				line.point_a.pos = screen_pos;
// 				line.point_b.pos = screen_pos_next;
// 				line.point_a.color = map.content[y][x].color;
// 				line.point_b.color = map.content[y + 1][x].color;
// 				draw_line(line, context->drw_win->img_wrapper);
// 			}
// 			if (x != map.width - 1)
// 			{
// 				screen_pos_next = isometry_transform(map.content[y][x + 1],
//					start_pos, tile_size, ratio);
// 				line.point_a.pos = screen_pos;
// 				line.point_b.pos = screen_pos_next;
// 				line.point_a.color = map.content[y][x].color;
// 				line.point_b.color = map.content[y][x + 1].color;
// 				draw_line(line, context->drw_win->img_wrapper);
// 			}
// 		//	draw_pixel(context->drw_win->img_wrapper, screen_pos.x ,
//			screen_pos.y, map.content[y][x].color),//0x00FF00FF);
// * map.content[y][x].altitude );//map.content[y][x].altitude);
// 			x++;
// 		}
// 			refresh(context->drw_win);
// 		y++;
// 	}
// 	// line.point_a.pos = f_vect2d(10, 20);
// 	// line.point_b.pos = f_vect2d(100, 200);
// 	// line.point_a.color = 0x0000F0F0;
// 	// line.point_b.color = 0x00FFFFFF;
// 	// draw_line(line, context->drw_win->img_wrapper);
// 	// draw_pixel(context->drw_win->img_wrapper,
//start_pos.x, isometry_map_size(context->map, tile_size).y, 0x0000FF00);
// * map.content[y][x].altitude );//map.content[y][x].altitude);

// 	refresh(context->drw_win);
// }
