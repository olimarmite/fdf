/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:26:17 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/12 03:31:08 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief check if a character is a space
 * @return int Return 1 if character is a space
 */
int	ft_isspace(char character)
{
	return ((character >= 9 && character <= 13) || character == 32);
}
