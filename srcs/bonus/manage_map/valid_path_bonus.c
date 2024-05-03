/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:47:55 by jewu              #+#    #+#             */
/*   Updated: 2024/05/03 14:37:20 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	fill_exit_b(t_mlx *so_long, t_pos current)
{
	if (current.x < 0 || current.x >= so_long->row
		|| current.y < 0 || current.y >= so_long->column
		|| so_long->map_tmp[current.x][current.y] == '1'
		|| so_long->map_tmp[current.x][current.y] == 'A'
		|| so_long->map_tmp[current.x][current.y] == 'M')
		return (0);
	if (so_long->map_tmp[current.x][current.y] == 'C')
		return (1);
	so_long->map_tmp[current.x][current.y] = 'A';
	if ((fill_exit_b(so_long, (t_pos){current.x - 1, current.y}))
		|| (fill_exit_b(so_long, (t_pos){current.x + 1, current.y}))
		|| (fill_exit_b(so_long, (t_pos){current.x, current.y - 1}))
		|| (fill_exit_b(so_long, (t_pos){current.x, current.y + 1})))
		return (1);
	return (0);
}
//stating from P, uses recursivity to check all path at different starting point
//function exits if we are in E, A or 1 or outisde the map
//if exit can be taken then path is OK

static int	fill_collectibles_b(t_mlx *so_long, t_pos current)
{
	if (current.x < 0 || current.x >= so_long->row
		|| current.y < 0 || current.y >= so_long->column
		|| so_long->map_tmp[current.x][current.y] == 'E'
		|| so_long->map_tmp[current.x][current.y] == 'V'
		|| so_long->map_tmp[current.x][current.y] == '1'
		|| so_long->map_tmp[current.x][current.y] == 'M')
		return (0);
	if (so_long->map_tmp[current.x][current.y] == 'C')
		so_long->collec_tmp--;
	if (so_long->collec_tmp == 0)
		return (1);
	so_long->map_tmp[current.x][current.y] = 'V';
	if ((fill_collectibles_b(so_long, (t_pos){current.x - 1, current.y}))
		|| (fill_collectibles_b(so_long, (t_pos){current.x + 1, current.y}))
		|| (fill_collectibles_b(so_long, (t_pos){current.x, current.y - 1}))
		|| (fill_collectibles_b(so_long, (t_pos){current.x, current.y + 1})))
		return (1);
	return (0);
}
//stating from P, uses recursivity to check all path at different starting point
//function exits if we are in E, V or 1 or outisde the map
//if we are in C collectibles counter is decremented
//if all collectibles are gathered then path is OK

static int	create_map_tmp_b(t_mlx *so_long)
{
	int	i;

	i = -1;
	so_long->map_tmp = ft_calloc(so_long->row, sizeof(char *));
	if (!so_long->map_tmp)
		destroy_and_tab_b(so_long);
	while (++i < so_long->row)
	{
		so_long->map_tmp[i] = ft_strdup(so_long->map[i]);
		if (!so_long->map_tmp[i])
		{
			while (--i >= 0)
				free(so_long->map_tmp[i]);
			free(so_long->map_tmp);
			destroy_and_tab_b(so_long);
		}
	}
	return (0);
}
//creates a duplicate of so_long map

int	search_path_b(t_mlx *so_long)
{
	create_map_tmp_b(so_long);
	if (fill_collectibles_b(so_long, so_long->p->pos))
	{
		if (fill_exit_b(so_long, so_long->e->pos))
			return (0);
	}
	free_tab_str_tmp(so_long->map_tmp, so_long);
	return (-1);
}
//process of searching a valid path
// → create map copy
// → recursivity to check map until all C are gathered
