/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:41:41 by jewu              #+#    #+#             */
/*   Updated: 2024/04/19 19:04:45 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_everything(t_mlx *so_long)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		mlx_destroy_image(so_long->mlx_ptr, so_long->img[i]->mlx_img);
		free(so_long->img[i]);
	}
	free_tab_str(so_long->map);
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	mlx_destroy_display(so_long->mlx_ptr);
	free(so_long->mlx_ptr);
	free(so_long->c);
	free(so_long->p);
	free(so_long->e);
	exit(0);
}
//if ESC, close window and free