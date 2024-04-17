/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:38:45 by jewu              #+#    #+#             */
/*   Updated: 2024/04/17 16:44:19 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	same_columns(t_mlx *so_long)
{
	int	i;
	int	column;
	int	column_read;

	i = (so_long->row) - 1;
	column = so_long->column;
	while (i >= 0)
	{
		column_read = ft_strlen(so_long->map[i]);
		if (column_read != column)
			return (-1);
		i--;
	}
	return (0);
}
//check if map has equal amount of columns

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
			if (so_long->map[0][j] != '1')
				return (-1);
			if (so_long->map[i][j] != '1' && so_long->map[i][j] != '0'
				&& so_long->map[i][j] != 'P' && so_long->map[i][j] != 'E'
				&& so_long->map[i][j] != 'C')
				return (-1);
			if (!so_long->map[i + 1])
				if (so_long->map[i][j] != '1')
					return (-1);
		}
		if ((so_long->map[i][0] != '1') || (so_long->map[i][j - 1] != '1'))
			return (-1);
	}
	so_long->row = i;
	so_long->column = j;
	return (1);
}
//only 0, 1, C, E and P are allowed
//map has to be surrounded by 1
//row and column are updated with i and j value

void	map_parsing(t_mlx *so_long)
{
	if (check_letter(so_long) == -1)
	{	
		free_tab_str(so_long->map);
		message_error("Error\nCheck the content of your map\n");
	}
	if (browse_map(so_long) == -1)
	{	
		free_tab_str(so_long->map);
		message_error("Error\nHow much C, E or P?\n");
	}
	if (same_columns(so_long) == -1)
	{	
		free_tab_str(so_long->map);
		message_error("Error\nCheck the content of your map\n");
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