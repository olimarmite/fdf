/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:28:44 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/24 00:37:53 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	point->color = DEFAULT_COLOR;
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
		return (errmsg("Parse line malloc error: ", 0), -1);
	while (i < points_count)
	{
		while (ft_isspace(line[j]))
			j++;
		if (parse_point(line + j, *returned_line + i, i, y) != 0)
		{
			errmsg("Parse line : line invalid syntax", 0);
			return (-1);
		}
		while (ft_isspace(line[j]) == 0 && line[j] != 0)
			j++;
		i++;
	}
	return (points_count);
}

static int	parse_and_add_line_to_map(char *line, int y, t_map *map)
{
	t_point	*points_line;
	int		result;

	result = parse_line(line, y, &points_line);
	if (result != map->width)
	{
		if (result >= 0)
			errmsg("Invalid map, inconsistant line lenght", 0);
	}
	else if (map_line_add(points_line, map) == 0)
	{
		return (0);
	}
	free(points_line);
	return (1);
}

int	parse_file(int fd, t_map *map)
{
	t_point	*points_line;
	char	*line;
	int		i;

	i = 0;
	points_line = NULL;
	line = get_next_line(fd);
	*map = map_create(0, count_point(line), NULL);
	if (map->width == 0)
		errmsg("Error Empty file", 0);
	else
	{
		while (parse_and_add_line_to_map(line, i, map) == 0)
		{
			i ++;
			free(line);
			line = get_next_line(fd);
			if (line == NULL)
				return (0);
		}
	}
	free(line);
	map_destroy(map);
	get_next_line_close(fd);
	return (1);
}
