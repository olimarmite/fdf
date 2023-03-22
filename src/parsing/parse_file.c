/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:28:44 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/21 02:40:31 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0

/**
 * @brief Calculate the Width of a line
 * @param line char*
 * @return int Width of a line
 */
static int	count_point(char *line)
{
	int	words_count;

	if (line == NULL)
		return (0);
	words_count = 1;
	while (ft_isspace(*line))
		line ++;
	while (*line != '\n' && *line != 0)
	{
		if (ft_isspace(*line))
		{
			while (ft_isspace(*line))
				line ++;
			if (*line != 0)
				words_count ++;
		}
		else
		{
			line ++;
		}
	}
	return (words_count);
}

static int	parse_point(char *line, t_point *point, int point_x, int point_y)
{
	int	i;

	i = 0;
	point->x = point_x;
	point->y = point_y;
	point->color = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_atoi(line + i, &point->altitude) != 0)
		return (1);
	while (ft_isdigit(line[i]))
		i++;
	if (ft_strncmp(line + i, ",0x", 3) == 0)
	{
		i += 3;
		if (ft_atoi_hex(line + i, &point->color) != 0)
			return (1);
	}
	return (0);
}

/**
 * @brief Parse a String line from a map file
 * @param line char* String line from a map file
 * @return t_point* Return points count
 */
static int	parse_line(char *line, int y, t_point **returned_line)
{
	int		i;
	int		j;
	int		points_count;

	i = 0;
	j = 0;
	points_count = count_point(line);
	*returned_line = malloc(points_count * sizeof(t_point));
	if (*returned_line == NULL)
		return (0);
	while (i < points_count)
	{
		while (ft_isspace(line[j]))
			j++;
		if (parse_point(line + j, *returned_line + i, i, y) != 0)
		{
			free(*returned_line);
			return (0);
		}
		while (ft_isspace(line[j]) == 0 && line[j] != 0)
			j++;
		i++;
	}
	return (points_count);
}

int	parse_file(int fd, t_map *map)
{
	t_point	*points_line;
	char	*line;
	int		i;
	i = 0;
	line = get_next_line(fd);
	map->content = NULL;
	map->height = 0;
	map->width = count_point(line);
	printf("{%i}", map->width);

	while (line != NULL)
	{
		if (parse_line(line, i, &points_line) != map->width)
		{
			if (points_line == NULL)
			{
				printf("Malloc error\n");
			}
			free(line);
			map_destroy(map);
			return (1);
		}
		map_line_add(points_line, map);
		free(line);
		line = get_next_line(fd);
		i ++;
	}
	return (0);
}
