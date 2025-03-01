/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:12:27 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/02/15 14:33:47 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

void	map_grid_error(t_game *game)
{
	if (!game->map.grid)
		error("Memory allocation failed for map");
}

void	process_map_part_2(t_game *g, int x, int y)
{
	if (g->map.grid[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->wi, g->w, x * T_S, y * T_S);
	else if (g->map.grid[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->wi, g->f, x * T_S, y * T_S);
	else if (g->map.grid[y][x] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->wi, g->c, x * T_S, y * T_S);
		g->map.coin++;
		printf("number of coin is %i", g->map.coin);
	}
	else if (g->map.grid[y][x] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->wi, g->e, x * T_S, y * T_S);
		g->map.exit++;
	}
	else if ((g->map.grid[y][x] != '\n') && (g->map.grid[y][x] != '\0'))
	{
		printf("unvalid map, unvalid character found");
		close_window(g);
	}
}

void	read_map_lines(int fd, int *max_line_len, int *height)
{
	char	*line;
	int		line_num;
	int		line_length;

	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		line_length = (int)ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line_length--;
		if (line_length > *max_line_len)
			*max_line_len = line_length;
		if (line_length != *max_line_len)
		{
			printf("Map not square \n");
			free(line);
			return (error("Map is not square"));
		}
		free(line);
		(*height)++;
		line_num++;
	}
}

void	count_x_y(const char *map_path, t_game *game, int *w_w, int *w_h)
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

/* void	count_x_y(const char *map_path, t_game *game, int *w_w, int *w_h)
{
int		fd;
char	*line;
int		max_line_len;
int		line_num;
int line_length;

max_line_len = 0;
fd = open(map_path, O_RDONLY);
game->map.width = 0;
game->map.height = 0;
line = get_next_line(fd);
line_num = 1;
while (line != NULL)
{
	line_length = (int)ft_strlen(line);
	if (line[line_length - 1] == '\n')
		line_length--;
	if (line_length > max_line_len)
		max_line_len = line_length;
	if (line_length != max_line_len)
	{
		printf("Error: Map is not square \n", line_length, max_line_len, line_num);
		free(line);
		close(fd);
		return error("Map is not square");
	}
	free(line);
	game->map.height++;
	line = get_next_line(fd);
	line_num++;
}
close(fd);
game->map.width = max_line_len;
game->map.grid = (char **)malloc(sizeof(char *) * game->map.height);
map_grid_error(game);
*w_w = game->map.width * T_S;
*w_h = game->map.height * T_S;
} */

void	process_background(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			mlx_put_image_to_window(g->mlx, g->wi, g->w, T_S, T_S);
			x++;
		}
		y++;
	}
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big != '\0' && len-- >= little_len)
	{
		if (*big == *little && ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		printf("valor de strnstr es %s %s \n", big, little);
	}
	return (NULL);
}
