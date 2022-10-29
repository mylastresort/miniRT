CC = cc
DEP = $(SRC:.c=.d)
CFLAGS = -DHAVE_INLINE -Iinclude -Ilib/gsl -I/Users/stamim/.brew/opt/gsl/include/
LDLIBS = -lmlx -framework OpenGL -framework AppKit -lm -lgsl -lgslcblas -lm
LDFLAGS = -L/Users/stamim/.brew/opt/gsl/lib/
NAME = miniRT
OBJ = $(SRC:.c=.o)
SRC = $(wildcard src/*.c)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $^ $(LDLIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -MD

clean:
	-rm $(OBJ) $(DEP)

fclean: clean
	-rm $(NAME)

re: fclean all

exe: all
	DYLD_LIBRARY_PATH=lib/mlx ./$(NAME)
-include $(DEP)