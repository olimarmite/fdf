/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:00:31 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/22 23:01:23 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
//# define DEC_ALPHABET "0123456789"
#include <fcntl.h>

#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 1200

void	main_graphics();

int	main(int argc, char **argv)
{
	// t_map	map;
	// int		fd;

	// if (argc != 2)
	// {
	// 	return (1);
	// }
	// fd = open(argv[1], O_RDONLY);

	// if (parse_file(fd, &map) != 0)
	// {
	// 	return (1);
	// }
	// map_print(map);
	// map_destroy(&map);
	main_graphics();
	//return (0);
}

int	on_mouse_move(int button, int x, int y, t_drawable_window *drw_win)
{
	t_line	line;

	printf("mouse : %i ; %i\n", x, y);
	line.x1 = WINDOW_WIDTH / 2;
	line.y1 = WINDOW_HEIGHT / 2;
	line.x2 = x;
	line.y2 = y;
	line.color = 0x00FF0000;
	draw_line(line, drw_win->img_wrapper);
	draw_pixel(drw_win->img_wrapper, x, y, 0x0000FF00);
	mlx_put_image_to_window(drw_win->mlx, drw_win->mlx_win, drw_win->img_wrapper->img, 0, 0);

	return (0);
}

int	ft_close(t_drawable_window *drw_win)
{
	void	*mlx;

	mlx = drw_win->mlx;
	drawable_window_destroy(&drw_win);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(0);
	return (0);
}

void	main_graphics(void)
{
	void				*mlx;
	t_drawable_window	*drw_win;
	t_line				line;

	mlx = mlx_init();
	drw_win = drawable_window_create(mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Hello World");

	draw_pixel(drw_win->img_wrapper, 5, 5, 0x00FF0000);
	draw_pixel(drw_win->img_wrapper, 5, 15, 0x00FF0000);
	line.x1 = 100;
	line.y1 = 100;
	line.x2 = 150;
	line.y2 = 200;
	line.color = 0x00FF0000;
	draw_line(line, drw_win->img_wrapper);
	mlx_put_image_to_window(mlx, drw_win->mlx_win,
		drw_win->img_wrapper->img, 0, 0);
	mlx_mouse_hook(drw_win->mlx_win, on_mouse_move, drw_win);
	mlx_hook(drw_win->mlx_win, 17, 1L<<17, ft_close, drw_win);
	mlx_loop(mlx);
	ft_close(drw_win);
	// drawable_window_destroy(&drw_win);
	// free(mlx);
}
