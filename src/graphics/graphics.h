/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:00:29 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/28 09:04:39 by olimarti         ###   ########.fr       */
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
}	t_image_wrapper;

typedef struct s_pixel
{
	t_vect2d	pos;
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

void				draw_pixel(t_image_wrapper *image, int x, int y, int color);
void				draw_line(t_line line, t_image_wrapper *img);
t_image_wrapper		*image_wrapper_create(void *mlx, int width, int height);
void				image_wrapper_destroy(void *mlx, t_image_wrapper **img_wrp);
t_drawable_window	*drawable_window_create(void *mlx, int width,
						int height, char *title);
void				drawable_window_destroy(t_drawable_window **drw_win);
void				refresh(t_drawable_window *drw_win);
t_vect2d			isometry_map_size(t_map map, t_vect2d tile_size);
t_vect2d			isometry_transform(t_point point, t_vect2d start_pos,
						t_vect2d tile_size, int altitude_ratio);
#endif
