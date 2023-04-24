/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:00:31 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/24 23:06:38 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include <fcntl.h>

int	validate_filename(char *path)
{
	int	i;
	int	j;

	i = 0;
	while (path[i])
	{
		j = 0;
		while (path[i + j] == FILE_EXT[j])
		{
			if (path[i + j] == 0)
			{
				return (i == 0);
			}
			j ++;
		}
		i ++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	context;
	int			fd;

	context.drw_win = NULL;
	if (argc != 2)
	{
		errmsg("Usage : ./fdf path_to_map/map.fdf", 0);
		return (1);
	}
	if (validate_filename(argv[1]))
		ft_fatal_error("Invalid map filename : map must be in .fdf format", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_fatal_error("Can't open map file", 0);
	if (parse_file(fd, &context.map) != 0)
		return (1);
	main_graphics(&context);
	register_close_events(&context);
	mlx_loop(context.mlx);
	fdf_exit(&context);
	return (0);
}
