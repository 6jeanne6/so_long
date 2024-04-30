/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_meter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:44:48 by jewu              #+#    #+#             */
/*   Updated: 2024/04/26 17:35:29 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_steps(t_mlx *so_long)
{
	char	*message;
	char	buffer[20];

	message = ft_itoa(so_long->p->step);
	if (!message)
		return ;
	sprintf(buffer, "Steps: %d", so_long->p->step);
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr,
		so_long->column, so_long->row * 42, 0xFFFFFF, buffer);
	free(message);
}
//display steps in game