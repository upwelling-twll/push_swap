# gcc instructions.c list_operations.c sortingA.c sortingB.c get_next_line.h get_next_line.c get_next_line_utils.c main.c -o push_swap

gcc -c instructions.c
gcc -c optimize_ins.c
gcc -c maxmin_ins.c
gcc -c list_operations.c
gcc -c verify_or_exit.c
gcc -c sceleton.c
gcc -c sort_mode.c
gcc -c sortingA.c
gcc -c sortingB.c
gcc -c get_next_line.c
gcc -c get_next_line_utils.c
gcc -c main.c

gcc -g3 -fsanitize=address optimize_ins.o maxmin_ins.o sort_mode.o sceleton.o verify_or_exit.o instructions.o list_operations.o sortingA.o sortingB.o get_next_line.o get_next_line_utils.o main.o -o push_swap
rm *.o