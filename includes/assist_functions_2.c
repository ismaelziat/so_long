/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:11:19 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 19:00:06 by iziat-hi         ###   ########.fr       */
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
	if (game->backup_map[y][x] == 'E')
	{
		game->map.exit_found = true;
		return ;
	}
	if (game->backup_map[y][x] == '1' || game->backup_map[y][x] == 'X')
		return ;
	if (game->backup_map[y][x] == 'C')
		game->map.fill_coin++;
	game->backup_map[y][x] = 'X';
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
	i = 0;
	printf("ORIGINAL\n");
	while (i < height)
		printf("%s\n", original[i++]);
	i = 0;
	printf("\n");
	printf("NUEVO\n");
	while (i < height)
		printf("%s\n", copy[i++]);
	return (copy);
}

void	verification(t_game *game)
{
	game->map.fill_coin = 0;
	game->map.exit_found = false;
	game->backup_map = copy_map(game->map.grid, game->map.height);
	verification_recursivity(game, game->player.y, game->player.x);
	free_map(game->backup_map, game->map.height);
}

void	check_fill_correct(t_game *game)
{
	if (game->map.exit_found == false)
		return (error("no se encontro salida"));
	if (game->map.fill_coin != game->map.coin)
		return (error("no se pueden recoger todas las monedas"));
}

