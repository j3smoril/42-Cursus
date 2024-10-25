NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -I include/

FILES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat \
		ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup \
		ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
BONUS_FILES = ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus

SRC = $(addsuffix .c, $(addprefix src/, $(FILES)))
OBJ = $(addsuffix .o, $(addprefix obj/, $(FILES)))

BONUS_SRC = $(addsuffix .c, $(addprefix src/, $(BONUS_FILES)))
BONUS_OBJ = $(addsuffix .o, $(addprefix obj/, $(BONUS_FILES))) 

all : $(NAME)

bonus: $(BONUS_FILES)

$(BONUS_FILES) : $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ) 

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ) 

obj/%.o : src/%.c
	@printf "\033[1mCompile : $(<)\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m ✓\033[0m\n"
	 

.PHONY: clean fclean re
clean:
	 @rm -f obj/*.o
fclean: clean
	@rm -f $(NAME)
re:	fclean all
