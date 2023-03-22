/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_wrapper_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:12:51 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/22 18:31:22 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	image_wrapper_destroy(void *mlx, t_image_wrapper **img_wrp)
{
	mlx_destroy_image(mlx, (*img_wrp)->img);
	free(*img_wrp);
	*img_wrp = NULL;
}
