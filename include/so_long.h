/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:53:50 by jewu              #+#    #+#             */
/*   Updated: 2024/04/12 19:30:44 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// **********************************
// *      C language Libraries      *
// **********************************

# include <fcntl.h> //open
# include <unistd.h> //close, read
# include <stdlib.h> //malloc
# include <stdio.h> //perror
# include <string.h> //strerror
# include <errno.h> //perror
# include "libft.h"
# include "mlx.h"

// **********************************
// *     We need colors to debug    *
// **********************************

# define COLOR_RED 		"\033[0;31m"
# define COLOR_GREEN	"\033[0;32m"
# define COLOR_RESET 	"\033[0m"

// **********************************
// *    A game is 1 tile really?    *
// **********************************

# define TILE_SIZE 42

// **********************************
// *          Game assets           *
// **********************************

# define BOMB	"images/xpm/Bomb.xpm"

# define WALL	"images/xpm/Brique.xpm"
# define WALL2	"images/xpm/Brique2.xpm"

# define JIGGY	"images/xpm/Collectible_jiggy.xpm"

# define ENEMY_DOWN	"images/xpm/Enemy.xpm"
# define ENEMY_UP	"images/xpm/Enemy_back.xpm"
# define ENEMY_LEFT	"images/xpm/Enemy_left.xpm"
# define ENEMY_RIGHT	"images/xpm/Enemy_right.xpm"

# define EXIT_CLOSED	"images/xpm/Exit_closed.xpm"
# define EXIT_OPENED	"images/xpm/Exit_open.xpm"

# define EXPLOSION	"images/xpm/Explosion.xpm"

# define VOID	"images/xpm/Purple_Nebula_08.xpm"

# define RENKO_DOWN	"images/xpm/Renko_down.xpm"
# define RENKO_LEFT	"images/xpm/Renko_left.xpm"
# define RENKO_RIGHT	"images/xpm/Renko_right.xpm"
# define RENKO_UP	"images/xpm/Renko_up.xpm"

# define BUSH	"images/xpm/Vegetation_32.xpm"
# define BUSH2	"images/xpm/Vegetation_35.xpm"
# define BUSH3	"images/xpm/Vegetation_46.xpm"
# define BUSH4	"images/xpm/Vegetation_51.xpm"
# define BUSH5	"images/xpm/Vegetation_55.xpm"

// **********************************
// *       Structures are cool      *
// **********************************

typedef struct s_image
{
	void	*mlx_img;

	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;

}				t_image;

typedef struct s_character
{
	int		pos_x;
	int		pos_y;

	t_image	*sprite;

}				t_chara;

typedef struct s_exit
{
	int		pos_x;
	int		pos_y;

	t_image	*exit_open;
	t_image	*exit_close;

}				t_exit;

typedef struct s_collectible
{
	int		pos_x;
	int		pos_y;
	int		collectibles;

	t_image	*jiggy;

}				t_collec;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;

	char	**map;

	int		row;
	int		column;

}				t_mlx;

// **********************************
// *         Parsing functions      *
// **********************************

void	map_init(int argc, char **argv, t_mlx *so_long);
void	map_parsing(t_mlx *so_long);
void	map_set_things(t_mlx *so_long);

// **********************************
// *         Error functions        *
// **********************************

void	message_error(char *message);
void	free_tab_str(char **tab);

#endif 