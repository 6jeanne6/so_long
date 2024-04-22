/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:55:46 by jewu              #+#    #+#             */
/*   Updated: 2024/04/22 18:22:21 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# include <SDL2/SDL.h>
//# include <SDL2/SDL_mixer.h>

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

# define JIGGY	"images/xpm/Collectible-jiggy.xpm"

# define ENEMY_DOWN	"images/xpm/Enemy_down.xpm"
# define ENEMY_UP	"images/xpm/Enemy_up.xpm"
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

// typedef struct s_music
// {
// 	void	*music_ptr;
// 	void	*sfx_ptr;
// }				t_music;

typedef struct s_position
{
	int		x;
	int		y;

}				t_pos;

typedef struct s_mob
{
	t_pos	pos;

	int		mobs;

}				t_mob;

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
	t_image		*img[13];
	t_collec	*c;
	t_chara		*p;
	t_exit		*e;
	t_mob		*m;

	void		*mlx_ptr;
	void		*win_ptr;

	char		**map;
	char		**map_tmp;

	int			leak;
	int			row;
	int			column;
	int			collectibles;
	int			current_i;
	int			current_j;

}				t_mlx;

// **********************************
// *         Parsing functions      *
// **********************************

void	map_init_b(int argc, char **argv, t_mlx *so_long);
void	map_parsing_b(t_mlx *so_long);
void	where_is_enemy(t_mlx *so_long);
void	map_set_things_b(t_mlx *so_long);

// **********************************
// *         Error functions        *
// **********************************

void	message_error_b(char *message, t_mlx *so_long);
void	free_tab_str_b(char **tab);

// **********************************
// *         Game and images        *
// **********************************

void	load_images_b(t_mlx *so_long);
void	put_images_b(t_mlx *so_long);
void	put_images_exit_b(t_mlx *so_long, char c);
void	got_exited_b(t_mlx *so_long, char c);
void 	enemy_sprite(t_mlx *so_long);

void	open_exit_b(t_mlx *so_long);

int		close_everything_b(t_mlx *so_long);
void	destroy_so_long_b(t_mlx *so_long);

// **********************************
// *           Movements            *
// **********************************

int		handle_keypress_b(int key, t_mlx *so_long);

void	move_up_b(t_mlx *so_long, t_chara *p);
void	move_down_b(t_mlx *so_long, t_chara *p);
void	move_left_b(t_mlx *so_long, t_chara *p);
void	move_right_b(t_mlx *so_long, t_chara *p);

#endif 