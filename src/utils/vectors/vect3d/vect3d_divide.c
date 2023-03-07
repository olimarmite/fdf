/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:51:11 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/07 23:36:49 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

t_vect3d	vect3d_divide(t_vect3d vect1, t_vect3d vect2)
{
	t_vect3d	result;

	result.x = vect1.x / vect2.x;
	result.y = vect1.y / vect2.y;
	result.z = vect1.z / vect2.z;
	return (result);
}
