/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:28:44 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/12 05:59:15 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parsing.h"

// //0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0

// /**
//  * @brief Calculate the Width of a line
//  * @param line char*
//  * @return int Width of a line
//  */
// static int	count_point(char *line)
// {
// 	int	words_count;

// 	if (line == NULL)
// 		return (0);
// 	words_count = 1;
// 	while (line != 0)
// 	{
// 		if (*line == ' ')
// 			words_count ++;
// 		line ++;
// 	}
// 	return (words_count);
// }


// static int	parse_point(char *line)
// {
// 	int	i;
// 	int	altitude;

// 	i = 0;
// 	altitude = 0;
// 	while (ft_isspace(line[i]))
// 	{
// 		i++;
// 	}
// 	if (ft_atoi(line + i, &altitude) != 0)
// 	{
// 		return (1);
// 	}
// 	while (ft_isdigit(line[i]))
// 	{
// 		i++;
// 	}
// 	if (ft_strncmp(line + i, ",0x", 3) == 0)
// 	{
// 		i += 3;
// 	}
// 	return (0); //TODO
// }

// /**
//  * @brief Parse a String line from a map file
//  * @param line char* String line from a map file
//  * @return t_point* Return line of t_point
//  */
// static t_point	*parse_line(char *line)
// {
// 	int		i;
// 	int		line_width;
// 	t_point	*result;

// 	i = 0;
// 	line_width = count_point(line);
// 	result = malloc(line_width * sizeof(t_point));
// 	if (result == NULL)
// 		return (NULL);
// 	while (i < line_width)
// 	{
// 		while (ft_isspace(line[i]))
// 		{
// 			i++;
// 		}
// 		// while (/* condition */)
// 		// {
// 		// 	/* code */
// 		// }

// 	}
// 	return (NULL);
// }

