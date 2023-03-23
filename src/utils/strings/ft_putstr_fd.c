/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:30:21 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 01:41:23 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	size;

	size = 0;
	while (str[size])
	{
		size ++;
	}
	write(fd, str, size);
}
