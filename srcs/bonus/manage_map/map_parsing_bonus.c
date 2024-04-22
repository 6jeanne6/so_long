/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:10:08 by jewu              #+#    #+#             */
/*   Updated: 2024/04/22 17:13:26 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	same_columns_b(t_mlx *so_long)
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

static void	how_many_letter_b(char a, int *c, int *p, int *e)
{
	if (!c || !p || !e)
		return ;
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

static int	browse_map_b(t_mlx *so_long)
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
			how_many_letter_b(so_long->map[i][j], &c, &p, &e);
	}
	if ((c < 1) || (p > 1 || p == 0) || (e > 1 || e == 0))
		return (-1);
	return (1);
}
//browse through map
// → C = collectible, at least 1 C
// → E = exit, only 1 E
// → P = player's starting position, only 1 P

static int	check_letter_b(t_mlx *so_long)
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
				&& so_long->map[i][j] != 'C' && so_long->map[i][j] != 'M')
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
//only 0, 1, C, E, P and M are allowed
//map has to be surrounded by 1
//row and column are updated with i and j value

void	map_parsing_b(t_mlx *so_long)
{
	if (check_letter_b(so_long) == -1)
	{	
		free_tab_str_b(so_long->map);
		message_error_b("Error\nCheck the content of your map\n", so_long);
	}
	if (browse_map_b(so_long) == -1)
	{	
		free_tab_str_b(so_long->map);
		message_error_b("Error\nHow much C, E or P?\n", so_long);
	}
	if (same_columns_b(so_long) == -1)
	{	
		free_tab_str_b(so_long->map);
		message_error_b("Error\nCheck the content of your map\n", so_long);
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