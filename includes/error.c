/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:36:28 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 11:37:43 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

void	win_game(t_game *g, int new_y, int new_x)
{
	if ((g->map.grid[new_y][new_x] == 'E') && (g->door_open == 1))
	{
		close_window(g);
		printf("has ganado \n");
	}
}

void	error(const char *message)
{
	perror(message);
	exit(1);
}

void	check_perimeters(t_game *game)
{
	int	x;
	int	y;
	int	z;

	x = game->map.width - 1;
	y = game->map.height;
	z = game->map.width - 1;
	while (x--)
	{
		if (game->map.grid[0][x] != '1' || game->map.grid[y - 1][x] != '1')
			error("\nmap is not closed\n");
	}
	while (y--)
	{
		if (game->map.grid[y][0] != '1' || game->map.grid[y][z - 1] != '1')
			error("\nmap is not closed\n");
	}
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}