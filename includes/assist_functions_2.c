/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:11:19 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 12:36:28 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

void	count_assist(int fd, char *line, int max_line_len, int line_num)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line_len > max_line_len)
		max_line_len = line_len;
	printf("Line %d: length = %d\n", line_num, line_len);
	if (line_len != max_line_len)
	{
		printf("Error: Map is not square\n");
		free(line);
		close(fd);
		return (error("Map is not square"));
	}
}

void	verification_recursivity(t_game *game, int y, int x)
{
	if (game->map.grid[y][x] == 'E')
	{
		game->map.exit_found = true;
		return ;
	}
	if (game->map.grid[y][x] == '1' || game->map.grid[y][x] == 'X')
		return ;
	if (game->map.grid[y][x] == 'C')
		game->map.fill_coin++;
	game->map.grid[y][x] = 'X';
	verification_recursivity(game, y + 1, x);
	verification_recursivity(game, y - 1, x);
	verification_recursivity(game, y, x + 1);
	verification_recursivity(game, y, x - 1);
}

char	**copy_map(char **original, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error("Failed to allocate memory for map copy");
	i = 0;
	while (i < height)
	{
		copy[i] = strdup(original[i]);
		if (!copy[i])
			error("Failed to duplicate map row");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	verification(t_game *game)
{
	char	**backup_map;

	game->map.fill_coin = 0;
	game->map.exit_found = false;
	backup_map = copy_map(game->map.grid, game->map.height);
	verification_recursivity(game, game->player.y, game->player.x);
	free_map(backup_map, game->map.height);
}

/*void	verification(t_game *game)
{
	game->map.fill_coin = 0;
	verification_recursivity(game, game->player.y, game->player.x);
}*/

void	check_fill_correct(t_game *game)
{
	if (game->map.exit_found == false)
		return (error("no se encontro salida"));
	if (game->map.fill_coin != game->map.coin)
		return (error("no se pueden recoger todas las monedas"));
}

