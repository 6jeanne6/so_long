/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:27:14 by jewu              #+#    #+#             */
/*   Updated: 2024/05/02 16:19:47 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	jiggy_loading(t_mlx *so_long)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < so_long->collectibles)
	{
		x = so_long->c[i].pos.x;
		y = so_long->c[i].pos.y;
		if (so_long->frame_counter == 0 && so_long->map[x][y] != '0'
			&& so_long->map[x][y] != 'P')
			mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
				so_long->img[2]->mlx_img, y * 42, x * 42);
		else if ((so_long->frame_counter == 1 || so_long->frame_counter == 3)
			&& so_long->map[x][y] != '0' && so_long->map[x][y] != 'P')
			mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
				so_long->img[14]->mlx_img, y * 42, x * 42);
		else if (so_long->frame_counter == 2 && so_long->map[x][y] != '0'
			&& so_long->map[x][y] != 'P')
			mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
				so_long->img[15]->mlx_img, y * 42, x * 42);
	}
	mlx_do_sync(so_long->mlx_ptr);
}
//load differents images of jiggy

static void	change_frame(t_mlx *so_long)
{
	if (so_long->frame_counter == 0)
		so_long->frame_counter = 1;
	else if (so_long->frame_counter == 1)
		so_long->frame_counter = 2;
	else if (so_long->frame_counter == 2)
		so_long->frame_counter = 3;
	else if (so_long->frame_counter == 3)
		so_long->frame_counter = 0;
}
//change frame

int	animate_jiggy(t_mlx *so_long)
{
	static long	start;
	long		now;
	double		time;

	now = clock();
	time = (double)(now - start) / CLOCKS_PER_SEC;
	if (time > 0.5)
	{
		change_frame(so_long);
		jiggy_loading(so_long);
		start = clock();
		animate_enemy(so_long);
	}
	return (0);
}
//animate jiggy every seconds
// → change frame by updating time and start
// → load said images