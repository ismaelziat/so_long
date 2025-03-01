/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:11:32 by iziat-hi          #+#    #+#             */
/*   Updated: 2025/03/01 12:19:29 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <stdbool.h>


# define W_WIDTH 1
# define W_HEIGHT 1 

# define KEY_ESC 65307
# define KEY_CLOSE 33
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define T_S 64

# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		coin;
	int		player;
	int		exit;
	int		fill_coin;
	bool	exit_found;
}	t_map;

typedef struct s_background_map
{
	char	**grid;
	int		width;
	int		height;
}	t_background;

typedef struct fill
{
	int	**map;
	int	coins_left;
}	t_fill;

typedef struct s_wallcheck
{
	int		height;
	int		width;
	char	**grid;
}	t_wallcheck;

typedef struct s_game
{
	void		*mlx;
	void		*wi;
	int			p_x;
	int			p_y;
	void		*w;
	void		*p;
	void		*f;
	void		*c;
	void		*e;
	int			size;
	int			door_open;
	int			collected_coins;
	t_map		map;
	t_player	player;
	t_fill		fill;
	t_wallcheck	wallcheck;
}	t_game;

typedef struct s_0
{
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
}	t_0;

typedef struct s_1
{
	void	*one;
	void	*two;
	void	*three;
	void	*four;
}	t_1;

typedef struct s_p
{
	void	*one;
	void	*two;
}	t_p;

typedef struct s_c_game
{
	void		*mlx;
	void		*wi;
	int			p_x;
	int			p_y;
	void		*w;
	void		*p;
	void		*f;
	void		*c;
	void		*e;
	int			size;
	int			door_open;
	int			collected_coins;
	t_map		map;
	t_player	player;
	t_fill		fill;
	t_wallcheck	wallcheck;
}	t__c_game;

typedef struct s_c_map
{
	char	**grid;
	int		width;
	int		height;
	int		coin;
	int		player;
	int		exit;
	int		fill_coin;
	bool	exit_found;
}	t_c_map;

void		print_map(const char *map_path);
void		init_game(const char *map_path, t_game *game);
void		start_game(t_game *game);
void		free_map(char **map, int height);
int			key_hook(int keycode, t_game *game);
int			close_window(t_game *game);
void		error(const char *message);
void		*ft_calloc(size_t count, size_t size);
int			randomizer(int min, int max);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*readb(int fd, char *res);
char		*joinfree(char *s1, char *s2);
char		*lines(char *buffer);
char		*next(char *buffer);
char		*get_next_line(int fd);
void		load_sprites(t_game *g);
void		count_map_lines(const char *file_path, t_game *game);
void		process_map(t_game *g);
void		process_map_part_2(t_game *g, int x, int y);
void		load_map_content(const char *file_path, t_game *game);
int			main(int argc, char **argv);
void		render_game(t_game *g);
void		count_x_y(const char *map_path, t_game *game, int *w_w, int *w_h);
char		*assign_floor(t_0 *floor);
char		*assign_wall(t_1 *wall);
char		*assign_player(t_p *player);
void		process_background(t_game *g);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			verify_xpm(const char *filename, char *name);
void		check_number_of_elements(t_game *game);
void		move_up(t_game *g);
void		move_down(t_game *g);
void		move_left(t_game *g);
void		move_right(t_game *g);
void		can_you_move(t_game *g, int new_y, int new_x);
void		win_game(t_game *g, int new_y, int new_x);
void		count_assist(int fd, char *line, int max_line_len, int line_num);
void		check_fill_correct(t_game *game);
void		verification(t_game *game);
void		check_perimeters(t_game *game);

#endif
