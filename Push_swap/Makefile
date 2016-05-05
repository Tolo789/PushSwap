NAME = push_swap

SDIR = src/

ADIR = $(SDIR)algo/

SRC =	$(SDIR)main.c \
		$(SDIR)ps_moves.c \
		$(SDIR)r_moves.c \
		$(SDIR)rev_moves.c \
		$(SDIR)get_pile.c \
		$(SDIR)begin_sort.c \
		$(SDIR)ft_lib.c \
		$(SDIR)print_funct.c \
		$(ADIR)my_sorting_funct.c \
		$(ADIR)push_little.c \
		$(ADIR)quicksort.c \
		$(ADIR)first_optimization.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "				push_swap created"

clean:
	@/bin/rm -f $(OBJ)
	@echo "				All push_swap's .o deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "				push_swap deleted"

re: fclean all

.PHONY: all lib clean fclean re
