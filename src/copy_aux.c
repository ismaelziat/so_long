/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:57:56 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 12:10:12 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

void	c_init_game(const char *map_path, t_game *game)
{
	int	w_width;
	int	w_height;

	c_count_map_lines(map_path, game);
	c_count_x_y(map_path, game, &w_width, &w_height);
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

void	c_count_map_lines(const char *file_path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error("Error opening map file");
	game->map.height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		game->map.height++;
		line = get_next_line(fd);
	}
	close(fd);
	game->map.grid = (char **)malloc(sizeof(char *) * game->map.height);
	if (!game->map.grid)
		error("Memory allocation failed for map");
}

void	c_count_x_y(const char *map_path, t_game *game, int *w_w, int *w_h)
{
	int		fd;
	int		max_line_len;
	int		height;

	max_line_len = 0;
	height = 0;
	fd = open(map_path, O_RDONLY);
	game->map.width = 0;
	game->map.height = 0;
	read_map_lines(fd, &max_line_len, &height);
	close(fd);
	game->map.width = max_line_len;
	game->map.height = height;
	game->map.grid = (char **)malloc(sizeof(char *) * game->map.height);
	map_grid_error(game);
	*w_w = game->map.width * T_S;
	*w_h = game->map.height * T_S;
	printf("valor de x = %d\n", game->map.width);
	printf("valor de y = %d\n", game->map.height);
}