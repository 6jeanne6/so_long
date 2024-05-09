/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_jiggy_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:21:28 by jewu              #+#    #+#             */
/*   Updated: 2024/05/09 14:24:41 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_images(t_mlx *so_long)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (!(so_long->img[i]->mlx_img))
			return (-1);
	}
	return (0);
}
//check if mlx xpm file has not failed

void	enemy_jiggy_sprite(t_mlx *so_long)
{
	int	loaded;

	loaded = 0;
	so_long->img[9]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			ENEMY_DOWN, &so_long->img[9]->width, &so_long->img[9]->height);
	so_long->img[10]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			ENEMY_UP, &so_long->img[10]->width, &so_long->img[10]->height);
	so_long->img[11]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			ENEMY_LEFT, &so_long->img[11]->width, &so_long->img[11]->height);
	so_long->img[12]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			ENEMY_DOWN, &so_long->img[12]->width, &so_long->img[12]->height);
	so_long->img[13]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			ENEMY_RIGHT, &so_long->img[13]->width, &so_long->img[13]->height);
	so_long->img[14]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			JIGGY2, &so_long->img[14]->width, &so_long->img[14]->height);
	so_long->img[15]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			JIGGY3, &so_long->img[15]->width, &so_long->img[15]->height);
	loaded = check_images(so_long);
	if (loaded == -1)
	{
		ft_putstr_fd("Error\nYour image is weird\n", 2);
		close_everything_b(so_long);
		exit(EXIT_FAILURE);
	}
	display_steps(so_long);
}
//load xpm images of enemy
