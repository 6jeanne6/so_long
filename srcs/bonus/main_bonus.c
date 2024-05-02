/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:06:26 by jewu              #+#    #+#             */
/*   Updated: 2024/05/02 19:04:55 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	where_iz_enemy(t_mlx *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (++i < so_long->row)
	{
		j = -1;
		while (++j < so_long->column)
		{
			if (so_long->map[i][j] == 'M')
			{
				so_long->m->pos.x = i;
				so_long->m->pos.y = j;
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
					so_long->img[9]->mlx_img, j * 42, i * 42);
			}
		}
	}
}
//localize enemy

static void	set_position(t_mlx *so_long, char c, int *count)
{
	if (c == 'C')
	{
		so_long->c[*count].pos.x = so_long->current_i;
		so_long->c[*count].pos.y = so_long->current_j;
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img[2]->mlx_img, so_long->current_j * 42,
			so_long->current_i * 42);
		(*count)++;
	}
}
//set collectible position

static void	where_jiggy(t_mlx *so_long)
{
	int			i;
	int			j;
	static int	count;

	count = 0;
	i = -1;
	if (so_long->c)
		free(so_long->c);
	so_long->c = ft_calloc(so_long->collectibles, sizeof(t_collec));
	if (so_long->c == NULL)
		close_everything_b(so_long);
	while (so_long->map[++i])
	{
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'C')
			{
				so_long->current_i = i;
				so_long->current_j = j;
				set_position(so_long, so_long->map[i][j], &count);
			}
		}
	}
}
//where are jiggies?

static void	hook(t_mlx *so_long)
{
	mlx_hook(so_long->win_ptr, KeyPress, KeyPressMask,
		&handle_keypress_b, so_long);
	mlx_hook(so_long->win_ptr, DestroyNotify, StructureNotifyMask,
		&close_everything_b, so_long);
}
//keyboard touch

int	main(int argc, char **argv)
{
	t_mlx	so_long;
	int		x;
	int		y;

	x = TILE_SIZE;
	y = TILE_SIZE;
	map_init_b(argc, argv, &so_long);
	map_parsing_b(&so_long);
	map_set_things_b(&so_long);
	so_long.mlx_ptr = mlx_init();
	if (!so_long.mlx_ptr)
		destroy_and_tab_b(&so_long);
	x *= so_long.row;
	y *= so_long.column;
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, y, x, "Super Renko");
	if (!so_long.win_ptr)
		return (free(so_long.mlx_ptr), destroy_and_tab_b(&so_long));
	load_images_b(&so_long);
	hook(&so_long);
	where_jiggy(&so_long);
	where_iz_enemy(&so_long);
	mlx_loop_hook(so_long.mlx_ptr, &animate_jiggy, &so_long);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}
//so_long bonus