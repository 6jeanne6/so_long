/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:06:26 by jewu              #+#    #+#             */
/*   Updated: 2024/04/19 19:05:01 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	display(t_mlx *so_long)
{
	put_images(so_long);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	so_long;
	int		x;
	int		y;

	x = TILE_SIZE;
	y = TILE_SIZE;
	map_init(argc, argv, &so_long);
	map_parsing(&so_long);
	map_set_things(&so_long);
	so_long.mlx_ptr = mlx_init();
	if (!so_long.mlx_ptr)
		exit(EXIT_FAILURE);
	x *= so_long.row;
	y *= so_long.column;
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, y, x, "Super Renko");
	if (!so_long.win_ptr)
		return (free(so_long.mlx_ptr), 0);
	load_images(&so_long);
	mlx_key_hook(so_long.win_ptr, &handle_keypress, &so_long);
	mlx_hook(so_long.win_ptr, DestroyNotify, StructureNotifyMask, &close_everything,
        &so_long);
	mlx_loop_hook(so_long.mlx_ptr, &display, &so_long);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}
