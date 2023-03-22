/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:00:31 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/22 02:23:06 by olimarti         ###   ########.fr       */
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

typedef struct	s_vars {
	void	*mlx;
	void	*mlx_win;
	t_image	img_wrapper;
}				t_vars;


int on_mouse_move(int button, int x, int y, t_vars *vars)
{
	printf("mouse : %i ; %i\n", x, y);
	t_line line;
	line.x1 = WINDOW_WIDTH / 2;
	line.y1 = WINDOW_HEIGHT / 2;
	line.x2 = x;
	line.y2 = y;
	line.color = 0x00FF0000;
	draw_line(line, &vars->img_wrapper);
	draw_pixel(&vars->img_wrapper, x, y, 0x0000FF00);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img_wrapper.img, 0, 0);

}

void	main_graphics()
{
	t_vars vars;
	// void	*mlx;
	// void	*mlx_win;
	// t_image	img_wrapper;

	vars.mlx = mlx_init();
	if (vars.mlx == 0)
		ft_fatal_error("Error init -> mlx_init :", errno);
	vars.mlx_win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (vars.mlx == 0)
		ft_fatal_error("Error init -> mlx_new_window :", errno);
	vars.img_wrapper.width = WINDOW_WIDTH;
	vars.img_wrapper.height = WINDOW_HEIGHT;
	vars.img_wrapper.img = mlx_new_image(vars.mlx, vars.img_wrapper.width, vars.img_wrapper.height);
	if (vars.img_wrapper.img == 0)
		ft_fatal_error("Error init -> failed to create frame image :", errno);
	vars.img_wrapper.addr = mlx_get_data_addr(vars.img_wrapper.img,
			&vars.img_wrapper.bits_per_pixel, &vars.img_wrapper.line_length,
			&vars.img_wrapper.endian);

	draw_pixel(&vars.img_wrapper, 5, 5, 0x00FF0000);
	draw_pixel(&vars.img_wrapper, 5, 15, 0x00FF0000);
	t_line line;
	line.x1 = 100;
	line.y1 = 100;
	line.x2 = 150;
	line.y2 = 200;
	line.color = 0x00FF0000;
	draw_line(line, &vars.img_wrapper);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img_wrapper.img, 0, 0);
	mlx_mouse_hook(vars.mlx_win, on_mouse_move, &vars);
	mlx_loop(vars.mlx);
}
