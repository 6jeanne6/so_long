/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:41:41 by jewu              #+#    #+#             */
/*   Updated: 2024/04/25 15:36:29 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_and_tab(t_mlx *so_long)
{
	if (!so_long)
		return (0);
	destroy_so_long(so_long);
	free_tab_str(so_long->map);
	free_tab_str(so_long->map);
	exit (0);
}
//destroy so_long + free map

int	close_everything(t_mlx *so_long)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (so_long->img[i]->mlx_img)
			mlx_destroy_image(so_long->mlx_ptr, so_long->img[i]->mlx_img);
		free(so_long->img[i]);
	}
	free_tab_str(so_long->map);
	free_tab_str(so_long->map_tmp);
	destroy_so_long(so_long);
	exit(0);
}
//if ESC, close window and free