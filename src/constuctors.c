/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constuctors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:36:31 by syolando          #+#    #+#             */
/*   Updated: 2022/03/07 19:58:18 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map_valid(t_map_valid *new_struct)
{
	new_struct->exit = 0;
	new_struct->coll = 0;
	new_struct->player = 0;
	new_struct->valid = 1;
	new_struct->wall = 0;
	new_struct->width = 0;
	new_struct->bottom_ok = 0;
	new_struct->top_ok = 0;
}

void	init_new_game(t_game *game)
{
	game -> map_width = 0;
	game -> map_height = 0;
	game -> x_p = 0;
	game -> y_p = 0;
	game -> numb_move = 0;
}
