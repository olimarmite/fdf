/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_management.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:02:06 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/09 22:50:09 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_MANAGEMENT_H
# define EXCEPTION_MANAGEMENT_H

# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void	ft_fatal_error(char *error_msg, int set_errno);

#endif
