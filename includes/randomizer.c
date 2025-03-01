/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:10:33 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 13:56:00 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"

unsigned int	open_urandom(void)
{
	int				fd;
	unsigned int	random_value;
	ssize_t			result;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	result = read(fd, &random_value, sizeof(random_value));
	if (result != sizeof(random_value))
	{
		perror("read");
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (close(fd) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	return (random_value);
}

int	randomizer(int min, int max)
{
	unsigned int	random_value;
	int				range;

	if (min > max)
		return (-1);
	random_value = open_urandom();
	range = max - min + 1;
	return ((random_value % range) + min);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
