/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:21:20 by jewu              #+#    #+#             */
/*   Updated: 2024/04/17 18:48:00 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_xpm_image(t_mlx *so_long, char *path, t_image *new)
{
	if (!new || !path)
		return ;
	new->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr, path,
			&new->width, &new->height);
	if (!new->mlx_img)
	{
		free(new);
		return ;
	}
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		new->mlx_img, so_long->current_j * 42, so_long->current_i * 42);
	return ;
}
//loads mlx_img

void	put_player(t_mlx *so_long)
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
			if (so_long->map[i][j] == 'P')
				init_xpm_image(so_long, RENKO_DOWN, &so_long->tab_img[i][j]);
		}
	}
}
//display player

void	put_images(t_mlx *so_long)
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
			if (so_long->map[i][j] == '1')
				init_xpm_image(so_long, WALL2, &so_long->tab_img[i][j]);
			else if (so_long->map[i][j] == '0')
				init_xpm_image(so_long, BUSH, &so_long->tab_img[i][j]);
			else if (so_long->map[i][j] == 'C')
				init_xpm_image(so_long, JIGGY, &so_long->tab_img[i][j]);
			else if (so_long->map[i][j] == 'E')
				init_xpm_image(so_long, EXIT_CLOSED, &so_long->tab_img[i][j]);
		}
	}
}
//display bush, jiggy, brick and closed exit

void	load_images(t_mlx *so_long)
{
	int	i;

	so_long->tab_img = ft_calloc(so_long->row, sizeof(t_image *));
	if (!so_long->tab_img)
		return ;
	i = -1;
	while (++i < so_long->row)
	{
		so_long->tab_img[i] = ft_calloc(so_long->column, sizeof(t_image));
		if (!so_long->tab_img[i])
			free(so_long->tab_img);
	}
	put_images(so_long);
	put_player(so_long);
}
//browse map to load images