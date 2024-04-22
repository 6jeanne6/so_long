/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:11:25 by jewu              #+#    #+#             */
/*   Updated: 2024/04/22 16:31:13 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	got_exited_b(t_mlx *so_long, char c)
{
	if (!so_long || !c)
		return ;
	if (c == 'E' && so_long->e->all_c == 1)
		close_everything_b(so_long);
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
			if (so_long->map[i][j] == 'E' && so_long->collectibles == 0)
			{
				so_long->e->all_c = 1;
				put_images_exit_b(so_long, so_long->map[i][j]);
				return ;
			}
		}
	}
}
//open exit when all collectibles are gathered