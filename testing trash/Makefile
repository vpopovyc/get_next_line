
NAME = gnl

SRC = get_next_line.c main.c

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	make -C libft/
	gcc $(CFLAGS) -I./libft/ -L./libft -lft -o gnl $(SRC)

rf:
	rm -f $(NAME)

tp: rf all

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all