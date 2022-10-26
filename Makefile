CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = miniRT
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)
SRC = $(wildcard *.c)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -MMD

$(NAME): $(OBJ)
	$(CC) $^ $(FLAGS) -o $(NAME)

clean:
	rm $(OBJ) $(DEP)

fclean: clean
	rm $(NAME)

re: fclean all