/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:00:29 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/17 12:36:02 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "../utils/utils.h"
# include "../map/map.h"

# define ISOMETRY_RATIO 0.58

typedef struct s_image_wrapper
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	double		*z_buff;
}	t_image_wrapper;

typedef struct s_pixel
{
	t_vect3d	pos;
	int			color;
}	t_pixel;

typedef struct s_line
{
	t_pixel	point_a;
	t_pixel	point_b;
}	t_line;

typedef struct s_drawable_window
{
	void			*mlx;
	void			*mlx_win;
	t_image_wrapper	*img_wrapper;
}	t_drawable_window;

typedef struct s_drawing_params
{
	t_vect2d		position;
	double			zoom;
	double			ratio;
	t_vect3d		rot;
}		t_drawing_params;

void				draw_pixel(t_image_wrapper *image, int x, int y, int color);
void				draw_pixel_depth(t_image_wrapper *image, t_vect2d position,
						double depth, int color);

void				draw_line(t_line line, t_image_wrapper *img);
void				fill_image(t_image_wrapper *image, int color);
t_image_wrapper		*image_wrapper_create(void *mlx, int width, int height);
void				image_wrapper_destroy(void *mlx, t_image_wrapper **img_wrp);
t_drawable_window	*drawable_window_create(void *mlx, int width,
						int height, char *title);
void				drawable_window_destroy(t_drawable_window **drw_win);
void				refresh(t_drawable_window *drw_win);
t_vect2d			isometry_map_size(t_map map, t_vect2d tile_size);
t_vect3d			isometry_transform(t_point point, t_drawing_params params,
						t_vect2d map_size);



t_pixel				pixel(t_vect3d pos, int color);
t_line				line(t_pixel point_a, t_pixel point_b);

#endif
