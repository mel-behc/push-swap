CC = gcc
CFLAGS = -Wall -Werror -Wextra
PROGRAM = push-swap
HEADER = push-swap.h
SRC = push-swap.c \
		ft_atol.c \
		check_args.c \
		error_function.c \
		read_args.c

OBJ = $(SRC:.c=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	@$(CC) $(OBJ) -o $(PROGRAM)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(PROGRAM)

re : fclean all 