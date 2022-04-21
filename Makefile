CC = gcc
CFLAGS = -Wall -Werror -Wextra
PROGRAM = push-swap
CHECKER = checker
HEADER = ./mandatory/push_swap.h
HEADER_B = ./bonus/push_swap.h
SRC = ./mandatory/push-swap.c \
		./mandatory/additional_functions.c \
		./mandatory/check_args.c \
		./mandatory/list_creation.c \
		./mandatory/putnbr_intop.c \
		./mandatory/push_instractions.c \
		./mandatory/rotate_instractions.c \
		./mandatory/sort_three_nbrs.c \
		./mandatory/sort_five_nbrs.c \
		./mandatory/push_to_b.c \
		./mandatory/sort_hundred_nbr.c \
		./mandatory/insert_tab.c

SRC_B = ./bonus/my_checker.c \
			./bonus/additional_functions.c \
			./bonus/check_args.c \
			./bonus/list_creation.c \
			./bonus/putnbr_intop.c \
			./bonus/push_instractions.c \
			./bonus/rotate_instractions.c \
			./bonus/sort_three_nbrs.c \
			./bonus/sort_five_nbrs.c \
			./bonus/push_to_b.c \
			./bonus/sort_hundred_nbr.c \
			./bonus/insert_tab.c \
			./bonus/get_next_line.c \
			./bonus/get_next_line_utils.c \
			./bonus/sorted_stack.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	@$(CC) $(OBJ) -o $(PROGRAM)

bonus: $(CHECKER)

$(CHECKER): $(OBJ_B)
	@$(CC) $(OBJ_B) -o $(CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_B)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_B)

fclean: clean
	@rm -rf $(PROGRAM)
	@rm -rf $(CHECKER)

re : fclean all bonus