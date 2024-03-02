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
}					t_chins;

typedef struct s_llist
{
	struct s_llist	*prev;
	int				data;
	struct s_llist	*next;
}					t_llist;

typedef struct s_inst
{
	int		target;
	int		s1_rotate_up;
	int		s1_rotate_down;
	int		s2_rotate_up;
	int		s2_rotate_down;
	int		mood;
}					t_inst;

int ft_llstsize(t_llist *lst);
int ft_strcmp(char *s1, char *s2);
void print_list_ins(t_chins *lst);
t_chins *add_node_ins(t_chins *lst, char *ins);
int valid_ins(char *ins);
int apply_ins(t_llist **stack1, t_llist **stack2, ins_func ins_recived);
void del_instr_list(t_chins *lst);
char *read_stdin(int fd);
int check_overflow(const char *str, int flag, int i);
int verify_atoi(const char *str);
int verify_argv(t_llist *args_lst, char *argv);
void del_stack_lst(t_llist *lst);
int ft_exit(t_llist *st1, t_llist *st2, t_chins *oper, int display);
void print_list(t_llist *lst);
t_llist *ft_llstlast(t_llist *lst);
t_llist *init_list(int i);
int check_if_sorted(t_llist *lst);


 t_llist	*add_node(t_llist *nlist, int data);
t_llist	*delfirst(t_llist  *lst);


int	rrr(t_llist **stack1, t_llist **stack2);
int	rrb(t_llist **stack, t_llist **s2); //no s2
int	rra(t_llist **stack, t_llist **s2); //no s2);
int	rr(t_llist **stack1, t_llist **stack2);
int	rb(t_llist **stack, t_llist **s2); //no s2);
int	ra(t_llist **stack,  t_llist **s2); //no s2);
int	pb(t_llist **stack1, t_llist **stack2);
int	pa(t_llist **stack1, t_llist **stack2);
int	ss(t_llist **stack1, t_llist **stack2);
int	sb(t_llist **stack,  t_llist **s2); //no s2);
int	sa(t_llist **stack,  t_llist **s2); //no s2);
int	swap(t_llist **stack,  t_llist **s2); //no s2);
void	move_first(t_llist **stack1, t_llist **stack2);

//list_operations.c

#endif