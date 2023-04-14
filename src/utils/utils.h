/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:47:16 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/14 23:15:33 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define INT_MAX 2147483647

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "get_next_line/get_next_line.h"

typedef struct s_vect2d
{
	double	x;
	double	y;
}	t_vect2d;

typedef struct s_vect3d
{
	double	x;
	double	y;
	double	z;
}	t_vect3d;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isspace(char character);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr, int *nbr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strichr(const char *str, char c);
int			ft_atoi_base(const char *nptr, int *nbr, char *base, int base_len);
int			ft_atoi_hex(const char *nptr, int *nbr);
void		ft_putstr_fd(char *str, int fd);

t_vect2d	vect2d(double x, double y);
t_vect2d	vect2d_add(t_vect2d vect1, t_vect2d vect2);
t_vect2d	vect2d_divide(t_vect2d vect1, t_vect2d vect2);
t_vect2d	vect2d_multiply(t_vect2d vect1, t_vect2d vect2);

t_vect3d	vect3d(double x, double y, double z);
t_vect3d	vect3d_add(t_vect3d vect1, t_vect3d vect2);
t_vect3d	vect3d_divide(t_vect3d vect1, t_vect3d vect2);
t_vect3d	vect3d_multiply(t_vect3d vect1, t_vect3d vect2);

void		ft_fatal_error(char *error_msg, int set_errno);
int			errmsg(char *error_msg, int set_errno);
void		warnmsg(char *warn_msg);

t_color		color_channels(int color);
int			color_to_int(t_color color);
int			color_lerp(int color_a, int color_b, double t);

double		ft_min(double nb_a, double nb_b);

#endif
