NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99

FILES = ft_printf ft_numlen ft_putchar ft_putnbr ft_putptr ft_strlen ft_putnbr_base ft_putnum ft_putstr ft_puthex_l ft_puthex_u


SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES)) 
 
all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ) 

%.o : %.c
	@printf "\033[1mCompile : $(<)\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m ✓\033[0m\n"
	 

.PHONY: clean fclean re
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re:	fclean all
