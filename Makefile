# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjabbour <hjabbour@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 18:39:51 by hjabbour          #+#    #+#              #
#    Updated: 2023/01/16 10:36:26 by hjabbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc

CFLAGS = -Wall -Werror -Wextra

# LINK = -Ofast -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address 
LINK = -Ofast -lmlx -framework OpenGL -framework AppKit #-g -fsanitize=address 

INC =	include/declarations.h \
		include/enums.h \
		include/macros.h \
		include/types.h

RM = rm -f

SRCS =	main.c \
		test_utils.c \
		test_utils1.c \
		libft/ft_strlen.c \
		libft/ft_itoa.c \
		linear_algebra/debug_vec.c \
		linear_algebra/is_equal.c \
		linear_algebra/vector.c \
		linear_algebra/vector_arithmetic.c \
		linear_algebra/vector_arithmetic_utils.c \
		linear_algebra/matrix_2x2.c \
		linear_algebra/matrix_3x3.c \
		linear_algebra/matrix_3x3_utils.c \
		linear_algebra/matrix_4x4.c \
		linear_algebra/matrix_4x4_utils.c \
		linear_algebra/matrix_4x4_utils2.c \
		linear_algebra/matrix_transformation.c \
		linear_algebra/geometry_conversion.c \
		linear_algebra/matrix_rotation.c \
		objects/camera.c \
		objects/ray.c \
		objects/cylinder.c \
		objects/sphere.c \
		objects/plane.c \
		objects/light.c \
		objects/debug_obj.c \
		parser/parse.c \
		srcs/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -Iinclude -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean