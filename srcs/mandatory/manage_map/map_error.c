/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:25:24 by jewu              #+#    #+#             */
/*   Updated: 2024/05/03 18:28:17 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_so_long(t_mlx *so_long)
{
	if (!so_long)
		return ;
	if (so_long->c)
		free(so_long->c);
	if (so_long->p)
		free(so_long->p);
	if (so_long->e)
		free(so_long->e);
	if (so_long->mlx_ptr && so_long->win_ptr)
	{
		mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
		mlx_destroy_display(so_long->mlx_ptr);
		free(so_long->mlx_ptr);
	}
}
//free content of so_long

void	free_tab_str_tmp(char **tab, t_mlx *so_long)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (++i < so_long->row)
		free(tab[i]);
	free(tab);
}
//free array and double array

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