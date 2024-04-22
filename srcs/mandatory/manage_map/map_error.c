/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:25:24 by jewu              #+#    #+#             */
/*   Updated: 2024/04/22 15:19:14 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_so_long(t_mlx *so_long)
{
	if (!so_long)
		return ;
	free(so_long->c);
	free(so_long->p);
	free(so_long->e);
}
//free content of so_long

void	free_tab_str(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
//free array and double array

void	message_error(char *message, t_mlx *so_long)
{
	if (!so_long || !message)
		return ;
	destroy_so_long(so_long);
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}
//puts an error message in standard error and exits