/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:20:38 by syolando          #+#    #+#             */
/*   Updated: 2022/03/08 17:43:01 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_fd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(file_name, 2);
		fatal(" file error!");
	}
	close(fd);
}

void	check_textures(void)
{
	check_fd(XPM_FLOOR);
	check_fd(XPM_WALL);
	check_fd(XPM_EXIT_A);
	check_fd(XPM_EXIT_D);
	check_fd(XPM_PL_L);
	check_fd(XPM_PL_R);
	check_fd(XPM_COL);
	check_fd(XPM_BLACK);
	check_fd(XPM_BOSS);
}
