/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:48:31 by jewu              #+#    #+#             */
/*   Updated: 2024/04/09 14:06:17 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_image	img;
	int	x = TILE_SIZE;
	int y = TILE_SIZE;

	map_init(argc, argv, &mlx);
	map_parsing(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (0);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, x * 5, y * 5, "Super Renko");
	if (!mlx.win_ptr)
		return (0);
	img.mlx_img = mlx_xpm_file_to_image(mlx.mlx_ptr, RENKO_DOWN, &x, &y);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.mlx_img, 85, 70);
	// mlx_destroy_image(mlx.mlx_ptr, img.mlx_img);
	// mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	// free(mlx.mlx_ptr);
	mlx_loop(mlx.mlx_ptr);
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
