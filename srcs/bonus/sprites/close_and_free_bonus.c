/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:41:41 by jewu              #+#    #+#             */
/*   Updated: 2024/04/23 18:54:59 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_everything_b(t_mlx *so_long)
{
	int	i;

	i = -1;
	while (++i < 13)
	{
		if (so_long->img[i]->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr, so_long->img[i]->mlx_img);
		free(so_long->img[i]);
	}
	free_tab_str_b(so_long->map);
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	mlx_destroy_display(so_long->mlx_ptr);
	free(so_long->mlx_ptr);
	destroy_so_long_b(so_long);
	exit(0);
}
//if ESC, close window and free