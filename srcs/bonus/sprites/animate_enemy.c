/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:15:50 by jewu              #+#    #+#             */
/*   Updated: 2024/05/03 14:17:09 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_images_enemy_bis(t_mlx *so_long, char c)
{
	if (c == 'M' && so_long->enemy_direction == 3)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img[11]->mlx_img, so_long->current_j * 42,
			so_long->current_i * 42);
	else if (c == 'M' && so_long->enemy_direction == 2)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img[9]->mlx_img, so_long->current_j * 42,
			so_long->current_i * 42);
	else if (c == 'M' && so_long->enemy_direction == 0)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img[13]->mlx_img, so_long->current_j * 42,
			so_long->current_i * 42);
}
//put sprites of enemy

void	put_images_mob(t_mlx *so_long)
{
	int		i;
	int		j;

	i = -1;
	while (++i < so_long->row)
	{
		so_long->current_i = i;
		j = -1;
		while (++j < so_long->column)
		{
			so_long->current_j = j;
			if (so_long->map[i][j] == 'M' && so_long->enemy_direction == 1)
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
					so_long->img[10]->mlx_img, so_long->current_j * 42,
					so_long->current_i * 42);
			else
				put_images_enemy_bis(so_long, so_long->map[i][j]);
		}
	}
}
//put sprites of enemy

void	move_enemy(t_mlx *so_long, t_mob *m)
{
	int	direction;

	direction = rand() % 4;
	if (direction == 1)
	{
		so_long->enemy_direction = direction;
		enemy_up(so_long, m);
	}
	else if (direction == 2)
	{
		so_long->enemy_direction = direction;
		enemy_down(so_long, m);
	}
	else if (direction == 3)
	{
		so_long->enemy_direction = direction;
		enemy_left(so_long, m);
	}
	else if (direction == 0)
	{
		so_long->enemy_direction = direction;
		enemy_right(so_long, m);
	}
}
//choose a random direction for mob

int	animate_enemy(t_mlx *so_long)
{
	static long	start;
	long		now;
	double		time;

	now = clock();
	time = (double)(now - start) / CLOCKS_PER_SEC;
	if (time > 0.1)
	{
		move_enemy(so_long, so_long->m);
		start = clock();
	}
	return (0);
}
//enemy will move on its own