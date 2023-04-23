/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:30:48 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/24 00:38:00 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../map/map.h"
# include "../utils/utils.h"

# define DEFAULT_COLOR 0x00FFFFFF

int	parse_file(int fd, t_map *map);

#endif
