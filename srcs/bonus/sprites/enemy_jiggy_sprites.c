/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:21:28 by jewu              #+#    #+#             */
/*   Updated: 2024/04/25 18:02:24 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_images_enemy(t_mlx *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (so_long->map[++i])
	{
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'M')
			{
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
					so_long->img[9]->mlx_img, j * 42, i * 42);
			}
		}
	}
}
//display mob

static int	check_images(t_mlx *so_long)
{
	int	i;

	i = 8;
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
			ENEMY_DOWN, &so_long->img[13]->width, &so_long->img[13]->height);
	so_long->img[14]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			JIGGY2, &so_long->img[14]->width, &so_long->img[14]->height);
	so_long->img[15]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			JIGGY3, &so_long->img[15]->width, &so_long->img[15]->height);
	loaded = check_images(so_long);
	if (loaded == -1)
	{
		close_everything_b(so_long);
		exit(EXIT_FAILURE);
	}
	put_images_enemy(so_long);
	display_steps(so_long);
}
//load xpm images of enemy