/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:38:45 by jewu              #+#    #+#             */
/*   Updated: 2024/04/09 19:44:40 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	how_many_letter(char a, int *c, int *p, int *e)
{
	if (a == 'C')
		(*c)++;
	else if (a == 'P')
		(*p)++;
	else if (a == 'E')
		(*e)++;
	else
		return ;
}
//counter is incremented if it's C, P or E

static int	browse_map(t_mlx *so_long)
{
	static int	c;
	static int	p;
	static int	e;
	int			i;
	int			j;

	c = 0;
	p = 0;
	e = 0;
	i = -1;
	while (so_long->map[++i])
	{
		j = -1;
		while (so_long->map[i][++j])
			how_many_letter(so_long->map[i][j], &c, &p, &e);
	}
	if ((c < 1) || (p > 1 || p == 0) || (e > 1 || e == 0))
		return (-1);
	return (1);
}
//browse through map
// → C = collectible, at least 1 C
// → E = exit, only 1 E
// → P = player's starting position, only 1 P

static int	check_letter(t_mlx *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (so_long->map[++i])
	{
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] != '1' && so_long->map[i][j] != '0'
				&& so_long->map[i][j] != 'P' && so_long->map[i][j] != 'E'
				&& so_long->map[i][j] != 'C')
				return (-1);
		}
	}
	so_long->row = i;
	so_long->column = j;
	return (1);
}
//only 0, 1, C, E and P are allowed

void	map_parsing(t_mlx *so_long)
{
	if (check_letter(so_long) == -1)
		message_error("Error\nForbidden letter or digit\n");
	if (browse_map(so_long) == -1)
		message_error("Error\nNot enough C, E or P\n");
}
//check if map is valid or not
// → 0 = empty space
// → 1 = wall
// → C = collectible, at least 1 C
// → E = exit, only 1 E
// → P = player's starting position, only 1 P
// → Map must be surrounded by wall
// → Map must have a valid path (P to E)

// void	map_parsing(t_mlx *so_long)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (so_long->map[i])
// 	{
// 		j = 0;
// 		while (so_long->map[i][j])
// 		{
// 			ft_printf("Character: %c\n", so_long->map[i][j]);
// 			if (so_long->map[i][0] != '1')
// 				message_error("Error\nMap not closed by 1\n");
// 			if (check_letter(so_long->map[i][j]) == -1)
// 				message_error("Error\nForbidden letter or digit\n");
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (how_many_letter(&so_long) == -1)
// 		message_error("Error\nNot enough C, E or P\n");
// }
//check if map is valid or not
// → 0 = empty space
// → 1 = wall
// → C = collectible, at least 1 C
// → E = exit, only 1 E
// → P = player's starting position, only 1 P
// → Map must be surrounded by wall
// → Map must have a valid path (P to E)