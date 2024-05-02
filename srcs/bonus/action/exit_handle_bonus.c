/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:11:25 by jewu              #+#    #+#             */
/*   Updated: 2024/05/02 15:58:24 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	got_exited_b(t_mlx *so_long, char c)
{
	if (!so_long || !c)
		return ;
	if ((c == 'E' && so_long->e->all_c == 1))
		close_everything_b(so_long);
	if (c == 'M')
	{
		ft_putstr_fd("GAME OVER\n", 1);
		close_everything_b(so_long);
	}
}
//when player is on open exit, leaves the game

void	open_exit_b(t_mlx *so_long)
{
	int	i;
	int	j;

	i = -1;
	if (!so_long)
		return ;
	while (++i < so_long->row)
	{
		j = -1;
		while (++j < so_long->column)
		{
			if (so_long->map[i][j] == 'E'
				&& so_long->collec_taken == so_long->collectibles)
			{
				so_long->e->all_c = 1;
				put_images_wall_exit_b(so_long, so_long->map[i][j]);
				return ;
			}
		}
	}
}
//open exit when all collectibles are gathered