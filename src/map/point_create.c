/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:58:59 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/14 17:52:58 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_point	point_create(int altitude, int color, int x, int y)
{
	t_point	point;

	point.altitude = altitude;
	point.color = color;
	point.x = x;
	point.y = y;
	return (point);
}
