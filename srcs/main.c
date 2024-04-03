/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:48:31 by jewu              #+#    #+#             */
/*   Updated: 2024/04/03 18:38:29 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_init;
	void	*mlx_win;
	void	*img;

	mlx_init = mlx_init();
	mlx_win = mlx_new_window(mlx_init, 20, 10, "so_long");
	img = mlx_xpm_file_to_image(mlx_init, "../images/floor/Purple_Nebula_08.png", &x, &y);
	exit(EXIT_SUCCESS);
	return (0);
}

// t_win    create_window(int height, int width, char *str)
// {
//     void *mlx_ptr;

//     mlx_ptr = mlx_init();
//     return((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str)});
// }

// int    main(void)
// {
//     t_win    window;

//     window = create_window(500, 500, "Very very long by Bickette");
//     mlx_loop(window.mlx_ptr);
// }
