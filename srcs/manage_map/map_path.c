/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:20:06 by jewu              #+#    #+#             */
/*   Updated: 2024/04/12 19:28:03 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_cpe_on_map(t_mlx *so_long, t_chara *p, t_collec *c, t_exit *e)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (so_long->map[++i])
	{
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'P')
			{
				p->pos_x = i;
				p->pos_y = j;
			}
			if (so_long->map[i][j] == 'E')
			{
				e->pos_x = i;
				e->pos_y = j;
			}
		}
	}
}
//define where is P and E
//also define where are C

void	map_set_things(t_mlx *so_long)
{
	t_chara			*player;
	t_collec		*collec;
	t_exit			*exit;

	set_cpe_on_map(so_long, player, collec, exit);
}
//is there a valid path?
// → P must gather all C to go to E