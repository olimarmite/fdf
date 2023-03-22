/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_wrapper_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:25:05 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/22 18:00:00 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_image_wrapper	*image_wrapper_create(void *mlx, int width, int height)
{
	t_image_wrapper	*img_wrapper;

	img_wrapper = malloc(sizeof(t_image_wrapper));
	if (img_wrapper == 0)
	{
		errmsg("Image wrapper -> failed to create image wrapper :", 0);
		return (NULL);
	}
	img_wrapper->width = width;
	img_wrapper->height = height;
	img_wrapper->img = mlx_new_image(mlx, img_wrapper->width,
			img_wrapper->height);
	if (img_wrapper->img == 0)
	{
		errmsg("Image wrapper -> failed to create frame image :", 0);
		free(img_wrapper);
		return (NULL);
	}
	img_wrapper->addr = mlx_get_data_addr(img_wrapper->img,
			&img_wrapper->bits_per_pixel, &img_wrapper->line_length,
			&img_wrapper->endian);
	return (img_wrapper);
}
