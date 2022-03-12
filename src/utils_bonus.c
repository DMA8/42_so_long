/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:38:41 by syolando          #+#    #+#             */
/*   Updated: 2022/03/08 17:38:54 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	fatal(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	wipe(char *s1, char *s2, int fd)
{
	free(s1);
	free(s2);
	close(fd);
}

void	clean(char **map, int fd)
{
	int	i;

	i = 0;
	close(fd);
	while (map[i])
		free(map[i++]);
	free(map);
	fatal("bad map!");
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
}

void	open_exits(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'E')
			{
				put_image(game, game->img.floor, j, i);
				put_image(game, game->img.exit_a, j, i);
			}
			j++;
		}
		i++;
	}
}
