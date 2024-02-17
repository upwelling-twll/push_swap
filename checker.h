#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
#include "get_next_line.h"
// #include "libft/ft_strdup.c"
// #include "libft/ft_memcpy.c"
// #include "libft/ft_strlen.c"
// #include "libft/ft_strchr.c"
// #include "libft/ft_strlcpy.c"
// #include "libft/ft_isdigit.c"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct in_list
{
	char			*content;
	struct in_list	*next;
}					t_instr;

typedef struct ss_list
{
	struct ss_list	*prev;
	int				data;
	struct ss_list	*next;
}					tt_list;

int ft_llstsize(tt_list *lst);
int ft_strcmp(char *s1, char *s2);
void print_list_ins(t_instr *lst);
t_instr *add_node_ins(t_instr *lst, char *ins);
int valid_ins(char *ins);
int apply_ins(tt_list **stack1, tt_list **stack2, ins_func ins_recived);
void del_instr_list(t_instr *lst);
char *read_stdin(int fd);
int check_overflow(const char *str, int flag, int i);
int verify_atoi(const char *str);
int verify_argv(tt_list *args_lst, char *argv);
void del_stack_lst(tt_list *lst);
int ft_exit(tt_list *st1, tt_list *st2, t_instr *oper, int display);
void print_list(tt_list *lst);
tt_list *ft_llstlast(tt_list *lst);
tt_list *init_list(int i);
int check_if_sorted(tt_list *lst);


 tt_list	*add_node(tt_list *nlist, int data);
tt_list	*delfirst(tt_list  *lst);


int	rrr(tt_list **stack1, tt_list **stack2);
int	rrb(tt_list **stack, tt_list **s2); //no s2
int	rra(tt_list **stack, tt_list **s2); //no s2);
int	rr(tt_list **stack1, tt_list **stack2);
int	rb(tt_list **stack, tt_list **s2); //no s2);
int	ra(tt_list **stack,  tt_list **s2); //no s2);
int	pb(tt_list **stack1, tt_list **stack2);
int	pa(tt_list **stack1, tt_list **stack2);
int	ss(tt_list **stack1, tt_list **stack2);
int	sb(tt_list **stack,  tt_list **s2); //no s2);
int	sa(tt_list **stack,  tt_list **s2); //no s2);
int	swap(tt_list **stack,  tt_list **s2); //no s2);
void	move_first(tt_list **stack1, tt_list **stack2);

typedef struct inst_list
{
	int		target;
	int		s1_rotate_up; // up = ra
	int		s1_rotate_down; // down = rra

	int		s2_rotate_up; //  up = rb The first element becomes the last one. the number of instructions rb which are needed to place the element
	int 	s2_rotate_down;// down = rrb The last element becomes the first one.
	int		mood; //
}					i_list;
//list_operations.c

#endif