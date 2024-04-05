/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:55:15 by jewu              #+#    #+#             */
/*   Updated: 2024/04/05 19:37:38 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**lets_split(char *map)
{
	char	**map_split;
	int		i;

	map_split = ft_split(map, '\n');
	i = 0;
	while (map_split[i])
		ft_printf("%s\n", map_split[i++]);
	return (map_split);
}

static char	*map_to_char(char *argv)
{
	char	*map;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		message_error("Error\nYour file cannot be opened...\n");
	map = get_next_line(fd);
	while (map)
	{
		ft_printf("%s", map);
		free(map);
		map = get_next_line(fd);
	}
	close (fd);
	return (map);
}
//transform map in char* with get_next_line

void	check_map(int argc, char **argv, t_mlx *so_long)
{
	(void)so_long;
	char	*parse;
	char	**ok;

	if (argc != 2)
		message_error("Error\nHey listen! Only 2 arguments\n");
	parse = map_to_char(argv[1]);
	ok = lets_split(parse);
}
//check if map is valid or not
// → 0 = empty space
// → 1 = wall
// → C = collectible, at least 1 C
// → E = exit, only 1 E
// → P = player's starting position, only 1 P
// → Map must be surrounded by wall
// → Map must have a valid path (P to E)
