/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:24:39 by iziat-hi          #+#    #+#             */
/*   Updated: 2024/08/16 14:01:02 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/minilibx-linux/mlx.h"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define YELLOW_BRIGHT "\033[1;33m"
#define BLUE_INTENSE "\033[0;34m"
#define RED "\033[0;31m"
#define BRIGHT_RED "\033[1;31m"
#define RESET "\033[0m"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*joinfree(char *s1, char *s2)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	free(s1);
	return (join);
}

char	*readb(int fd, char *res)
{
	int		readbytes;
	char	*buffer;

	if (!res)
		res = ft_calloc(1, 1);
	readbytes = 1;
	buffer = ft_calloc(1 + BUFFER_SIZE, sizeof(char));
	while (readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readbytes] = 0;
		res = joinfree(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*lines(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next(char *buffer)
{
	int		i;
	int		n;
	char	*line;

	i = 0;
	n = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[n++] = buffer[i++];
	line[n] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readb(fd, buffer);
	if (!buffer)
		return (NULL);
	line = lines(buffer);
	buffer = next(buffer);
	return (line);
}
