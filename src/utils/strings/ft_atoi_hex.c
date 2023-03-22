
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:55:39 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/12 06:40:13 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

#define HEX_UC_ALPHABET "0123456789ABCDEF"
#define HEX_BASE_LEN 16

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/**
 * Convert String [nptr] formated number to int
 *
 * @param nptr Input String
 * @param nbr Output pointer
 * @return Return 0 if [nptr] start by a valid number
 */
int	ft_atoi_hex(const char *nptr, int *nbr)
{
	long	nb;
	size_t	i;
	int		decoded_char_base;

	nb = 0;
	i = 0;
	*nbr = 0;
	if (*nptr == '-' || *nptr == '+')
		i++;
	decoded_char_base = ft_strichr(HEX_UC_ALPHABET, ft_toupper(nptr[i]));
	if (decoded_char_base == -1)
		return (1);
	while (decoded_char_base != -1)
	{
		nb = (nb * HEX_BASE_LEN) + decoded_char_base;
		if (nb - (*nptr == '-') > INT_MAX)
			return (1);
		i++;
		decoded_char_base = ft_strichr(HEX_UC_ALPHABET, nptr[i]);
	}
	if (*nptr == '-')
		nb *= -1;
	*nbr = nb;
	return (0);
}
