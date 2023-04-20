/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vect2d_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:44:20 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/20 21:44:26 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

t_f_vect2d	f_vect2d_add(t_f_vect2d vect1, t_f_vect2d vect2)
{
	t_f_vect2d	result;

	result.x = vect1.x + vect2.x;
	result.y = vect1.y + vect2.y;
	return (result);
}
