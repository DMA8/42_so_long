/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:28:31 by syolando          #+#    #+#             */
/*   Updated: 2022/03/08 17:53:56 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move(t_game *game, int j, int i, int incr)
{
	if ((game->x_p == j + incr) && (game->y_p == i))
		destroy_game(game, "YOU HAS BEEN KILLED!");
	game->map[i][j] = '0';
	game->map[i][j + incr] = 'B';
	put_image(game, game->img.floor, j, i);
	put_image(game, game->img.boss, j + incr, i);
}

void	move_enemy(t_game *game)
{
	int	j;
	int	i;

	i = -1;
	while (++i < game->map_height - 1)
	{
		j = -1;
		while (++j < game -> map_width - 1)
		{
			if (game->map[i][j] == 'B' && game->map[i][j + 1] == '0')
			{
				move(game, j, i, 1);
				break ;
			}
			else if (game->map[i][j] == 'B' && game->map[i][j - 1] == '0')
			{
				move(game, j, i, -1);
				break ;
			}
		}
	}
}

int	animate(t_game *game)
{
	game->anim_c++;
	if (game->anim_c % ANIMATION_SPEED == 0)
		move_enemy(game);
	return (0);
}
