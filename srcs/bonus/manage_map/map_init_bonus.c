/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:09:45 by jewu              #+#    #+#             */
/*   Updated: 2024/05/03 12:30:55 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	space_or_tab_b(char *map)
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

static char	**lets_split_b(char *map)
{
	char	**map_split;

	map_split = ft_split(map, '\n');
	if (!map_split)
		return (NULL);
	return (map_split);
}
//split map by \n to have each line

static char	**gnl_and_join_b(t_mlx *so_long, int fd)
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
		if (space_or_tab_b(map) == -1)
			so_long->leak = 1;
		big_map = ft_strjoin_gnl(big_map, map);
		if (!big_map || big_map[0] == '\0')
			return (free(map), NULL);
		free(map);
		map = get_next_line(fd);
	}
	splitted_map = lets_split_b(big_map);
	if (!splitted_map)
		return (free(big_map), NULL);
	free(big_map);
	return (splitted_map);
}
// take all the content of map.ber and transform it to a char*
// → gnl and strjoin each line to read and have all the content
// → then split it by \n

static void	so_long_null_b(t_mlx *so_long)
{
	if (!so_long)
		return ;
	ft_bzero(so_long, sizeof(t_mlx));
	so_long->p = ft_calloc(1, sizeof(t_chara));
	if (!so_long->p)
		so_long->p = NULL;
	so_long->c = ft_calloc(1, sizeof(t_collec));
	if (!so_long->c)
		destroy_so_long_b(so_long);
	so_long->e = ft_calloc(1, sizeof(t_exit));
	if (!so_long->e)
		destroy_so_long_b(so_long);
	so_long->m = ft_calloc(1, sizeof(t_mob));
	if (!so_long->m)
		destroy_so_long_b(so_long);
}
//all variables of structure are set to NULL

void	map_init_b(int argc, char **argv, t_mlx *so_long)
{
	int	fd;

	fd = 0;
	so_long_null_b(so_long);
	if (argc != 2)
		message_error_b("Error\nHey listen! Only 2 arguments\n", so_long);
	if (!(ft_strstr(argv[1], ".ber")))
		message_error_b("Error\nPlease use a .ber map\n", so_long);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message_error_b("Error\nYour file cannot be opened...\n", so_long);
	so_long->map = gnl_and_join_b(so_long, fd);
	if (so_long->map == NULL || so_long->leak == 1)
	{
		free_tab_str_b(so_long->map, so_long);
		close(fd);
		message_error_b("Error\nHmm your map is kind of weird\n", so_long);
	}
	close(fd);
}
//check if arguments and map are good and take map content
