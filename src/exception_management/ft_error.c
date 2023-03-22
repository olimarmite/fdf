/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:10:29 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/22 17:56:13 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception_management.h"

void	ft_fatal_error(char *error_msg, int set_errno)
{
	if (set_errno != 0)
		errno = set_errno;
	if (errno == 0)
		errno = 132;
	perror(error_msg);
	exit(errno);
}

int	errmsg(char *error_msg, int set_errno)
{
	if (set_errno != 0)
		errno = set_errno;
	if (errno == 0)
		errno = 132;
	perror(error_msg);
	return (errno);
}

void	warnmsg(char *error_msg)
{
	printf("WARN : %s\n");
}
