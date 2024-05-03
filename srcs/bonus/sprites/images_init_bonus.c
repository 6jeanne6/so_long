/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:51:16 by jewu              #+#    #+#             */
/*   Updated: 2024/05/03 15:51:42 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_images_player_b(t_mlx *so_long, char c)
{
	if (c == 'P')
	{
		if (so_long->p->direction == XK_s || so_long->p->direction == 0)
			mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
				so_long->img[5]->mlx_img, so_long->current_j * 42,
				so_long->current_i * 42);
		else if (so_long->p->direction == XK_w)
			mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
				so_long->img[6]->mlx_img, so_long->current_j * 42,
				so_long->current_i * 42);
		else if (so_long->p->direction == XK_a)
			mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
				so_long->img[7]->mlx_img, so_long->current_j * 42,
				so_long->current_i * 42);
		else if (so_long->p->direction == XK_d)
			mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
				so_long->img[8]->mlx_img, so_long->current_j * 42,
				so_long->current_i * 42);
	}
}
//display player according to direction 
//(see handle keypress) and collectible

void	put_images_wall_exit_b(t_mlx *so_long, char c)
{
	if (c == '1')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img[1]->mlx_img, so_long->current_j * 42,
			so_long->current_i * 42);
	else if (c == 'E' && so_long->e->all_c == 0)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img[3]->mlx_img, so_long->current_j * 42,
			so_long->current_i * 42);
	else if (c == 'E' && so_long->e->all_c == 1)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img[4]->mlx_img, so_long->current_j * 42,
			so_long->current_i * 42);
}
//display exit according to number of collectibles gathered

void	put_images_b(t_mlx *so_long)
{
	int		i;
	int		j;

	i = -1;
	while (++i < so_long->row)
	{
		so_long->current_i = i;
		j = -1;
		while (++j < so_long->column)
		{
			so_long->current_j = j;
			if (so_long->map[i][j] == '0')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
					so_long->img[0]->mlx_img, so_long->current_j * 42,
					so_long->current_i * 42);
			else if (so_long->map[i][j] == '1' || so_long->map[i][j] == 'E')
				put_images_wall_exit_b(so_long, so_long->map[i][j]);
			else if (so_long->map[i][j] == 'C' || so_long->map[i][j] == 'P')
				put_images_player_b(so_long, so_long->map[i][j]);
		}
	}
	display_steps(so_long);
}
//display bush, jiggy, brick and closed exit

static void	load_images_player_b(t_mlx *so_long)
{
	so_long->img[5]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			RENKO_DOWN, &so_long->img[5]->width, &so_long->img[5]->height);
	so_long->img[6]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			RENKO_UP, &so_long->img[6]->width, &so_long->img[6]->height);
	so_long->img[7]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			RENKO_LEFT, &so_long->img[7]->width, &so_long->img[7]->height);
	so_long->img[8]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			RENKO_RIGHT, &so_long->img[8]->width, &so_long->img[8]->height);
}
//load xpm images of player

void	load_images_b(t_mlx *so_long)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		so_long->img[i] = ft_calloc(1, sizeof(t_image));
		if (!so_long->img[i])
		{
			close_everything_b(so_long);
			return ;
		}
	}
	so_long->img[0]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			BUSH, &so_long->img[0]->width, &so_long->img[0]->height);
	so_long->img[1]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			WALL2, &so_long->img[1]->width, &so_long->img[1]->height);
	so_long->img[2]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			JIGGY, &so_long->img[2]->width, &so_long->img[2]->height);
	so_long->img[3]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			EXIT_CLOSED, &so_long->img[3]->width, &so_long->img[3]->height);
	so_long->img[4]->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			EXIT_OPENED, &so_long->img[4]->width, &so_long->img[4]->height);
	load_images_player_b(so_long);
	enemy_jiggy_sprite(so_long);
	put_images_b(so_long);
}
//alloc t_image array and load xpm images of bush, wall, jiggy, exit