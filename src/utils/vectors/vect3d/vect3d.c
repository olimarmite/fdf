/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:51:11 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/28 08:31:44 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

t_vect3d	vect3d(double x, double y, double z)
{
	t_vect3d	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
