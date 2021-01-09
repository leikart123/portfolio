NAME = fractol
FLAGS = -lX11 -lXext -lm -lcuda -lcudart
HEADER = fractol.h
SRC = mlx.c fractol.cu draw.cu key_mouse_control.cu utils.cu args_parse.c
OBJ = mlx.o fractol.o draw.o key_mouse_control.o utils.o args_parse.o
LIBRARY = minilibx/libmlx_Linux.a libft/libft.a
all: $(NAME)


$(LIBRARY):
		@make -C libft/
		
$(OBJ): $(SRC) fractol.h fractol.cuh
		nvcc -c $(FLAGS) $(SRC)

$(NAME): $(LIBRARY) $(OBJ)
		@nvcc $(OBJ) $(LIBRARY) -o $(NAME) $(FLAGS)

clean:
	@rm -f *.o

fclean: clean
	@rm -f *.o fractol

re: fclean all
