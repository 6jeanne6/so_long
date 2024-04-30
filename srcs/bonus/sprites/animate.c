/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:27:14 by jewu              #+#    #+#             */
/*   Updated: 2024/04/30 14:27:28 by jewu             ###   ########.fr       */
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

// static void	change_clock (t_mlx *so_long, long start)
// {
// 	if (so_long->frame_counter == 0)
// 	{
// 		so_long->frame_counter = 1;
// 		start = clock();
// 	}
// 	else if (so_long->frame_counter == 1)
// 	{
// 		so_long->frame_counter = 2;
// 		start = clock();
// 	}
// 	else if (so_long->frame_counter == 2)
// 	{
// 		so_long->frame_counter = 3;
// 		start = clock();
// 	}
// 	else if (so_long->frame_counter == 3)
// 	{
// 		so_long->frame_counter = 0;
// 		start = clock();
// 	}
// }
//change frame counter and start time

int	animate_jiggy(t_mlx *so_long)
{
	static long	start;
	long		now;
	double		time;

	now = clock();
	time = (double)(now - start) / CLOCKS_PER_SEC;
	if (time > 0.3)
	{
		if (so_long->frame_counter == 0)
		{
			so_long->frame_counter = 1;
			start = clock();
		}
		else if (so_long->frame_counter == 1)
		{
			so_long->frame_counter = 2;
			start = clock();
		}
		else if (so_long->frame_counter == 2)
		{
			so_long->frame_counter = 3;
			start = clock();
		}
		else if (so_long->frame_counter == 3)
		{
			so_long->frame_counter = 0;
			start = clock();
		}
		jiggy_loading(so_long);
	}
	return (0);
}
//animate jiggy