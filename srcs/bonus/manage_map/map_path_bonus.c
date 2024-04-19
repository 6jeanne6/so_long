/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:10:43 by jewu              #+#    #+#             */
/*   Updated: 2024/04/19 19:10:47 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// static void	fill(char **map, int rows, int cols, t_pos current)
// {
// 	if (current.x < 0 || current.x >= rows
// 		|| current.y < 0 || current.y >= cols)
// 		return ;
// 	if (map[current.x][current.y] == 'P')
// 	{
// 		fill(map, rows, cols, (t_pos){current.x - 1, current.y});
// 		fill(map, rows, cols, (t_pos){current.x + 1, current.y});
// 		fill(map, rows, cols, (t_pos){current.x, current.y - 1});
// 		fill(map, rows, cols, (t_pos){current.x, current.y + 1});
// 	}
// 	if (map[current.x][current.y] == '0')
// 	{
// 		map[current.x][current.y] = 'V';
// 		fill(map, rows, cols, (t_pos){current.x - 1, current.y});
// 		fill(map, rows, cols, (t_pos){current.x + 1, current.y});
// 		fill(map, rows, cols, (t_pos){current.x, current.y - 1});
// 		fill(map, rows, cols, (t_pos){current.x, current.y + 1});
// 	}
// }
//stating from P, browse map and replace it by V
//allow to define if there is a valid path

// static void	find_collectibles(t_mlx *so_long, t_collec *c)
// {
// 	int	c_index;
// 	int	i;
// 	int	j;

// 	c_index = 0;
// 	i = -1;
// 	c->position = ft_calloc(so_long->collectibles, sizeof(t_position));
// 	if (!c->position)
// 		return ;
// 	while (++i < so_long->row)
// 	{
// 		j = -1;
// 		while (++j < so_long->column)
// 		{
// 			if (so_long->map[i][j] == 'C')
// 			{
// 				// c->position[c_index] = ft_calloc(2, sizeof(int));
// 				// if (!c->position[c_index])
// 				// 	return ;
// 				c->position[c_index].x = i;
// 				c->position[c_index].y = j;
// 				c_index++;
// 			}
// 		}
// 	}
// 	ft_printf("NUmber of x: %d\n", i);
// 	int k = -1;
// 	ft_printf("pos_x: %d\n", c->position[k + 1][c->pos.x]);
//     while (++k < so_long->collectibles)
//         ft_printf("Collectible %d - Position : (%d, %d)\n", k,
// 			c->position[k][c->pos.x], c->position[k][c->pos.y]);
// }
//set each collectible position

static void	set_cpe_on_map(t_mlx *so_long, t_chara *p, t_exit *e)
{
	int		i;
	int		j;

	i = -1;
	while (so_long->map[++i])
	{	
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'P')
			{
				p->pos.x = i;
				p->pos.y = j;
			}
			if (so_long->map[i][j] == 'E')
			{
				e->pos.x = i;
				e->pos.y = j;
			}
			if (so_long->map[i][j] == 'C')
				so_long->collectibles++;
		}
	}
}
//define where is P and E
//define how many C there are

static void	all_null(t_mlx *so_long, t_chara *p, t_collec *c, t_exit *e)
{
	if (!p || !c || !e)
	{
		free_tab_str(so_long->map);
		exit(EXIT_FAILURE);
	}
	p->pos.x = 0;
	p->pos.y = 0;
	p->direction = 0;
	p->step = 1;
	c->pos.x = 0;
	c->pos.y = 0;
	e->pos.x = 0;
	e->pos.y = 0;
	e->all_c = 0;
}
//set all variables to NULL

void	map_set_things(t_mlx *so_long)
{
	//so_long->map_tmp = so_long->map;
	all_null(so_long, so_long->p, so_long->c, so_long->e);
	set_cpe_on_map(so_long, so_long->p, so_long->e);
	// fill(so_long->map_tmp, so_long->row, so_long->column, player.pos);
	// int i = -1;
	// while (++i < so_long->row)
	// 	ft_printf ("Line[%d]: %s\n", i, so_long->map_tmp[i]);
}
//is there a valid path?
// → P must gather all C to go to E