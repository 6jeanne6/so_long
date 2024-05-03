/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:09:05 by jewu              #+#    #+#             */
/*   Updated: 2024/05/03 18:23:20 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_so_long_b(t_mlx *so_long)
{
	int	i;

	i = -1;
	if (!so_long)
		return ;
	if (so_long->c)
	{
		while (++i < so_long->collec_taken)
			if (so_long->c[i].position)
				free(so_long->c[i].position);
		free(so_long->c);
	}
	if (so_long->p)
		free(so_long->p);
	if (so_long->e)
		free(so_long->e);
	if (so_long->m)
		free(so_long->m);
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

void	free_tab_str_b(char **tab, t_mlx *so_long)
{
	int	i;

	(void)so_long;
	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
//free array and double array
//ft_printf("row: %d\n", so_long->row);

void	message_error_b(char *message, t_mlx *so_long)
{
	destroy_so_long_b(so_long);
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}
//puts an error message in standard error and exits