gcc -c ../dbg_func.c 
gcc -c checker.c
gcc -c checker_inc.c
gcc -c ../rsc_push_swap/sort_small.c
gcc -c ../rsc_push_swap/exit.c
gcc -c ../rsc_push_swap/verify.c
gcc -c ../rsc_push_swap/more_args.c
gcc -c ../rsc_push_swap/optimize_ins.c
gcc -c ../rsc_push_swap/find_place3.c
gcc -c ../rsc_push_swap/sort_mode.c
gcc -c ../rsc_push_swap/instr_clcltA.c
gcc -c ../rsc_push_swap/instr_clcltB.c
gcc -c ../rsc_push_swap/maxmin_ins.c
gcc -c ../rsc_push_swap/list_operations.c
gcc -c ../rsc_push_swap/stack_analysis.c
gcc -c ../rsc_push_swap/sortingA.c
gcc -c ../rsc_push_swap/sortingB.c
gcc -c ../rsc_gnl/get_next_line.c
gcc -c ../rsc_gnl/get_next_line_utils.c
gcc -c checker_push.c
gcc -c checker_swap.c
gcc -c checker_revrot.c
gcc -c checker_rotate.c
gcc -c exit_del.c
gcc -c parse_instructions.c
gcc -c parse_nums.c
gcc -c apply_instructions.c

gcc dbg_func.o checker.o checker_inc.o sort_small.o exit.o verify.o more_args.o optimize_ins.o find_place3.o sort_mode.o instr_clcltA.o instr_clcltB.o maxmin_ins.o list_operations.o stack_analysis.o sortingA.o sortingB.o get_next_line.o get_next_line_utils.o checker_push.o checker_swap.o checker_revrot.o checker_rotate.o exit_del.o parse_instructions.o parse_nums.o apply_instructions.o -o checker

rm *.o

#gcc ../dbg_func.c checker.c checker_inc.c checker_inst.c ../rsc_push_swap/sort_small.c ../rsc_push_swap/exit.c ../rsc_push_swap/verify.c ../rsc_push_swap/more_args.c  ../rsc_push_swap/optimize_ins.c ../rsc_push_swap/find_place3.c ../rsc_push_swap/sort_mode.c ../rsc_push_swap/instr_clcltA.c ../rsc_push_swap/instr_clcltB.c ../rsc_push_swap/maxmin_ins.c ../rsc_push_swap/list_operations.c ../rsc_push_swap/stack_analysis.c ../rsc_push_swap/sortingA.c ../rsc_push_swap/sortingB.c ../rsc_gnl/get_next_line.c ../rsc_gnl/get_next_line_utils.c -o checker

#-g -fsanitize=address