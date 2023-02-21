NAME = so_long
cc = gcc
FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit 
RM = rm -f
SRC = so_long.c get_next_line.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS_MLX) $(OBJ) -o $(NAME)

all : $(NAME)

clean:
	rm -f

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus flean clean re