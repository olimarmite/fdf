/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:47:16 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/12 06:00:58 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define INT_MAX 2147483647

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

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
int			ft_isspace(char character);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr, int *nbr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strichr(const char *str, char c);
int			ft_atoi_base(const char *nptr, int *nbr, char *base, int base_len);

t_vect2d	vect2d(int x, int y);
t_vect2d	vect2d_add(t_vect2d vect1, t_vect2d vect2);
t_vect2d	vect2d_divide(t_vect2d vect1, t_vect2d vect2);
t_vect2d	vect2d_multiply(t_vect2d vect1, t_vect2d vect2);

t_vect3d	vect3d(int x, int y, int z);
t_vect3d	vect3d_add(t_vect3d vect1, t_vect3d vect2);
t_vect3d	vect3d_divide(t_vect3d vect1, t_vect3d vect2);
t_vect3d	vect3d_multiply(t_vect3d vect1, t_vect3d vect2);

#endif
