/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:36:36 by syolando          #+#    #+#             */
/*   Updated: 2022/03/08 14:05:26 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_game(t_game *game, char *s)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img.floor.img);
	mlx_destroy_image(game->mlx, game->img.wall.img);
	mlx_destroy_image(game->mlx, game->img.exit_a.img);
	mlx_destroy_image(game->mlx, game->img.obsticles.img);
	mlx_destroy_image(game->mlx, game->img.player_l.img);
	mlx_destroy_image(game->mlx, game->img.player_r.img);
	mlx_destroy_window(game->mlx, game->window);
	ft_printf("%s\n", s);
	exit(0);
}

int	mouse_hook(t_game *game)
{
	destroy_game(game, "Game was closed with mouse!");
	return (0);
}

int	is_step_possible(t_game *game, int dx, int dy)
{
	if (game->map[game->y_p + dy][game->x_p + dx] == 'C')
	{
		game->img.tocollect--;
		game->map[game->y_p + dy][game->x_p + dx] = '0';
		put_image(game, game->img.floor, game->x_p + dx, game->y_p + dy);
	}
	if (!game->img.tocollect)
		open_exits(game);
	if (game->map[game->y_p + dy][game->x_p + dx] == '1')
		return (0);
	if (game->map[game->y_p + dy][game->x_p + dx] == 'E'
		&& game->img.tocollect)
		return (0);
	if (game->map[game->y_p + dy][game->x_p + dx] == 'E'
		&& !game->img.tocollect)
	{
		put_image(game, game->img.cplay, game->y_p + dy,
			game->x_p + dx);
		destroy_game(game, "You WON!");
	}
	return (1);
}

void	play_game(t_game *game, int key)
{
	if (key == W && is_step_possible(game, 0, -1))
	{
		put_image(game, game->img.floor, game->x_p, game->y_p);
		put_image(game, game->img.cplay, game->x_p, game->y_p - 1);
	}
	if (key == A && is_step_possible(game, -1, 0))
	{
		put_image(game, game->img.floor, game->x_p, game->y_p);
		put_image(game, game->img.player_l, game->x_p - 1, game->y_p);
	}
	if (key == S && is_step_possible(game, 0, 1))
	{
		put_image(game, game->img.floor, game->x_p, game->y_p);
		put_image(game, game->img.cplay, game->x_p, game->y_p + 1);
	}
	if (key == D && is_step_possible(game, 1, 0))
	{
		put_image(game, game->img.floor, game->x_p, game->y_p);
		put_image(game, game->img.player_r, game->x_p + 1, game->y_p);
	}	
}

int	key_hook(int key, t_game *game)
{	
	if (key == ESC)
		destroy_game(game, "ESC pressed!");
	if (key == W || key == A || key == S || key == D)
		play_game(game, key);
	return (0);
}
