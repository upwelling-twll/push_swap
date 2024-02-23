# green='\033[0;32m' 
# clear='\033[0m' 
green ='\033[0;32m' 
clear ='\033[0m'

NAME = push_swap

NAME_BONUS = checker

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = func_push.c func_swap.c func_revrot.c func_rotate.c optimize_ins.c	\
	maxmin_ins.c stack_analysis.c list_operations.c verify_or_exit.c	\
	sort_small.c sort_mode.c instr_clcltA.c sortingA.c find_place3.c	\
	instr_clcltB.c sortingB.c sceleton.c

SRCS_BONUS = checker.c instructions.c list_operations.c sortingA.c	\
	sortingB.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
 
bonus: $(NAME_BONUS)

server: libft $(OBJ_S)
	@ $(CC) $(FLAGS) -o $(NAME_S) $(OBJ_S) libft/*.o

client: libft $(OBJ_C)
	@ $(CC) $(FLAGS) -o $(NAME_C) $(OBJ_C) libft/*.o
	@if [ ! -e "$(client_before)" ]; then (echo "${green}Compiled successfully!${clear}") && (bash important_file.sh); fi

server_bonus: libft $(OBJ_S_BONUS)
	@ $(CC) $(FLAGS) -o $(NAME_S_BONUS) $(OBJ_S_BONUS) libft/*.o

client_bonus: libft $(OBJ_C_BONUS)
	@ $(CC) $(FLAGS) -o $(NAME_C_BONUS) $(OBJ_C_BONUS) libft/*.o

libft:
	@ make -C libft/

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C) $(OBJ_S_BONUS) $(OBJ_C_BONUS)
	@ make -C libft/ clean

fclean: clean
	@ $(RM) $(NAME_S) $(NAME_C) $(NAME_S_BONUS) $(NAME_C_BONUS)
	@ make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re client server bonus client_bonus server_bonus