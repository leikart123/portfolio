# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 17:55:06 by pmetron           #+#    #+#              #
#    Updated: 2020/08/03 17:56:02 by pmetron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror
LIBRARY = libft/libft.a minilibx/libmlx_Linux.a
HEADER = fractol.h
FLAGS_LINUX = -lX11 -lXext -lm -pthread -L.
SRC = fractol.c key_mouse_control.c draw.c image_changes.c \
image_utils.c init.c color.c args_parse.c hyper.c threads.c \
change_fractal.c draw_calc.c draw_norme.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBRARY):
		@make -C libft/

$(OBJ): %.o: %.c fractol.h
		gcc -c $(FLAGS) -I libft/ -o $@ $<
$(NAME): $(LIBRARY) $(OBJ)
		@gcc $(OBJ) $(LIBRARY) -o $(NAME) $(FLAGS) -lX11 -lXext -lm -pthread -L.
clean:
	@rm -f *.o
	@make -C libft clean

fclean: clean
	@rm -f *.o fractol
	@make -C libft fclean
make linux : fclean
	@make -C libft/
	gcc -c $(FLAGS_LINUX) -I libft/ -o $@ $<
	@gcc $(OBJ) $(LIBRARY) -o $(NAME) $(FLAGS_LINUX)
re: fclean all
