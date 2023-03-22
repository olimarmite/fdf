/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:10:29 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/22 00:24:34 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception_management.h"

void	ft_fatal_error(char *error_msg, int set_errno)
{
	if (set_errno != 0)
		errno = set_errno;
	perror(error_msg);
	exit(errno);
}
