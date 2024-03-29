/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:17:25 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/06 23:07:26 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "../graphics/graphics.h"
# include "../map/map.h"

typedef struct s_context
{
	t_drawable_window	*drw_win;
	t_map				map;
	void				*mlx;
	t_drawing_params	drawing_params;
	int					is_dirty;
}	t_context;

#endif
