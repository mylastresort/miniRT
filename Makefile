# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 18:39:51 by hjabbour          #+#    #+#              #
#    Updated: 2022/12/25 19:23:42 by hjabbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc

CFLAGS = -Wall -Werror -Wextra

LINK = -Ofast -lmlx -framework OpenGL -framework AppKit

INC =	include/declarations.h \
		include/enums.h \
		include/linear_algebra.h \
		include/macros.h \
		include/types.h

RM = rm -f

SRCS =	main.c \
		test.c \
		test_utils.c \
		test_utils1.c \
		libft/ft_strlen.c \
		linear_algebra/debug_vec.c \
		linear_algebra/is_equal.c \
		linear_algebra/vector.c \
		linear_algebra/vector_arithmetic.c \
		linear_algebra/vector_arithmetic_utils.c \
		linear_algebra/matrix_2x2.c \
		linear_algebra/matrix_3x3.c \
		linear_algebra/matrix_4x4.c \
		parser/parse.c \
		srcs/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean