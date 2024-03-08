NAME = push_swap

NAME_BONUS = checker

CC = cc
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
RM = rm -f

SRCS = ./rsc_push_swap/func_push.c ./rsc_push_swap/func_swap.c ./rsc_push_swap/func_revrot.c \
		./rsc_push_swap/func_rotate.c ./rsc_push_swap/optimize_ins.c \
		./rsc_push_swap/maxmin_ins.c ./rsc_push_swap/stack_analysis.c \
		./rsc_push_swap/list_operations.c ./rsc_push_swap/verify.c \
		./rsc_push_swap/sort_small.c ./rsc_push_swap/sort_mode.c \
		 ./rsc_push_swap/instr_clcltA.c ./rsc_push_swap/sortingA.c \
		./rsc_push_swap/find_place3.c ./rsc_push_swap/instr_clcltB.c \
		./rsc_push_swap/sortingB.c ./rsc_push_swap/more_args.c \
		./rsc_push_swap/sceleton.c ./rsc_push_swap/exit.c ./rsc_push_swap/main.c

SRCS_BONUS = ./rsc_checker/checker_push.c ./rsc_checker/checker_swap.c ./rsc_checker/checker_revrot.c \
			 ./rsc_checker/checker_rotate.c ./rsc_checker/exit_del.c ./rsc_checker/parse_instructions.c \
			 ./rsc_checker/parse_nums.c ./rsc_checker/apply_instructions.c ./rsc_checker/main_ch.c \
			 ./rsc_checker/checker_inc.c ./rsc_checker/checker_supp.c ./rsc_checker/proc_args.c \
			 ./rsc_checker/verify_args.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
 
bonus:  $(NAME) $(NAME_BONUS)

$(NAME): libft $(OBJS)
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/*.o

$(NAME_BONUS): $(OBJS_BONUS)
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