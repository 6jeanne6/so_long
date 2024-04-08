/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:38:45 by jewu              #+#    #+#             */
/*   Updated: 2024/04/08 19:54:31 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_letter(char c)
{
	if (c != '1' || c != '0' || c != 'P' || c != 'E' || c != 'C')
		return (-1);
	return (1);
}
//only 0, 1, C, E and P are allowed

void	map_parsing(t_mlx *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][0] != '1')
				return ;
			if (check_letter(so_long->map[i][j] == -1))
				return ;
			j++;
		}
		i++;
	}
}
//check if map is valid or not
// → 0 = empty space
// → 1 = wall
// → C = collectible, at least 1 C
// → E = exit, only 1 E
// → P = player's starting position, only 1 P
// → Map must be surrounded by wall
// → Map must have a valid path (P to E)