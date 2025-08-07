CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj/
SRC_DIR = src/

NAME_SERVER  = server
FILES_SERVER = server utils
SRC_SERVER = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILES_SERVER)))
OBJ_SERVER = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(FILES_SERVER)))

NAME_CLIENT  = client
FILES_CLIENT = client utils
SRC_CLIENT = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILES_CLIENT)))
OBJ_CLIENT = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(FILES_CLIENT)))


NAME_SERVER_BONUS  = server_bonus
FILES_SERVER_BONUS = server_bonus utils_bonus
SRC_SERVER_BONUS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILES_SERVER_BONUS)))
OBJ_SERVER_BONUS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(FILES_SERVER_BONUS)))

NAME_CLIENT_BONUS  = client_bonus
FILES_CLIENT_BONUS = client_bonus utils_bonus
SRC_CLIENT_BONUS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILES_CLIENT_BONUS)))
OBJ_CLIENT_BONUS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(FILES_CLIENT_BONUS)))


all :   $(NAME_SERVER) $(NAME_CLIENT)
bonus : $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME_SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_CLIENT) 	
	@$(CC) $(CFLAGS) $(OBJ_CLIENT)  -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS)

.PHONY: clean fclean re
clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) 
fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
re:	fclean all