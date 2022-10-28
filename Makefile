CC = cc
DEP = $(SRC:.c=.d)
CFLAGS = -Wall -Werror -Wextra -DHAVE_INLINE -Iinclude
LDLIBS = -lgsl -lgslcblas -lm
NAME = miniRT
OBJ = $(SRC:.c=.o)
SRC = $(wildcard src/*.c)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) -static $^ $(LDLIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -MD

clean:
	-rm $(OBJ) $(DEP)

fclean: clean
	-rm $(NAME)

-include $(DEP)
re: fclean all

exe: all
	./$(NAME)