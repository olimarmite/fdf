/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:14:29 by olivier           #+#    #+#             */
/*   Updated: 2023/04/20 21:45:25 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Returns the lesser of two numbers. [nb_a] [nb_b]
 */
double	ft_min(double nb_a, double nb_b)
{
	if (nb_a < nb_b)
	{
		return (nb_a);
	}
	else
	{
		return (nb_b);
	}
}
