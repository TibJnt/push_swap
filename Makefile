# =============================== NAMES ====================================== #

NAME = push_swap
LIBFT = libft.a
LIBFT_DIR = ./libft/
HEADER = push_swap.h
INCLUDE = -I ./
SRC_DIR = ./src/

# ============================= COMPILATE ==================================== #

RM						= rm -rf
AR         				= ar -rcs
CFLAGS					= -Wall -Werror -Wextra -g

# =========================== DIRECTORIES ==================================== #

OBJ_DIR				= ./obj_dir
OBJ_SRC 			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# =========================== SOURCES ======================================== #

SRC = main.c free_ops/free.c\
		parse/parse.c \
		stack_operations/stack_ops.c stack_operations/stack_utils.c \
		sort_operations/sort.c sort_operations/operations_1.c sort_operations/operations_2.c sort_operations/sort_2.c\
		utils/utils.c\

VPATH = $(SRC_DIR)\
		 $(SRC_DIR)stack_operations\
		 $(SRC_DIR)parse\
		 $(SRC_DIR)free_ops\
		 $(SRC_DIR)sort_operations\
		 $(SRC_DIR)utils

# =========================== BOLD COLORS ==================================== #

DEF_COLOR 				= \033[1;39m
GRAY 	   				= \033[1;90m
RED		   				= \033[1;91m
GREEN	    			= \033[1;32m
YELLOW	    			= \033[1;93m
BLUE 					= \033[1;94m
MAGENTA     			= \033[1;95m
CYAN        			= \033[1;96m
WHITE		       		= \033[1;97m
	
# =========================== BACKGROUND COLORS ============================ #

BG_Black				=\033[40m

# ========================== MAKE RULES ===================================== #

all: smake $(NAME)
	@echo "\n\n$(BG_Purple)$(GREEN)==== Project push_swap compiled! ==== ✅$(DEF_COLOR)$(BG_Black)\n"
	@touch $(NAME)

smake:
	@make bonus -C  $(LIBFT_DIR)
$(NAME):$(OBJ_SRC)
	#@make bonus -C  $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_SRC) -L$(LIBFT_DIR) -lft $(INCLUDE)$(LIBFT_DIR) -o $@

$(OBJ_SRC): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@printf "$(YELLOW)\r $@$(DEF_COLOR)"
	@$(CC) $(CFLAGS)  -I$(SRC_DIR) -c $< -o $@
	#@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(SRC_DIR) -c $< -o $@

# ========================== CLEAN   ===================================== #

.PHONY: all clean fclean re smake

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "\n$(CYAN)==== push_swap and libft object files cleaned! ==== ✅$(DEF_COLOR)\n"
	
fclean: clean 
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "\n$(CYAN)==== push_swap and libft executable files and name cleaned! ==== ✅$(DEF_COLOR)\n"

re : fclean all
	@echo "\n$(GREEN)==== Cleaned and rebuilt everything for push_swap and libft! ==== ✅$(DEF_COLOR)\n"
