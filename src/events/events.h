/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:50:15 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 01:04:29 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

//X11 events mask
# define STRUCTURE_NOTIFY_MASK 0b100000000000000000L
# define DESTROY_NOTIFY_EVENT 17
# define KEYPRESS_MASK 1L
# define KEYPRESS_EVENT 2

# define KEY_ESC 65307

# include "../graphics/graphics.h"
# include "../exit/fdf_exit.h"

void	register_close_events(t_drawable_window *drw_win);

#endif
