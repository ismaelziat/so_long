/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:36:28 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 19:26:29 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

void	win_game(t_game *g, int new_y, int new_x)
{
	if ((g->map.grid[new_y][new_x] == 'E') && (g->door_open == 1))
	{
		free_map_2025(g, g->map.height);
		close_window(g);
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

void	free_map_2025(t_game *game, int height)
{
	int	i;

	if (!game->map.grid)
		return ;
	i = 0;
	while (i < height)
	{
		free(game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
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
