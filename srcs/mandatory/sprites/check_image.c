/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:45:31 by jewu              #+#    #+#             */
/*   Updated: 2024/04/23 14:52:18 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_xpm_images(t_mlx *so_long)
{
	int	i;

	i = 0;
	while (++i < 9)
	{
		if (!(so_long->img[i]->mlx_img))
			return (-1);
	}
	return (0);
}
//check if xpm_image worked and if img.ptr is not NULL