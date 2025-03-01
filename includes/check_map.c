/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:17:59 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 18:32:34 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

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

char	*ft_strstr(char *str, char *to_find)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	while (to_find[len])
	{
		len++;
	}
	if (len == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (to_find[j] == str[i + j])
		{
			if (j + 1 == len)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*newstr;
	size_t	i;

	if (!s1)
		return (NULL);
	newstr = (char *) malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!newstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
