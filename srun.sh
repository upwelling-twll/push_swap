# gcc instructions.c list_operations.c sortingA.c sortingB.c get_next_line.h get_next_line.c get_next_line_utils.c main.c -o push_swap
gcc -c func_push.c #ok norm 5f
gcc -c func_swap.c #ok norm 4f
gcc -c func_revrot.c #ok norm 3f
gcc -c func_rotate.c #ok norm 3f
gcc -c optimize_ins.c #ok norm 4f
gcc -c maxmin_ins.c #ok norm 4f
gcc -c stack_analysis.c #ok norm 5f
gcc -c list_operations.c #ok norm 4f
gcc -c verify_or_exit.c #ok norm 5f
gcc -c sort_small.c #ok norm 4f
gcc -c sort_mode.c #ok norm 5f
gcc -c instr_clcltA.c #ok norm 3f
gcc -c sortingA.c #ok norm 4f
gcc -c find_place3.c #ok norm 2f
gcc -c instr_clcltB.c #ok norm 5f
gcc -c sortingB.c #ok norm 4f

gcc -c sceleton.c #ok norm 4f
gcc -c main.c

gcc -c dbg_func.c #3f


gcc -c get_next_line.c
gcc -c get_next_line_utils.c
gcc find_place3.o instr_clcltA.o instr_clcltB.o stack_analysis.o sort_small.o func_rotate.o func_revrot.o func_push.c func_swap.o dbg_func.o optimize_ins.o maxmin_ins.o sort_mode.o sceleton.o verify_or_exit.o list_operations.o sortingA.o sortingB.o get_next_line.o get_next_line_utils.o main.o -o push_swap -g -fsanitize=address
rm *.o