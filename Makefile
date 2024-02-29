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
	instr_clcltB.c sortingB.c sceleton.c main.c

SRCS_BONUS = checker.c instructions.c list_operations.c sortingA.c	\
	sortingB.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
 
bonus: $(NAME_BONUS)

$(NAME): libft $(OBJS)
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/*.o

bonus: libft $(OBJS_BONUS)
	@ $(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) libft/*.o

libft:
	@ make -C libft/

clean:
	@ $(RM) $(OBJS) $(OBJS_BONUS)
	@ make -C libft/ clean

fclean: clean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@ make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re bonus