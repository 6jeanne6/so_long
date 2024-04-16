/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:55:06 by jewu              #+#    #+#             */
/*   Updated: 2024/04/16 19:23:05 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *so_long, t_chara *p)
{
	if (so_long->map[p->pos.x][p->pos.y - 1] == '0')
	{
		p->pos.y = p->pos.y - 1;
	}
}
//player goes up

int	handle_keypress(int key, t_mlx *so_long)
{
	if (key == XK_Escape)
		close_everything(so_long);
	// if (key == XK_a)
	// 	move_left(so_long, so_long->p);
	// if (key == XK_d)
	// 	move_right(so_long, so_long->p);
	if (key == XK_w)
		move_up(so_long, so_long->p);
	// if (key == XK_s)
	// 	move_down(so_long, so_long->p);
	return (0);
}
//handle keyboard directions