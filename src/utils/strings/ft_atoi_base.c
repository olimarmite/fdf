/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:55:39 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/23 00:59:32 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

/**
 * Convert String [nptr] formated number to int
 *
 * @param nptr Input String
 * @param nbr Output pointer
 * @return Return 0 if [nptr] start by a valid number
 */
int	ft_atoi_base(const char *nptr, int *nbr, char *base, int base_len)
{
	long	nb;
	size_t	i;
	int		decoded_char_base;

	nb = 0;
	i = 0;
	*nbr = 0;
	if (*nptr == '-' || *nptr == '+')
		i++;
	decoded_char_base = ft_strichr(base, nptr[i]);
	if (decoded_char_base == -1)
		return (1);
	while (decoded_char_base != -1)
	{
		nb = (nb * base_len) + decoded_char_base;
		if (nb - (*nptr == '-') > INT_MAX)
			return (1);
		i++;
		decoded_char_base = ft_strichr(base, nptr[i]);
	}
	if (*nptr == '-')
		nb *= -1;
	*nbr = nb;
	return (0);
}
