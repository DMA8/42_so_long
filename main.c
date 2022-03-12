/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:37:21 by syolando          #+#    #+#             */
/*   Updated: 2022/03/08 17:42:45 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc);
	check_textures();
	init_new_game(&game);
	valid_file(argv[1], &game);
	get_map(argv[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		fatal("mlx init failed!");
	game.window = mlx_new_window(game.mlx, game.map_width * 30 + 5,
			game.map_height * 30 + 5, "so_long");
	if (!game.window)
		fatal("mlx new window failed!");
	init_map(&game);
	mlx_hook(game.window, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.window, 17, 1L << 0, mouse_hook, &game);
	mlx_loop(game.mlx);
}
