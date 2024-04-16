/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:21:20 by jewu              #+#    #+#             */
/*   Updated: 2024/04/16 18:55:34 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	*init_xpm_image(t_mlx *so_long, char *path, int row, int col)
{
	t_image	*new;

	new = ft_calloc(1, sizeof(t_image));
	if (!new)
		return (NULL);
	new->mlx_img = mlx_xpm_file_to_image(so_long->mlx_ptr, path,
			&new->width, &new->height);
	if (!new->mlx_img)
	{
		free(new);
		return (NULL);
	}
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		new->mlx_img, col * 42, row * 42);
	return (new);
}
//loads mlx_img

static void	put_player(t_mlx *so_long)
{
	int		i;
	int		j;
	t_image	*pic;

	i = -1;
	pic = NULL;
	while (++i < so_long->row)
	{
		j = -1;
		while (++j < so_long->column)
		{
			if (so_long->map[i][j] == 'P')
				pic = init_xpm_image(so_long, RENKO_DOWN, i, j);
		}
	}
}
//display player

static void	put_images(t_mlx *so_long)
{
	int		i;
	int		j;

	i = -1;
	while (++i < so_long->row)
	{
		j = -1;
		while (++j < so_long->column)
		{
			if (so_long->map[i][j] == '1')
				init_xpm_image(so_long, WALL2, i, j);
			else if (so_long->map[i][j] == '0')
				init_xpm_image(so_long, BUSH, i, j);
			else if (so_long->map[i][j] == 'C')
				init_xpm_image(so_long, JIGGY, i, j);
			else if (so_long->map[i][j] == 'E')
				init_xpm_image(so_long, EXIT_CLOSED, i, j);
		}
	}
}
//display bush, jiggy, brick and closed exit

void	load_images(t_mlx *so_long)
{
	put_images(so_long);
	put_player(so_long);
	mlx_key_hook(so_long->win_ptr, &handle_keypress, so_long);
}
//browse map to load images