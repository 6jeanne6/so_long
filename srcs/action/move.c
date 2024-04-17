/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:55:06 by jewu              #+#    #+#             */
/*   Updated: 2024/04/17 19:21:41 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_mlx *so_long, t_chara *p)
{
	if (so_long->map[p->pos.x][p->pos.y + 1] != '1')
	{
		so_long->map[p->pos.x][p->pos.y] = '0';
		p->pos.y = p->pos.y + 1;
		so_long->map[p->pos.x][p->pos.y] = 'P';
		put_images(so_long);
		put_player(so_long);
	}
}
//player goes right

void	move_left(t_mlx *so_long, t_chara *p)
{
	if (so_long->map[p->pos.x][p->pos.y - 1] != '1')
	{
		so_long->map[p->pos.x][p->pos.y] = '0';
		p->pos.y = p->pos.y - 1;
		so_long->map[p->pos.x][p->pos.y] = 'P';
		put_images(so_long);
		put_player(so_long);
	}
}
//player goes left

void	move_down(t_mlx *so_long, t_chara *p)
{
	if (so_long->map[p->pos.x + 1][p->pos.y] != '1')
	{
		so_long->map[p->pos.x][p->pos.y] = '0';
		p->pos.x = p->pos.x + 1;
		so_long->map[p->pos.x][p->pos.y] = 'P';
		put_images(so_long);
		put_player(so_long);
	}
}
//player goes down

void	move_up(t_mlx *so_long, t_chara *p)
{
	if (so_long->map[p->pos.x - 1][p->pos.y] != '1')
	{
		so_long->map[p->pos.x][p->pos.y] = '0';
		p->pos.x = p->pos.x - 1;
		so_long->map[p->pos.x][p->pos.y] = 'P';
		put_images(so_long);
		put_player(so_long);
	}
}
//player goes up

int	handle_keypress(int key, t_mlx *so_long)
{
	if (key == XK_Escape)
		close_everything(so_long);
	if (key == XK_a)
		move_left(so_long, so_long->p);
	if (key == XK_d)
		move_right(so_long, so_long->p);
	if (key == XK_w)
		move_up(so_long, so_long->p);
	if (key == XK_s)
		move_down(so_long, so_long->p);
	return (0);
}
//handle keyboard directions