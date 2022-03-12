/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:37:03 by syolando          #+#    #+#             */
/*   Updated: 2022/03/07 20:18:01 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_args(int argc)
{
	if (argc == 1)
		fatal("give me a path to the map you want to run!");
	if (argc > 2)
		fatal("too much arguments!");
}

int	check_middle_line(char *s0, t_map_valid *map)
{
	int	i;

	i = 0;
	if (!s0)
		return (1);
	if (ft_strlen(s0) != map->width + 1)
		return (0);
	if (s0[0] != '1' || s0[ft_strlen(s0) - 2] != '1')
		return (0);
	while (s0[i])
	{
		if (s0[i] == 'P')
			map->player++;
		else if (s0[i] == 'C')
			map->coll++;
		else if (s0[i] == 'E')
			map->exit++;
		if (!check_wrong_chars(s0[i]))
			map->valid = 0;
		i++;
	}
	return (1);
}

int	check_map_valid(t_map_valid	*map)
{
	int	res;

	res = 200;
	if (!map->bottom_ok || !map->top_ok || !map->valid)
		res = 0;
	else if (map->player != 1 || !map->coll || !map->exit)
		res = 1;
	if (res == 0)
		fatal("check map!");
	else if (res == 1)
		fatal("check player/collectable/exits!");
	return (1);
}

int	my_validate(int fd, char *s, t_game *game)
{
	char		*s2;
	t_map_valid	map;
	int			flag;

	init_map_valid(&map);
	flag = 1;
	map.top_ok = check_top_bottom_line(s, 0, 0);
	map.width = ft_strlen(s) - 1;
	s2 = get_next_line(fd);
	while (flag && s && s[0] != 0)
	{
		flag = check_middle_line(s2, &map);
		if (!flag)
			map.valid = 0;
		free(s2);
		s2 = ft_strdup(s);
		free(s);
		s = get_next_line(fd);
		game -> map_height++;
	}
	game -> map_height++;
	map.bottom_ok = check_top_bottom_line(s2, 1, map.width);
	wipe(s, s2, fd);
	return (check_map_valid(&map));
}

void	valid_file(char *path, t_game *game)
{
	int		fd;
	char	*line;

	if (ft_strlen(path) < 4)
		fatal("\nvalid map name is needed!\n");
	if (ft_memcmp(path + ft_strlen(path) - 4, ".ber", 4))
		fatal("\nfileName shoud ends with \".ber\"\n");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		fatal("\nmap is not found\n");
	line = get_next_line(fd);
	if (!line)
		fatal("\nempty map!\n");
	my_validate(fd, line, game);
}
