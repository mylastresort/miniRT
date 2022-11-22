CC = cc
CFLAGS = -Werror -Wall -Wextra
INC = -Iinclude -Imlx
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = miniRT
OBJ = $(SRC:.c=.o)
SRC = $(wildcard src/*.c)

all: $(NAME)

%.o: %.c
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(LDFLAGS) $^

clean:
	-rm $(OBJ) $(SRC:.c=.d)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(SRC:.c=.d)