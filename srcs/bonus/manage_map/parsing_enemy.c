/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:11:17 by jewu              #+#    #+#             */
/*   Updated: 2024/05/02 15:07:06 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	how_many_enemy(t_mlx *so_long)
{
	int	m;
	int	i;
	int	j;

	m = 0;
	i = -1;
	while (so_long->map[++i])
	{
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'M')
				m++;
		}
	}
	if (m == 0 || m > 1)
		return (-1);
	so_long->m->mobs = m;
	return (1);
}
//browse through map
// → M = mob, at least 1 M

void	where_is_enemy(t_mlx *so_long)
{
	how_many_enemy(so_long);
	if (how_many_enemy(so_long) == -1)
	{
		free_tab_str_b(so_long->map, so_long);
		message_error_b("Error\nEnemy or not enemy?\n", so_long);
	}
}
//checks if there is an enemy