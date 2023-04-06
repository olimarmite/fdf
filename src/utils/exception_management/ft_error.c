/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:10:29 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/06 22:02:30 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ft_fatal_error(char *error_msg, int set_errno)
{
	if (set_errno != 0)
		errno = set_errno;
	if (errno != 0)
		perror(error_msg);
	else
	{
		ft_putstr_fd(error_msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(errno);
}

int	errmsg(char *error_msg, int set_errno)
{
	if (set_errno != 0)
		errno = set_errno;
	if (errno != 0)
		perror(error_msg);
	else
	{
		ft_putstr_fd(error_msg, 2);
		ft_putstr_fd("\n", 2);
	}
	return (errno);
}

void	warnmsg(char *warn_msg)
{
	ft_putstr_fd("WARN :", 1);
	ft_putstr_fd(warn_msg, 1);
	ft_putstr_fd("\n", 2);
}
