/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:06:26 by jewu              #+#    #+#             */
/*   Updated: 2024/04/25 16:22:44 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	hook(t_mlx *so_long)
{
	mlx_hook(so_long->win_ptr, KeyPress, KeyPressMask,
		&handle_keypress_b, so_long);
	mlx_hook(so_long->win_ptr, DestroyNotify, StructureNotifyMask,
		&close_everything_b, so_long);
}
//keyboard touch

int	main(int argc, char **argv)
{
	t_mlx	so_long;
	int		x;
	int		y;

	x = TILE_SIZE;
	y = TILE_SIZE;
	map_init_b(argc, argv, &so_long);
	map_parsing_b(&so_long);
	map_set_things_b(&so_long);
	so_long.mlx_ptr = mlx_init();
	if (!so_long.mlx_ptr)
		destroy_and_tab_b(&so_long);
	x *= so_long.row;
	y *= so_long.column;
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, y, x, "Super Renko");
	if (!so_long.win_ptr)
		return (free(so_long.mlx_ptr), destroy_and_tab_b(&so_long));
	load_images_b(&so_long);
	hook(&so_long);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}
//so_long bonus