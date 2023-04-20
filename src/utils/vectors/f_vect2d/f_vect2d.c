/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vect2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:51:11 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:30:30 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

t_f_vect2d	f_vect2d(double x, double y)
{
	t_f_vect2d	result;

	result.x = x;
	result.y = y;
	return (result);
}
