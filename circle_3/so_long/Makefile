CC = gcc
CFLAGS = -Wall -Wextra -Werror 

NAME = so_long
FILES = main game move map_load map_render map_check map_check_utils ft_free 
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = -I ./include/
SRC = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILES)))
OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(FILES)))

MLX_DIR = ./mlx
MLX_INCLUDE = -I $(MLX_DIR)
MLX_FLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11
MLX = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = ./libft
LIBFT_INCLUDE = -I $(LIBFT_DIR)/include
LIBFT = $(LIBFT_DIR)/libft.a 

INCS = $(MLX_INCLUDE) $(LIBFT_INCLUDE) $(INC_DIR)


all: $(NAME)

$(LIBFT):
	@printf "\033[32m[\033[36m LIBFT   \033[32m]\033[36m Compiling...\033[0m\n"
	@make -C $(LIBFT_DIR)  > /dev/null 2>&1

$(MLX):
	@printf "\033[32m[\033[36m MLX     \033[32m]\033[36m Compiling...\033[0m\n"
	@make -C $(MLX_DIR)  > /dev/null 2>&1
	

$(NAME) : $(OBJ) $(MLX) $(LIBFT)
	@printf "\033[32m[\033[36m SO_LONG \033[32m]\033[36m Compiling...\033[0m\n"
	@$(CC) $(CFLAGS) $(INCS) -o $@ $^ $(MLX_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 

.PHONY: clean fclean re
clean:
	@printf "\033[32m[\033[36m CLEAN  \033[32m]\n"
	@rm -f $(OBJ)
	@make -C libft clean > /dev/null 2>&1
	@make -C mlx clean > /dev/null 2>&1
fclean: clean
	@printf "\033[32m[\033[36m FCLEAN \033[32m]\n"
	@rm -f $(NAME)
	@make -C libft fclean > /dev/null 2>&1
	@make -C mlx clean > /dev/null 2>&1
re:     fclean all

