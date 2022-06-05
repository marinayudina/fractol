NAME	=	fractol
HEADER	=	fractol.h

SRCS	=	srcs/main.c  srcs/utils.c srcs/mandelbrot.c\
			srcs/julia.c srcs/key.c   srcs/burningship.c\
			srcs/utils1.c

OBJ		=	${SRCS:.c=.o}
CC		=	cc
CFLAGS  =   -Wall -Wextra -Werror

.PHONY	:	all clean fclean re 

all: $(NAME) 

$(NAME): $(OBJ) 
	$(CC)  $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

srcs/%.o		:	srcs/%.c ${HEADER} Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all
