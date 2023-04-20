/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_wrapper_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:25:05 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:16:30 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

static int	create_z_buff(t_image_wrapper *img_wrapper, int width, int height)
{
	unsigned long long	size;

	size = height * width;
	img_wrapper->z_buff = malloc(sizeof(double) * size);
	if (img_wrapper->z_buff == NULL)
		return (1);
	ft_memset(img_wrapper->z_buff, -2147483648, size);
	return (0);
}

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
			&img_wrapper->bits_per_pixel,
			&img_wrapper->line_length,
			&img_wrapper->endian);
	if (create_z_buff(img_wrapper, width, height) != 0)
		return (image_wrapper_destroy(mlx, &img_wrapper), NULL);
	return (img_wrapper);
}
