/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:37:14 by syolando          #+#    #+#             */
/*   Updated: 2022/03/08 18:49:49 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<mlx.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>

# include	"libft/libft.h"
# include	"src/gnl/get_next_line.h"

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

# define XPM_FLOOR "./img/floor.XPM"
# define XPM_WALL "./img/wall.XPM"
# define XPM_EXIT_A "./img/exit_a.XPM"
# define XPM_EXIT_D "./img/exit_d.XPM"
# define XPM_PL_L "./img/pl_L.XPM"
# define XPM_PL_R "./img/pl_R.XPM"
# define XPM_COL "./img/col.XPM"

typedef struct s_img
{
	void	*img;
	int		h;
	int		w;
}	t_img;

typedef struct s_map_valid
{
	int	coll;
	int	wall;
	int	exit;
	int	player;
	int	valid;
	int	width;
	int	top_ok;
	int	bottom_ok;
}	t_map_valid;

typedef struct s_textures
{
	t_img	floor;
	t_img	wall;
	t_img	exit_a;
	t_img	exit_d;
	t_img	player_l;
	t_img	player_r;
	t_img	obsticles;
	t_img	cplay;
	int		tocollect;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	t_textures	img;
	int			map_width;
	int			map_height;
	int			x_p;
	int			y_p;
	int			numb_move;
}	t_game;

void			fatal(char *msg);
void			check_textures(void);
void			check_args(int argc);
void			valid_file(char *path, t_game *game);
void			init_map_valid(t_map_valid *new_struct);
void			init_new_game(t_game *game);
t_textures		*new_textures(void);
void			wipe(char *s1, char *s2, int fd);
int				check_top_bottom_line(char *str, int top_bottom, int width);
void			get_map(char *path, t_game *game);
void			clean(char **map, int fd);
void			init_map(t_game *game);
void			free_map(char **map);
void			put_image(t_game *game, t_img texture, int x, int y);
int				key_hook(int key, t_game *game);
int				mouse_hook(t_game *game);
void			destroy_game(t_game *game, char *s);
int				check_wrong_chars(char c);
void			open_exits(t_game *game);

#endif
