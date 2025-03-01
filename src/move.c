/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:21 by iziat-hi          #+#    #+#             */
/*   Updated: 2024/09/09 16:56:45 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

void	move_up(t_game *g)
{
	int	new_x;
	int	new_y;

	new_x = g->player.x;
	new_y = g->player.y;
	mlx_put_image_to_window(g->mlx, g->wi, g->f, new_x * T_S, new_y * T_S);
	new_y--;
	if (g->map.grid[new_y][new_x] == '1')
	{
		printf("te mueves a un muro!!\n");
		new_y++;
	}
	if ((g->map.grid[new_y][new_x] == 'E') && (g->door_open == 0))
	{
		printf("puerta cerrada!!\n");
		mlx_put_image_to_window(g->mlx, g->wi, g->e, new_x * T_S, new_y * T_S);
		new_y++;
	}
	mlx_put_image_to_window(g->mlx, g->wi, g->p, new_x * T_S, new_y * T_S);
	printf("posicion del jugador %i, %i\n", new_x, new_y);
	can_you_move(g, new_y, new_x);
}

void	move_down(t_game *g)
{
	int	new_x;
	int	new_y;

	new_x = g->player.x;
	new_y = g->player.y;
	mlx_put_image_to_window(g->mlx, g->wi, g->f, new_x * T_S, new_y * T_S);
	new_y++;
	if (g->map.grid[new_y][new_x] == '1')
	{
		printf("te mueves a un muro!!\n");
		new_y--;
	}
	if ((g->map.grid[new_y][new_x] == 'E') && (g->door_open == 0))
	{
		printf("puerta cerrada!!\n");
		mlx_put_image_to_window(g->mlx, g->wi, g->e, new_x * T_S, new_y * T_S);
		new_y--;
	}
	mlx_put_image_to_window(g->mlx, g->wi, g->p, new_x * T_S, new_y * T_S);
	printf("posicion del jugador %i, %i\n", new_x, new_y);
	can_you_move(g, new_y, new_x);
}

void	move_left(t_game *g)
{
	int	new_x;
	int	new_y;

	new_x = g->player.x;
	new_y = g->player.y;
	mlx_put_image_to_window(g->mlx, g->wi, g->f, new_x * T_S, new_y * T_S);
	new_x--;
	if (g->map.grid[new_y][new_x] == '1')
	{
		printf("te mueves a un muro!!\n");
		new_x++;
	}
	if ((g->map.grid[new_y][new_x] == 'E') && (g->door_open == 0))
	{
		printf("puerta cerrada!!\n");
		mlx_put_image_to_window(g->mlx, g->wi, g->e, new_x * T_S, new_y * T_S);
		new_x++;
	}
	mlx_put_image_to_window(g->mlx, g->wi, g->p, new_x * T_S, new_y * T_S);
	printf("posicion del jugador %i, %i\n", new_x, new_y);
	can_you_move(g, new_y, new_x);
}

void	move_right(t_game *g)
{
	int	new_x;
	int	new_y;

	new_x = g->player.x;
	new_y = g->player.y;
	mlx_put_image_to_window(g->mlx, g->wi, g->f, new_x * T_S, new_y * T_S);
	new_x++;
	if (g->map.grid[new_y][new_x] == '1')
	{
		printf("te mueves a un muro!!\n");
		new_x--;
	}
	if ((g->map.grid[new_y][new_x] == 'E') && (g->door_open == 0))
	{
		printf("puerta cerrada!!\n");
		mlx_put_image_to_window(g->mlx, g->wi, g->e, new_x * T_S, new_y * T_S);
		new_x--;
	}
	mlx_put_image_to_window(g->mlx, g->wi, g->p, new_x * T_S, new_y * T_S);
	printf("posicion del jugador %i, %i\n", new_x, new_y);
	can_you_move(g, new_y, new_x);
}

void	can_you_move(t_game *g, int new_y, int new_x)
{
	if (new_x >= 0 && new_x < g->map.width
		&& new_y >= 0 && new_y < g->map.height)
	{
		if (g->map.grid[new_y][new_x] != '1')
		{
			g->player.x = new_x;
			g->player.y = new_y;
		}
		if (g->map.grid[new_y][new_x] == 'C')
		{
			g->collected_coins++;
			printf("moneda recogida!!\n");
			if (g->collected_coins == g->map.coin)
			{
				printf("tienes todas las monedas\n");
				g->door_open = 1;
			}
		}
		win_game(g, new_y, new_x);
	}
}
