/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:36:51 by syolando          #+#    #+#             */
/*   Updated: 2022/03/07 23:22:22 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_top_bottom_line(char *str, int top_bottom, int width)
{
	int	i;
	int	n_wals;

	i = 0;
	if (!str)
		return (1);
	if (top_bottom == 0)
		n_wals = ft_strlen(str) - 1;
	else
		n_wals = width;
	while (str[i] && str[i] == '1')
		i++;
	return (i == n_wals);
}

int	check_wrong_chars_b(char c)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'C'
		&& c != 'P' && c != '\n' && c != 0 && c != 'B')
		return (0);
	return (1);
}
