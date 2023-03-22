/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:30:48 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/16 00:46:53 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../map/map.h"
# include "../utils/utils.h"

//# define HEX_UC_ALPHABET "0123456789ABCDEF"
//# define HEX_UC_ALPHABET "0123456789abcdef"

int	parse_file(int fd, t_map *map);

#endif
