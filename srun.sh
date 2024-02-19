# gcc instructions.c list_operations.c sortingA.c sortingB.c get_next_line.h get_next_line.c get_next_line_utils.c main.c -o push_swap

gcc -c instructions.c
gcc -c list_operations.c
gcc -c sortingA.c
gcc -c sortingB.c
gcc -c get_next_line.c
gcc -c get_next_line_utils.c
gcc -c main.c

gcc -g3 -fsanitize=address instructions.o list_operations.o sortingA.o sortingB.o get_next_line.o get_next_line_utils.o main.o -o push_swap
rm *.o