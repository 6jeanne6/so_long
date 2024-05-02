/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:23:33 by jewu              #+#    #+#             */
/*   Updated: 2024/05/02 20:16:30 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_right(t_mlx *so_long, t_mob *m)
{
	if (so_long->map[m->pos.x][m->pos.y + 1] != '0'
	&& so_long->map[m->pos.x][m->pos.y + 1] != 'P')
	{
		put_images_b(so_long);
		put_images_mob(so_long);
		return ;
	}
	if (so_long->map[m->pos.x][m->pos.y + 1] == 'P')
		got_exited_b(so_long, so_long->map[m->pos.x][m->pos.y]);
	so_long->map[m->pos.x][m->pos.y] = '0';
	m->pos.y = m->pos.y + 1;
	so_long->map[m->pos.x][m->pos.y] = 'M';
	put_images_b(so_long);
	put_images_mob(so_long);
}
//enemy goes right

void	enemy_left(t_mlx *so_long, t_mob *m)
{
	if (so_long->map[m->pos.x][m->pos.y - 1] != '0'
	&& so_long->map[m->pos.x][m->pos.y - 1] != 'P')
	{
		put_images_b(so_long);
		put_images_mob(so_long);
		return ;
	}	
	if (so_long->map[m->pos.x][m->pos.y - 1] == 'P')
		got_exited_b(so_long, so_long->map[m->pos.x][m->pos.y]);
	so_long->map[m->pos.x][m->pos.y] = '0';
	m->pos.y = m->pos.y - 1;
	so_long->map[m->pos.x][m->pos.y] = 'M';
	put_images_b(so_long);
	put_images_mob(so_long);
}
//enemy goes left

void	enemy_down(t_mlx *so_long, t_mob *m)
{
	if (so_long->map[m->pos.x + 1][m->pos.y] != '0'
	&& so_long->map[m->pos.x + 1][m->pos.y] != 'P')
	{
		put_images_b(so_long);
		put_images_mob(so_long);
		return ;
	}
	if (so_long->map[m->pos.x + 1][m->pos.y] == 'P')
		got_exited_b(so_long, so_long->map[m->pos.x][m->pos.y]);
	so_long->map[m->pos.x][m->pos.y] = '0';
	m->pos.x = m->pos.x + 1;
	so_long->map[m->pos.x][m->pos.y] = 'M';
	put_images_b(so_long);
	put_images_mob(so_long);
}
//enemy goes down

void	enemy_up(t_mlx *so_long, t_mob *m)
{
	if (so_long->map[m->pos.x - 1][m->pos.y] != '0'
	&& so_long->map[m->pos.x - 1][m->pos.y] != 'P')
	{
		put_images_b(so_long);
		put_images_mob(so_long);
		return ;
	}
	if (so_long->map[m->pos.x - 1][m->pos.y] == 'P')
		got_exited_b(so_long, so_long->map[m->pos.x][m->pos.y]);
	so_long->map[m->pos.x][m->pos.y] = '0';
	m->pos.x = m->pos.x - 1;
	so_long->map[m->pos.x][m->pos.y] = 'M';
	put_images_b(so_long);
	put_images_mob(so_long);
}
//enemy move up