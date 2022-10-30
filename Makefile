CC = cc
CFLAGS = -Werror -Wall -Wextra
DEP = $(SRC:.c=.d)
INC = -DHAVE_INLINE -Iinclude -I/usr/local/include -I/Users/stamim/homebrew/opt/gsl/include/
LDFLAGS = -L/Users/stamim/homebrew/opt/gsl/lib
LDLIBS = -lmlx -framework OpenGL -framework AppKit -lm -lgsl -lgslcblas -lm
NAME = miniRT
OBJ = $(SRC:.c=.o)
SRC = $(wildcard src/*.c)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $^ $(LDLIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INC) -MD

clean:
	-rm $(OBJ) $(DEP)

fclean: clean
	-rm $(NAME)

re: fclean all

exe: all
	./$(NAME)
-include $(DEP)