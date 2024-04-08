/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:55:15 by jewu              #+#    #+#             */
/*   Updated: 2024/04/08 18:49:48 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**lets_split(char *map)
{
	char	**map_split;

	map_split = ft_split(map, '\n');
	if (!map_split)
		return (NULL);
	return (map_split);
}
//split map by \n to have each line

static char	**gnl_and_join(int fd)
{
	char	*map;
	char	*big_map;
	char	**splitted_map;

	map = get_next_line(fd);
	if (!map)
		return (NULL);
	big_map = ft_strdup_gnl("");
	if (!big_map)
		return (NULL);
	while (map)
	{
		big_map = ft_strjoin_gnl(big_map, map);
		if (!big_map || big_map[0] == '\0')
			return (free(big_map), NULL);
		free(map);
		map = get_next_line(fd);
	}
	splitted_map = lets_split(big_map);
	free(big_map);
	return (splitted_map);
}
//take all the content of map.ber and transform it to a char*
// → gnl and strjoin each line to read and have all the content
// → then split it by \n

void	map_init(int argc, char **argv, t_mlx *so_long)
{
	int		fd;

	fd = 0;
	if (argc != 2)
		message_error("Error\nHey listen! Only 2 arguments\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message_error("Error\nYour file cannot be opened...\n");
	so_long->map = gnl_and_join(fd);
	close(fd);
}
//check if arguments and map are good and take map content
