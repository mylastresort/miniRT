CC = cc
DEP = $(SRC:.c=.d)
FLAGS = -Wall -Werror -Wextra
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = miniRT
OBJ = $(SRC:.c=.o)
SRC = $(wildcard *.c)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $^

%.o: %.c
	$(CC) -c $< -o $@ $(FLAGS) -MMD

clean:
	-rm $(OBJ) $(DEP)

fclean: clean
	-rm $(NAME)

-include $(DEP)
re: fclean all