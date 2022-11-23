CC = cc
CFLAGS = -Werror -Wall -Wextra
INC = -Iinclude -Imlx
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = miniRT
OBJ = $(SRC:.c=.o)
SRC = $(wildcard src/*.c)
SUITES = $(wildcard test/*.c)
SUITES_DA = $(SUITES:.c=.gcda)
SUITES_NO = $(SUITES:.c=.gcno)
SUITES_O = $(SUITES:.c=.o)
TST = test_run

all: $(NAME)

check: $(TST)
	./$(TST)

%_test.o: %_test.c
	$(CC) -c -fprofile-arcs -ftest-coverage $< -o $@

%.o: %.c
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(LDFLAGS) $^

$(TST): $(SUITES_O)
	$(CC) -o $(TST) --coverage $^

clean:
	-rm $(OBJ) $(SRC:.c=.d) $(TST) $(SUITES_O) $(SUITES_DA) $(SUITES_NO)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(SRC:.c=.d)