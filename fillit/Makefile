# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 12:35:12 by hunnamab          #+#    #+#              #
#    Updated: 2019/12/16 13:46:49 by hunnamab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
LIBRARY = libft/libft.a
HEADER = fillit.h
SRC = main.c check_mistakes.c check_tetriminos.c create_list.c ft_btd.c ft_pow.c get_dec_arr.c \
		fillit.c map_output.c fillit_big.c get_dec_arr2.c map_staff.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
		gcc -c $(FLAGS) -I libft/ -o $@ $<

$(LIBRARY):
		@make -C libft/

$(NAME): $(LIBRARY) $(OBJ)
		@gcc $(OBJ) $(LIBRARY) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
