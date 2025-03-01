/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:32:13 by iziat-hi          #+#    #+#             */
/*   Updated: 2024/11/17 10:29:44 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

char	*assign_floor(t_0 *floor)
{
	int			i;
	char		*path;

	path = NULL;
	floor->one = "./a/0/brick.xpm";
	floor->two = "./a/0/grass.xpm";
	floor->three = "./a/0/patron1.xpm";
	floor->four = "./a/0/patron2.xpm";
	floor->five = "./a/0/patron3.xpm";
	i = randomizer(1, 5);
	if (i == 1)
		path = floor->one;
	else if (i == 2)
		path = floor->two;
	else if (i == 3)
		path = floor->three;
	else if (i == 4)
		path = floor->four;
	else if (i == 5)
		path = floor->five;
	printf("pathfloor = %s\n", path);
	return (path);
}

char	*assign_wall(t_1 *wall)
{
	int		i;
	char	*path;

	path = NULL;
	wall->one = "./a/1/arbol.xpm";
	wall->two = "./a/1/water1.xpm";
	wall->three = "./a/1/statua.xpm";
	wall->four = "./a/1/fire1.xpm";
	i = randomizer(1, 4);
	if (i == 1)
		path = "./a/1/arbol.xpm";
	else if (i == 2)
		path = "./a/1/water1.xpm";
	else if (i == 3)
		path = "./a/1/statua.xpm";
	else if (i == 4)
		path = "./a/1/fire1.xpm";
	printf("pathwall = %s\n", path);
	return (path);
}

char	*assign_player(t_p *player)
{
	int		i;
	char	*path;

	path = NULL;
	player->one = "./a/p/p1/p1d1.xpm";
	player->two = "./a/p/p2/p2d1.xpm";
	i = randomizer(1, 2);
	if (i == 1)
		path = "./a/p/p1/p1d1.xpm";
	else if (i == 2)
		path = "./a/p/p2/p2d1.xpm";
	printf("pathplayer = %s\n", path);
	return (path);
}
