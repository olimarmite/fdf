/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:47:16 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/07 23:37:49 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_vect2d
{
	int	x;
	int	y;
}	t_vect2d;

typedef struct s_vect3d
{
	int	x;
	int	y;
	int	z;
}	t_vect3d;

char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

t_vect2d	vect2d(int x, int y);
t_vect2d	vect2d_add(t_vect2d vect1, t_vect2d vect2);
t_vect2d	vect2d_divide(t_vect2d vect1, t_vect2d vect2);
t_vect2d	vect2d_multiply(t_vect2d vect1, t_vect2d vect2);

t_vect3d	vect3d(int x, int y, int z);
t_vect3d	vect3d_add(t_vect3d vect1, t_vect3d vect2);
t_vect3d	vect3d_divide(t_vect3d vect1, t_vect3d vect2);
t_vect3d	vect3d_multiply(t_vect3d vect1, t_vect3d vect2);

#endif
