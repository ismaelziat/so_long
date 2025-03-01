/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:21:18 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 13:10:17 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

int	key_hook(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
	{
		close_window(g);
		exit(0);
	}
	else if (keycode == KEY_UP)
		move_up(g);
	else if (keycode == KEY_LEFT)
		move_left(g);
	else if (keycode == KEY_DOWN)
		move_down(g);
	else if (keycode == KEY_RIGHT)
		move_right(g);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wi);
	mlx_destroy_display(game->mlx);
	exit(0);
	return (0);
}

void	init_game(const char *map_path, t_game *game)
{
	int	w_width;
	int	w_height;

	count_map_lines(map_path, game);
	count_x_y(map_path, game, &w_width, &w_height);
	printf("Width: %d, Height: %d\n", w_width, w_height);
	game->mlx = mlx_init();
	if (!game->mlx)
		error("Failed to initialize MLX");
	game->wi = mlx_new_window(game->mlx, w_width, w_height, "Game Title");
	if (!game->wi)
		error("Failed to create window");
	load_sprites(game);
	load_map_content(map_path, game);
	process_map(game);
	verification(game);
	check_fill_correct(game);
	mlx_key_hook(game->wi, key_hook, game);
}

void	start_game(t_game *game)
{
	mlx_loop(game->mlx);
}
