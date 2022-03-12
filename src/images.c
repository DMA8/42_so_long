/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:36:44 by syolando          #+#    #+#             */
/*   Updated: 2022/03/08 17:48:16 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_map(char *path, t_game *game)
{
	int		fd;
	int		i;
	char	**map;
	int		j;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		fatal("map file feels blue while getting the map");
	i = 0;
	map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map)
		fatal("malloc failed in get_map");
	while (i < game->map_height)
		map[i++] = get_next_line(fd);
	map[i] = 0;
	j = ft_strlen(map[0]);
	game->map_width = j - 1;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i++]) != j)
			clean(map, fd);
	}
	game->map = map;
	close(fd);
}

void	init_textures(t_game *game)
{
	game->img.floor.img = mlx_xpm_file_to_image(game->mlx, XPM_FLOOR,
			&game->img.floor.h, &game->img.floor.w);
	game->img.wall.img = mlx_xpm_file_to_image(game->mlx, XPM_WALL,
			&game->img.wall.h, &game->img.wall.w);
	game->img.exit_a.img = mlx_xpm_file_to_image(game->mlx, XPM_EXIT_A,
			&game->img.exit_a.h, &game->img.exit_a.w);
	game->img.exit_d.img = mlx_xpm_file_to_image(game->mlx, XPM_EXIT_D,
			&game->img.exit_d.h, &game->img.exit_d.w);
	game->img.player_l.img = mlx_xpm_file_to_image(game->mlx, XPM_PL_L,
			&game->img.player_l.h, &game->img.player_l.w);
	game->img.player_r.img = mlx_xpm_file_to_image(game->mlx, XPM_PL_R,
			&game->img.player_r.h, &game->img.player_r.w);
	game->img.obsticles.img = mlx_xpm_file_to_image(game->mlx, XPM_COL,
			&game->img.obsticles.h, &game->img.obsticles.w);
	game->img.cplay.img = game->img.player_r.img;
}

void	put_image(t_game *game, t_img texture, int x, int y)
{
	static int	n;

	mlx_put_image_to_window(game->mlx, game->window, texture.img,
		2 + x * 30, y * 30);
	if (texture.img == game->img.player_l.img
		|| texture.img == game->img.player_r.img)
	{
		game->x_p = x;
		game->y_p = y;
		game->img.cplay.img = texture.img;
		ft_printf("Moves: %d\n", n);
		n++;
	}
}

void	init_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	init_textures(game);
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			put_image(game, game->img.floor, j, i);
			if (game->map[i][j] == '1')
				put_image(game, game->img.wall, j, i);
			else if (game->map[i][j] == 'E')
				put_image(game, game->img.exit_d, j, i);
			if (game->map[i][j] == 'C')
			{
				put_image(game, game->img.obsticles, j, i);
				game->img.tocollect++;
			}
			if (game->map[i][j] == 'P')
				put_image(game, game->img.player_r, j, i);
		}
	}
}
