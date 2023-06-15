CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = *.c
MAINFILE = main.c
OUTPUT = -o tests
NAME = fractol
OBJ = $(src:.c=.o) 

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAG) $(SRC) minilibx-linux/libmlx_Linux.a -o $(NAME) -lXext -lX11 -lm

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
