/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_wrapper_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:12:51 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/17 09:00:17 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

void	image_wrapper_destroy(void *mlx, t_image_wrapper **img_wrp)
{
	mlx_destroy_image(mlx, (*img_wrp)->img);
	if ((*img_wrp)->z_buff != NULL)
	{
		free((*img_wrp)->z_buff);
	}
	free(*img_wrp);
	*img_wrp = NULL;
}
