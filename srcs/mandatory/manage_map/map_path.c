/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:20:06 by jewu              #+#    #+#             */
/*   Updated: 2024/04/24 19:00:14 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_cpe_on_map(t_mlx *so_long, t_chara *p, t_exit *e)
{
	int		i;
	int		j;

	i = -1;
	while (so_long->map[++i])
	{	
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'P')
			{
				p->pos.x = i;
				p->pos.y = j;
			}
			if (so_long->map[i][j] == 'E')
			{
				e->pos.x = i;
				e->pos.y = j;
			}
			if (so_long->map[i][j] == 'C')
				so_long->collectibles++;
		}
	}
}
//define where is P and E
//define how many C there are

static void	all_null(t_mlx *so_long, t_chara *p, t_collec *c, t_exit *e)
{
	if (!p || !c || !e)
	{
		free_tab_str(so_long->map);
		exit(EXIT_FAILURE);
	}
	p->pos.x = 0;
	p->pos.y = 0;
	p->direction = 0;
	p->step = 1;
	c->pos.x = 0;
	c->pos.y = 0;
	e->pos.x = 0;
	e->pos.y = 0;
	e->all_c = 0;
}
//set all variables to NULL

void	map_set_things(t_mlx *so_long)
{
	all_null(so_long, so_long->p, so_long->c, so_long->e);
	set_cpe_on_map(so_long, so_long->p, so_long->e);
	so_long->collec_tmp = so_long->collectibles;
	if (search_path(so_long) == -1)
	{
		free_tab_str(so_long->map);
		message_error("Error\nYour path is not valid\n", so_long);
	}
}
//is there a valid path?
// → P must gather all C to go to E