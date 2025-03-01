/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:17:59 by iziat-hi          #+#    #+#             */
/*   Updated: 2024/11/17 11:42:54 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

int	verify_xpm(const char *filename, char *name)
{
	char	*xpm;

	xpm = ".xpm";
	if (strstr(filename, xpm) != NULL)
		return (printf("%s no es xpm\n", name), 1);
	else
		return (printf("%s es xpm\n", name), 0);
}

void	check_number_of_elements(t_game *game)
{
	if (game->map.coin == 0)
		error("no coins in map!!!");
	if (game->map.player != 1)
		error("number of player in the map is not 1!!!");
	if (game->map.exit != 1)
	{
		printf("number of EXIT is %i\n", game->map.exit);
		error("incorrect number of exits on the map!!!");
	}
	game->door_open = 0;
	game->collected_coins = 0;
	printf("number of EXIT is %i\n", game->map.exit);
	printf("number of player is %i\n", game->map.player);
	printf("number of coins is %i\n", game->map.coin);
}
