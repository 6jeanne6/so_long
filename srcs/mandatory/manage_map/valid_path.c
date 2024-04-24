/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:47:55 by jewu              #+#    #+#             */
/*   Updated: 2024/04/24 20:04:29 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	i_went_everywhere(t_mlx *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (++i < so_long->row)
	{
		j = -1;
		while (++j < so_long->column)
		{
			if (so_long->map_tmp[i][j] == '0')
				return ;
		}
	}
	so_long->zeros = 1;
}
//check if entire map and all path have been checked

static int	fill_exit(t_mlx *so_long, t_pos current)
{
	if (current.x < 0 || current.x >= so_long->row
		|| current.y < 0 || current.y >= so_long->column
		|| so_long->map_tmp[current.x][current.y] == '1'
		|| so_long->map_tmp[current.x][current.y] == 'A')
		return (0);
	so_long->map_tmp[current.x][current.y] = 'A';
	if (so_long->collec_tmp == 0
		&& so_long->map_tmp[current.x][current.y] == 'E')
		return (1);
	if ((fill_exit(so_long, (t_pos){current.x - 1, current.y}))
		|| (fill_exit(so_long, (t_pos){current.x + 1, current.y}))
		|| (fill_exit(so_long, (t_pos){current.x, current.y - 1}))
		|| (fill_exit(so_long, (t_pos){current.x, current.y + 1})))
		return (1);
	return (0);
}
//stating from P, uses recursivity to check all path at different starting point
//function exits if we are in E, A or 1 or outisde the map
//if exit can be taken then path is OK

static int	fill_collectibles(t_mlx *so_long, t_pos current)
{
	if (current.x < 0 || current.x >= so_long->row
		|| current.y < 0 || current.y >= so_long->column
		|| so_long->map_tmp[current.x][current.y] == 'E'
		|| so_long->map_tmp[current.x][current.y] == 'V'
		|| so_long->map_tmp[current.x][current.y] == '1')
		return (0);
	if (so_long->map_tmp[current.x][current.y] == 'C')
		so_long->collec_tmp--;
	if (so_long->collec_tmp == 0)
	{
		i_went_everywhere(so_long);
		if (so_long->zeros == 1)
			return (1);
	}
	so_long->map_tmp[current.x][current.y] = 'V';
	if ((fill_collectibles(so_long, (t_pos){current.x - 1, current.y}))
		|| (fill_collectibles(so_long, (t_pos){current.x + 1, current.y}))
		|| (fill_collectibles(so_long, (t_pos){current.x, current.y - 1}))
		|| (fill_collectibles(so_long, (t_pos){current.x, current.y + 1})))
		return (1);
	return (0);
}
//stating from P, uses recursivity to check all path at different starting point
//function exits if we are in E, V or 1 or outisde the map
//if we are in C collectibles counter is decremented
//if all collectibles are gathered then path is OK

static int	create_map_tmp(t_mlx *so_long)
{
	int	i;

	i = -1;
	so_long->map_tmp = ft_calloc(so_long->column, sizeof(char *));
	if (!so_long->map_tmp)
		destroy_and_tab(so_long);
	while (++i < so_long->row)
	{
		so_long->map_tmp[i] = ft_strdup(so_long->map[i]);
		if (!so_long->map_tmp[i])
		{
			while (--i >= 0)
				free(so_long->map_tmp[i]);
			free(so_long->map_tmp);
			destroy_and_tab(so_long);
		}
	}
	i = -1;
	while (++i < so_long->row)
		ft_printf ("Line[%d] im map_tmp: %s\n", i, so_long->map_tmp[i]);
	return (0);
}
//creates a duplicate of so_long map

int	search_path(t_mlx *so_long)
{
	create_map_tmp(so_long);
	if (fill_collectibles(so_long, so_long->p->pos))
	{
		int i = -1;
		while (++i < so_long->row)
			ft_printf ("Line[%d] im map_tmp after fill_collec: %s\n", i, so_long->map_tmp[i]);
		if (fill_exit(so_long, so_long->p->pos))
		{
			i = -1;
			while (++i < so_long->row)
				ft_printf ("Line[%d] im map_tmp after fill_exit: %s\n", i, so_long->map_tmp[i]);
			return (0);
		}
	}
	free_tab_str(so_long->map_tmp);
	return (-1);
}
//process of searching a valid path
// → create map copy
// → recursivity to check map until all C are gathered
