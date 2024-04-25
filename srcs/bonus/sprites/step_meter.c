/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_meter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:44:48 by jewu              #+#    #+#             */
/*   Updated: 2024/04/25 16:30:49 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_steps(t_mlx *so_long)
{
	char	*message;

	message = ft_itoa(so_long->p->step);
	if (!message)
		return ;
	//mlx_set_font(so_long->mlx_ptr, so_long->win_ptr, "FreeMono");
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr,
		so_long->column, so_long->row * 42, 0xFFFFFF, message);
	free(message);
}
//display steps in game