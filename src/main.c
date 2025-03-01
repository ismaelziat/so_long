/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:11:04 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 12:18:38 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_game		game;
	//t__c_game	c_game;

	if (argc != 2)
	{
		error("Usage: ./so_long <map_file>");
		return (1);
	}
	init_game(argv[1], &game);
	start_game(&game);
	render_game(&game);
	return (0);
} 