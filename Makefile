CC = gcc
CFLAGS = -Wall -Werror -Wextra
PROGRAM = push-swap
HEADER = push_swap.h
SRC = push-swap.c \
		additional_functions.c \
		check_args.c \
		read_args.c \
		list_creation.c \
		print_list.c \
		push_instractions.c \
		rotate_instractions.c \
		find_index.c \
		sort_three_nbrs.c \
		sort_five_nbrs.c

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