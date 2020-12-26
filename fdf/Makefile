# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 15:05:19 by hunnamab          #+#    #+#              #
#    Updated: 2020/02/21 15:06:01 by hunnamab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -lX11 -lXext -lm
#-lmlx -lX11 -lXext -lm for linux
LIBRARY = libft/libft.a minilibx-linux/libmlx_Linux.a
HEADER = fdf.h
SRC = fdf.c get_next_line.c key_mouse_control.c map_changes.c map_read.c \
		map_settings.c matrix_manipulations.c points_output.c projections.c \
		menu.c colors.c errors.c validation.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
		gcc -c $(FLAGS) -I libft/ -o $@ $<

$(LIBRARY):
		@make -C libft/

$(NAME): $(LIBRARY) $(OBJ)
		@gcc $(OBJ) $(LIBRARY) -o $(NAME) -I $(HEADER) -L. $(FLAGS)

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
