/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:50:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/06 20:43:07 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_line	line(t_pixel point_a, t_pixel point_b)
{
	t_line	line;

	line.point_a = point_a;
	line.point_b = point_b;
	return (line);
}
