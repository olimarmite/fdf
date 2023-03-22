/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:56:49 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/14 17:53:28 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief Checks whether a character c is a digit (0-9).
* @param c The character to be checked.
* @return int Returns 1 if c is a digit, 0 otherwise.
*/
int	ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57));
}
