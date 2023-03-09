/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:02:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/09 17:24:10 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "utils/utils.h"

typedef struct s_point
{
	t_vect3d	pos;
	int			color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		max_altitude;
	int		min_altitude;
	t_point	**content;
}	t_map;

#endif
