gcc -c ./rsc_checker/checker_push.c
gcc -c ./rsc_checker/checker_swap.c
gcc -c ./rsc_checker/checker_revrot.c
gcc -c ./rsc_checker/checker_rotate.c
gcc -c ./rsc_checker/exit_del.c
gcc -c ./rsc_checker/parse_instructions.c
gcc -c ./rsc_checker/parse_nums.c
gcc -c ./rsc_checker/apply_instructions.c
gcc -c ./rsc_checker/checker.c
gcc -c ./rsc_checker/checker_inc.c
gcc -c ./rsc_checker/checker_supp.c
gcc -c ./rsc_checker/proc_args.c
gcc -c ./rsc_checker/verify_args.c
gcc -c ./libft/ft_atoi.c
gcc -c ./libft/ft_calloc.c
gcc -c ./libft/ft_isalpha.c
gcc -c ./libft/ft_isdigit.c
gcc -c ./libft/ft_striteri.c
gcc -c ./libft/ft_memchr.c
gcc -c ./libft/ft_memcpy.c
gcc -c ./libft/ft_memset.c
gcc -c ./libft/ft_putendl_fd.c
gcc -c ./libft/ft_putstr_fd.c
gcc -c ./libft/ft_strchr.c
gcc -c ./libft/ft_strjoin.c
gcc -c ./libft/ft_strlcpy.c
gcc -c ./libft/ft_strmapi.c
gcc -c ./libft/ft_strnstr.c
gcc -c ./libft/ft_strtrim.c
gcc -c ./libft/ft_tolower.c
gcc -c ./libft/ft_bzero.c
gcc -c ./libft/ft_isalnum.c
gcc -c ./libft/ft_isascii.c
gcc -c ./libft/ft_isprint.c
gcc -c ./libft/ft_itoa.c
gcc -c ./libft/ft_memcmp.c
gcc -c ./libft/ft_memmove.c
gcc -c ./libft/ft_putchar_fd.c
gcc -c ./libft/ft_putnbr_fd.c
gcc -c ./libft/ft_split.c
gcc -c ./libft/ft_strdup.c
gcc -c ./libft/ft_strlcat.c
gcc -c ./libft/ft_strlen.c
gcc -c ./libft/ft_strncmp.c
gcc -c ./libft/ft_strrchr.c
gcc -c ./libft/ft_substr.c
gcc -c ./libft/ft_toupper.c
gcc -c ./libft/ft_lstnew.c
gcc -c ./libft/ft_lstadd_front.c
gcc -c ./libft/ft_lstsize.c
gcc -c ./libft/ft_lstlast.c
gcc -c ./libft/ft_lstadd_back.c
gcc -c ./libft/ft_lstdelone.c
gcc -c ./libft/ft_lstclear.c
gcc -c ./libft/ft_lstiter.c
gcc -c ./libft/ft_lstmap.c
gcc -c ./libft/ft_numlen.c
gcc -c ./libft/ft_putnbr_int.c
gcc -c ./libft/ft_putcharlen.c
gcc -c ./libft/thex.c
gcc -c ./libft/print_d.c
gcc -c ./libft/print_u.c
gcc -c ./libft/print_p.c
gcc -c ./libft/ft_print.c
gcc -c ./libft/ft_putstrlen.c
gcc -c ./libft/get_next_line.c
gcc -c ./libft/get_next_line_utils.c



gcc ft_atoi.o ft_calloc.o ft_isalpha.o ft_isdigit.o ft_striteri.o ft_memchr.o ft_memcpy.o ft_memset.o ft_putendl_fd.o ft_putstr_fd.o ft_strchr.o ft_strjoin.o ft_strlcpy.o ft_strmapi.o ft_strnstr.o ft_strtrim.o ft_tolower.o ft_bzero.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_itoa.o ft_memcmp.o ft_memmove.o ft_putchar_fd.o ft_putnbr_fd.o ft_split.o ft_strdup.o ft_strlcat.o ft_strlen.o ft_strncmp.o checker_push.o checker_swap.o checker_revrot.o checker_rotate.o exit_del.o parse_instructions.o parse_nums.o apply_instructions.o checker.o checker_inc.o checker_supp.o proc_args.o verify_args.o -o checker

rm *.o

#gcc ../dbg_func.c checker.c checker_inc.c checker_inst.c ../rsc_push_swap/sort_small.c ../rsc_push_swap/exit.c ../rsc_push_swap/verify.c ../rsc_push_swap/more_args.c  ../rsc_push_swap/optimize_ins.c ../rsc_push_swap/find_place3.c ../rsc_push_swap/sort_mode.c ../rsc_push_swap/instr_clcltA.c ../rsc_push_swap/instr_clcltB.c ../rsc_push_swap/maxmin_ins.c ../rsc_push_swap/list_operations.c ../rsc_push_swap/stack_analysis.c ../rsc_push_swap/sortingA.c ../rsc_push_swap/sortingB.c ../rsc_gnl/get_next_line.c ../rsc_gnl/get_next_line_utils.c -o checker

#-g -fsanitize=address