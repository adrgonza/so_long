NAME = so_long

# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit #-O3
INCLUDES = -I./include -I./lib/libft

# Folders
LIB = lib
LIBFT = $(LIB)/libft
SRC = src
BIN = bin
OBJ = $(BIN)/obj

# Files
SRC_FILES = \
        $(SRC)/main.c \


OBJ_FILES = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRC_FILES))

#Rules
all: $(LIBFT) $(BIN)/$(NAME)

$(BIN)/$(NAME): $(OBJ_FILES) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(FLAGS_MLX) $(INCLUDES) $(OBJ_FILES) -L$(LIBFT) -lft -o $(BIN)/$(NAME)

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@test -d $(LIBFT) || (mkdir -p $(LIB) && git clone https://github.com/adrgonza/libft $(LIBFT) && $(MAKE) -C $(LIBFT))

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(BIN) $(LIB)

re: fclean all

.PHONY: all clean fclean re