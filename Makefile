NAME1 = checker
NAME2 = push_swap

SRC_PATH = ./src

SRC_NAME = checker.c moves.c list.c list2.c rules.c display.c flags.c utils.c \
			moves_dispatcher.c resolver_simple.c resolver_optimized.c \
			moves2.c

SRC_NAME2 = push_swap.c moves.c list.c rules.c display.c flags.c utils.c \
			moves_dispatcher.c resolver_simple.c resolver_optimized.c list2.c \
			moves2.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OFILES = $(SRC_NAME:.c=.o)
OFILES2 = $(SRC_NAME2:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = lib/GNL/get_next_line.a lib/libft/libft.a lib/libft/ft_printf/libftprintf.a

all: makelibs $(NAME1) $(NAME2)

makelibs:
	make -C lib/libft
	make -C lib/GNL

$(NAME1): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LIBS) -I includes -o $(NAME1)
	@echo "Compilation checker:\033[92m OK\033[0m"

$(NAME2): $(OFILES2)
	$(CC) $(CFLAGS) $(OFILES2) $(LIBS) -I includes -o $(NAME2)
	@echo "Compilation push_swap:\033[92m OK\033[0m"

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes

clean:
	@make -C lib/GNL clean
	@make -C lib/libft clean
	@rm -rf $(OFILES) $(OFILES2)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@make -C lib/GNL fclean
	@make -C lib/libft fclean
	@rm -rf $(NAME1) $(NAME2)
	@echo "Deleting:\n\033[33m $(NAME1) and $(NAME2)\033[0m"

re : fclean all

.PHONY: all clean fclean re
