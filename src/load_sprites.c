/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:55:13 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 11:34:11 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

void	load_sprites(t_game *g)
{
	t_1		w;
	t_p		p;
	char	*ball;

	ball = "./a/c/pokeball.xpm";
	g->size = 64;
	g->w = mlx_xpm_file_to_image(g->mlx, assign_wall(&w), &g->size, &g->size);
	g->f = mlx_xpm_file_to_image(g->mlx, "./a/0/grass.xpm", &g->size, &g->size);
	g->p = mlx_xpm_file_to_image(g->mlx, assign_player(&p), &g->size, &g->size);
	g->c = mlx_xpm_file_to_image(g->mlx, ball, &g->size, &g->size);
	g->e = mlx_xpm_file_to_image(g->mlx, "./a/e/exit1.xpm", &g->size, &g->size);
	verify_xpm(g->w, "wall");
	verify_xpm(g->f, "floor");
	verify_xpm(g->p, "player");
	verify_xpm(g->c, "coin");
	verify_xpm(g->e, "exit");
	g->map.exit = 0;
	g->map.player = 0;
	g->map.coin = 0;
}

/* 	printf("g->mlx = %p\n", g->mlx);
	printf("g->w = %p\n", g->w);
	printf("g->mlx = %p\n", g->f);
	printf("g->w = %p\n", g->p);
	printf("g->mlx = %p\n", g->c);
	printf("g->w = %p\n", g->e); */

void	count_map_lines(const char *file_path, t_game *game)
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

void	load_map_content(const char *file_path, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error("Error opening map file");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map.grid[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	if (game->map.height > 0)
		game->map.width = ft_strlen(game->map.grid[0]);
	else
		game->map.width = 0;
}

void	process_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == 'P')
			{
				mlx_put_image_to_window(g->mlx, g->wi, g->p, x * T_S, y * T_S);
				g->player.x = x;
				g->player.y = y;
				g->map.player++;
				printf("number of player is %i\n", g->map.player);
			}
			else
				process_map_part_2(g, x, y);
			x++;
		}
		y++;
	}
	check_number_of_elements(g);
}

void	render_game(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->wi, g->w, T_S, T_S);
			else if (g->map.grid[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->wi, g->f, T_S, T_S);
			else if (g->map.grid[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->wi, g->c, T_S, T_S);
			else if (g->map.grid[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->wi, g->e, T_S, T_S);
			else if (g->map.grid[y][x] == 'P')
				mlx_put_image_to_window(g->mlx, g->wi, g->p, T_S, T_S);
			x++;
		}
		y++;
	}
}
