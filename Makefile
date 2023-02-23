NAME = so_long
cc = gcc
FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
SRC = so_long.c get_next_line.c so_check_map.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS_MLX) $(OBJ) -o $(NAME)

all : $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus flean clean re