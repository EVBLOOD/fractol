# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 22:13:55 by sakllam           #+#    #+#              #
#    Updated: 2021/12/19 01:05:03 by sakllam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract
bonus = burning
INCLUDE = ./Mandatory/fract.h
INCLUDE_BONUS = ./Bonus/fract_bonus.h
SRC = ./Mandatory/fract_utils.c \
		./Mandatory/fract_utils_julia.c\
		./Mandatory/fract_utils_mandelbrot.c\
		./Mandatory/ft_julia.c\
		./Mandatory/ft_mandelbrot.c\
		./Mandatory/main.c
SRC_BONUS = ./Bonus/fract_utils_1bonus.c\
		./Bonus/fract_utils_bonus.c\
		./Bonus/ft_burning_bonus.c\
		./Bonus/main_bonus.c
CFLAGS = -Wall -Werror -Wextra
EXTONSTION = -framework OpenGL -framework AppKit
EXTOFILES = libmlx.a libmlx.dylib
all: $(NAME)
$(NAME): $(INCLUDE) $(SRC:.c=.o)
	(cd minilibx_mms_20200219; make all; mv libmlx.dylib ../)
	(cd minilibx_opengl_20191021; make all; mv libmlx.a ../)
	gcc $(CFLAGS) $(EXTOFILES) $(EXTONSTION) $(SRC) -I $(INCLUDE) -o $(NAME)
bonus: $(INCLUDE_BONUS) $(SRC_BONUS:.c=.o)
	(cd minilibx_mms_20200219; make all; mv libmlx.dylib ../)
	(cd minilibx_opengl_20191021; make all; mv libmlx.a ../)
	gcc $(CFLAGS) $(EXTOFILES) $(EXTONSTION) $(SRC_BONUS) -I $(INCLUDE_BONUS) -o $(bonus)
clean:
	(cd minilibx_mms_20200219; make clean)
	(cd minilibx_opengl_20191021; make clean)
	rm -f $(SRC:.c=.o) $(SRC_BONUS:.c=.o)
fclean: clean
	rm -f $(NAME) $(bonus) $(EXTOFILES)
re: fclean all
.PHONY: all clean fclean re