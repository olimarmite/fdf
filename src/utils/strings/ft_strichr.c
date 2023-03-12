/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:07:10 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/12 06:40:18 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

/**
 * @brief Search first index of char [c] in str
 *
 * @param char* str Text where the function search [c]
 * @param char c Searched character
 * @return Return index of c in str or Return -1 if not found
 */
int	ft_strichr(const char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == 0)
			return (-1);
		i++;
	}
	if (str[i] == 0)
		return (-1);
	return (i);
}
