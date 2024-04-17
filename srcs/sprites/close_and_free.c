/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:41:41 by jewu              #+#    #+#             */
/*   Updated: 2024/04/17 17:47:31 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_mlx *so_long)
{
	if (so_long->c->jiggy)
		mlx_destroy_image(so_long->mlx_ptr, so_long->c->jiggy);
	if (so_long->p->left)
		mlx_destroy_image(so_long->mlx_ptr, so_long->p->left);
	if (so_long->p->right)
		mlx_destroy_image(so_long->mlx_ptr, so_long->p->right);
	if (so_long->p->up)
		mlx_destroy_image(so_long->mlx_ptr, so_long->p->up);
	if (so_long->p->down)
		mlx_destroy_image(so_long->mlx_ptr, so_long->p->down);
	if (so_long->e->exit_open)
		mlx_destroy_image(so_long->mlx_ptr, so_long->e->exit_open);
	if (so_long->e->exit_close)
		mlx_destroy_image(so_long->mlx_ptr, so_long->e->exit_close);
}
//destroy content of image and free

int	close_everything(t_mlx *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (++i < so_long->row)
	{
		j = -1;
		while (++j < so_long->column)
			mlx_destroy_image(so_long->mlx_ptr, so_long->tab_img[i][j].mlx_img);
		free(so_long->tab_img[i]);
	}
	free(so_long->tab_img);
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	mlx_destroy_display(so_long->mlx_ptr);
	free(so_long->mlx_ptr);
	free(so_long->c);
	free(so_long->p);
	free(so_long->e);
	exit(0);
}
//if ESC, close window and free