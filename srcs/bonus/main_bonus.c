/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:06:26 by jewu              #+#    #+#             */
/*   Updated: 2024/04/23 18:16:38 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		exit(EXIT_FAILURE);
	x *= so_long.row;
	y *= so_long.column;
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, y, x, "Super Renko");
	if (!so_long.win_ptr)
		return (free(so_long.mlx_ptr), 0);
	load_images_b(&so_long);
	mlx_key_hook(so_long.win_ptr, &handle_keypress_b, &so_long);
	mlx_hook(so_long.win_ptr, DestroyNotify, StructureNotifyMask,
		&close_everything_b, &so_long);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}
//so_long bonus