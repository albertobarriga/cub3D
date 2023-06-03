NAME = cub3D
LIBFT = libft/libft.a
CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra
SRC = 	src/main.c \
		src/exit.c \
	 	src/parser/parser.c \
	 	src/parser/init.c \
	 	src/parser/utils_parser.c \
	 	src/parser/utils_init.c \
		src/raycaster/init_raycaster.c \
	 	src/checker/error.c \
	 	src/checker/checker_map.c \
	 	src/checker/checker_elements.c

LIBM = MLX42/libmlx42.a

ifeq ($(USER), abarriga)
	GLFW = -I include -lglfw -L /sgoinfre/goinfre/Perso/${USER}/homebrew/Cellar/glfw/3.3.8/lib
else
	GLFW = -I include -lglfw -L /opt/homebrew/opt/glfw/lib
endif
# Mac 42
# GLFW = -I include -lglfw -L /sgoinfre/goinfre/Perso/abarriga/homebrew/Cellar/glfw/3.3.8/lib

# Mac alberto
# GLFW = -I include -lglfw -L /opt/homebrew/opt/glfw/lib



AUTHOR = jlimones / abarriga
DATE = 18/05/2023

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OBJ = $(SRC:.c=.o)

all: header $(NAME)
	@rm -rf .files_changed

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(FLAGS)\n\033[m"

$(NAME): ${OBJ} $(LIBM)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(LIBM) $(GLFW)
	@printf "%b" "$(OK_COLOR)" "cub3D compilado\n"

$(LIBM):
	@make -C MLX42

skiperror:
	@$(CC) -o $(NAME) $(SRC)

clean: header
	@make clean -C libft
	@make clean -C ./MLX42
	# @make -C $(LIBM_DIR) clean
	@rm -f $(OBJ)

fclean: header clean
	@make fclean -C ./MLX42
	@rm -f $(NAME)
	@make fclean -C libft
	@printf "%b" "$(OK_COLOR)" "fclean ejecutado correctamente\n"
	

re: fclean all

.PHONY: all lib clean fclean re