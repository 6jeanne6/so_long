/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:53:50 by jewu              #+#    #+#             */
/*   Updated: 2024/05/06 15:16:00 by jewu             ###   ########.fr       */
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
# include <X11/Xlib.h>
# include <X11/keysym.h>

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

# define WALL2			"images/xpm/Brique2.xpm"

# define JIGGY			"images/xpm/Collectible-jiggy.xpm"

# define EXIT_CLOSED	"images/xpm/Exit_closed.xpm"
# define EXIT_OPENED	"images/xpm/Exit_open.xpm"

# define RENKO_DOWN		"images/xpm/Renko_down.xpm"
# define RENKO_LEFT		"images/xpm/Renko_left.xpm"
# define RENKO_RIGHT	"images/xpm/Renko_right.xpm"
# define RENKO_UP		"images/xpm/Renko_up.xpm"

# define BUSH			"images/xpm/Vegetation_32.xpm"

// **********************************
// *       Structures are cool      *
// **********************************

typedef struct s_position
{
	int		x;
	int		y;

}				t_pos;

typedef struct s_image
{
	void	*mlx_img;

	int		width;
	int		height;

}				t_image;

typedef struct s_character
{
	t_pos		pos;

	int			direction;
	int			step;

}				t_chara;

typedef struct s_exit
{
	t_pos		pos;

	int			all_c;

}				t_exit;

typedef struct s_collectible
{
	t_pos		pos;

	int			**position;

}				t_collec;

typedef struct s_mlx
{
	t_image		*img[9];
	t_collec	*c;
	t_chara		*p;
	t_exit		*e;

	void		*mlx_ptr;
	void		*win_ptr;

	char		**map;
	char		**map_tmp;

	int			leak;
	int			row;
	int			column;
	int			collectibles;
	int			collec_tmp;
	int			current_i;
	int			current_j;

}				t_mlx;

// **********************************
// *         Parsing functions      *
// **********************************

void	map_init(int argc, char **argv, t_mlx *so_long);
void	map_parsing(t_mlx *so_long);
void	map_set_things(t_mlx *so_long);

int		search_path(t_mlx *so_long);
int		map_is_ber(char *argv);

// **********************************
// *         Error functions        *
// **********************************

void	message_error(char *message, t_mlx *so_long);
void	free_tab_str(char **tab);
void	free_tab_str_tmp(char **tab, t_mlx *so_long);

// **********************************
// *         Game and images        *
// **********************************

void	load_images(t_mlx *so_long);
void	put_images(t_mlx *so_long);
void	put_images_exit(t_mlx *so_long, char c);
void	got_exited(t_mlx *so_long, char c);

void	open_exit(t_mlx *so_long);

int		destroy_and_tab(t_mlx *so_long);
int		close_everything(t_mlx *so_long);
int		check_xpm_images(t_mlx *so_long);

void	destroy_so_long(t_mlx *so_long);

// **********************************
// *           Movements            *
// **********************************

int		handle_keypress(int key, t_mlx *so_long);

void	move_up(t_mlx *so_long, t_chara *p);
void	move_down(t_mlx *so_long, t_chara *p);
void	move_left(t_mlx *so_long, t_chara *p);
void	move_right(t_mlx *so_long, t_chara *p);

#endif 