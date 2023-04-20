/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vect2d_divide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:51:11 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/20 21:45:06 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

t_f_vect2d	f_vect2d_divide(t_f_vect2d vect1, t_f_vect2d vect2)
{
	t_f_vect2d	result;

	result.x = vect1.x / vect2.x;
	result.y = vect1.y / vect2.y;
	return (result);
}
