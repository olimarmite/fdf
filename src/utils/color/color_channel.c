/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_channel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 07:51:27 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/28 08:05:52 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

t_color	color_channels(int color)
{
	t_color	result;

	result.b = color & 0xFF;
	result.g = (color >> 8) & 0xFF;
	result.r = (color >> 16) & 0xFF;
	return (result);
}
