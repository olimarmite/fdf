/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_lerp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 07:51:27 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/28 09:01:02 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	color_lerp(int color_a, int color_b, double t)
{
	t_color	parsed_color_a;
	t_color	parsed_color_b;

	parsed_color_a = color_channels(color_a);
	parsed_color_b = color_channels(color_b);
	return ((int)
		(parsed_color_a.r + (parsed_color_b.r - parsed_color_a.r) * t) << 16
		|(int)
		(parsed_color_a.g + (parsed_color_b.g - parsed_color_a.g) * t) << 8
		|(int)
		(parsed_color_a.b + (parsed_color_b.b - parsed_color_a.b) * t));
}
