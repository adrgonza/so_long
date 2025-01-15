NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I./include -I./lib/libft -I./lib/minilibx

LIB = lib
LIBFT = $(LIB)/libft
MLX_DIR = $(LIB)/minilibx
SRC = src
BIN = bin
OBJ = $(BIN)/obj

SRC_FILES = \
        $(SRC)/main.c \
		$(SRC)/parser.c \
		$(SRC)/floodfill.c \
		$(SRC)/game.c \

OBJ_FILES = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRC_FILES))

all: $(LIBFT) $(BIN)/$(NAME)

$(BIN)/$(NAME): $(OBJ_FILES) $(LIBFT)/libft.a
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(FLAGS_MLX) $(INCLUDES) $(OBJ_FILES) -L$(LIBFT) -lft -o $(BIN)/$(NAME)

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@test -d $(LIBFT) || (mkdir -p $(LIB) && git clone https://github.com/adrgonza/libft $(LIBFT) && $(MAKE) -C $(LIBFT))

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(BIN) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
