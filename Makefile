NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
INCLUDES = -I$(MLX_DIR) -I./includes

MLX_DIR = ./minilibx/minilibx-linux 


SRC = includes/assist_functions.c \
		includes/error.c \
		includes/randomizer.c \
		includes/get_next_line.c \
		includes/get_next_line_utils.c \
		includes/asign_routes.c \
		includes/assist_functions_2.c \
		includes/check_map.c \
		src/main.c \
		src/so_long_aux.c \
		src/load_sprites.c \
		src/move.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
