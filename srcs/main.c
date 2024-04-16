/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:48:31 by jewu              #+#    #+#             */
/*   Updated: 2024/04/16 19:18:35 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		free(so_long.mlx_ptr);
		exit(EXIT_FAILURE);
	}
	x *= so_long.row;
	y *= so_long.column;
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, y, x, "Super Renko");
	if (!so_long.win_ptr)
		return (0);
	load_images(&so_long);
	mlx_key_hook(so_long.win_ptr, &handle_keypress, &so_long);
	// mlx_destroy_image(mlx.mlx_ptr, img.mlx_img);
	// mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	// free(mlx.mlx_ptr);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}

// t_mlx   create_window(int height, int width, char *str)
// {
//     void *mlx_ptr;

//     mlx_ptr = mlx_init();
//     return((t_mlx) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str)});
// }

// int    main(void)
// {
//     t_mlx    window;

//     window = create_window(500, 500, "Very very long by Bickette");
//     mlx_loop(window.mlx_ptr);
// }
