/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:55:15 by jewu              #+#    #+#             */
/*   Updated: 2024/04/19 18:43:39 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	space_or_tab(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '\t' || map[0] != '1')
			return (-1);
		i++;
	}
	return (1);
}
//check if character is space or tab

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
		return (free(map), NULL);
	while (map)
	{
		if (space_or_tab(map) == -1)
		{
			get_next_line(-42);
			return (free(big_map), free(map), NULL);
		}
		big_map = ft_strjoin_gnl(big_map, map);
		if (!big_map || big_map[0] == '\0')
			return (free(map), NULL);
		free(map);
		map = get_next_line(fd);
	}
	splitted_map = lets_split(big_map);
	if (!splitted_map)
		return (free(big_map), NULL);
	free(big_map);
	return (splitted_map);
}
// take all the content of map.ber and transform it to a char*
// → gnl and strjoin each line to read and have all the content
// → then split it by \n

static void	so_long_null(t_mlx *so_long)
{
	if (!so_long)
		return ;
	so_long->mlx_ptr = NULL;
	so_long->win_ptr = NULL;
	so_long->map = NULL;
	so_long->map_tmp = NULL;
	so_long->row = 0;
	so_long->column = 0;
	so_long->collectibles = 0;
	so_long->current_i = 0;
	so_long->current_j = 0;
	so_long->p = ft_calloc(1, sizeof(t_chara));
	if (!so_long->p)
		so_long->p = NULL;
	so_long->c = ft_calloc(1, sizeof(t_collec));
	if (!so_long->c)
		so_long->c = NULL;
	so_long->e = ft_calloc(1, sizeof(t_exit));
	if (!so_long->e)
		so_long->e = NULL;
}
//all variables of structure are set to NULL

void	map_init(int argc, char **argv, t_mlx *so_long)
{
	int	fd;

	fd = 0;
	so_long_null(so_long);
	if (argc != 2)
		message_error("Error\nHey listen! Only 2 arguments\n", so_long);
	if (!(ft_strstr(argv[1], ".ber")))
		message_error("Error\nPlease use a .ber map\n", so_long);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message_error("Error\nYour file cannot be opened...\n", so_long);
	so_long->map = gnl_and_join(fd);
	if (so_long->map == NULL)
	{
		close(fd);
		message_error("Error\nHmm your map is kind of weird\n", so_long);
	}
	close(fd);
}
//check if arguments and map are good and take map content
