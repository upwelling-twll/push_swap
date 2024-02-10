#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
#include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct ss_list
{
	struct ss_list	*prev;
	int				data;
	struct ss_list	*next;
}					tt_list;

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
int		check_if_sorted(tt_list *lst);
tt_list	*init_list(int i);
tt_list	*ft_llstlast(tt_list *lst);
int		ft_llstsize(tt_list *lst);
void	print_list(tt_list *lst);
void	print_itarget(i_list *lst);
void	float_to_top(tt_list **head, tt_list *new_head);
void	sort_3(tt_list **lst);
int		cmp(int a, int b);
void	min_to_top(tt_list **lst);

//sorting B
void	run_mood1(tt_list **stack1, tt_list **stack2, i_list *i_target);
void	run_mood2(tt_list **stack1, tt_list **stack2, i_list *i_target);
void	run_mood3(tt_list **stack1, tt_list **stack2, i_list *i_target);
void	run_mood4(tt_list **stack1, tt_list **stack2, i_list *i_target);
void	exec_instr(tt_list **stack1, tt_list **stack2, i_list *i_target);
void	i_to_float(int position, tt_list *stack1, int size, i_list **inumber);
tt_list	*get_min(tt_list *stack, int size);
tt_list	*get_max(tt_list *stack, int size);
void	push_on_max(tt_list *stack, tt_list *max, i_list **instr);
void	push_under_min(tt_list *stack, tt_list *min, i_list **instr);
tt_list	*search_for_closest(tt_list *stack2, int target_data, int size);
tt_list	*find_place(tt_list *stack2, int target_data, int size,tt_list *max, tt_list *min);
void	clclt_instr(tt_list *upper_nebor, tt_list *stack2, int size, i_list **inumber);
void	i_to_place(tt_list *target_s1, tt_list *stack2, i_list **inumber, int size);
char	gmin(int a, int b , int c, int d);
int		best_option(int s1us2d, int s1ds2u, int tu, int td);
int		optimize(i_list **inumber);
int		inst_num(tt_list *stack1, tt_list *stack2, tt_list *node, int size1, i_list **inumber);
void	update_inst(i_list **i_target, i_list **inumber);
tt_list	*find_target(tt_list *head, tt_list *stack2, i_list **i_target);

//sorting A
void	push_on_min(tt_list *stack, tt_list *min, i_list **instr);
void	push_under_max(tt_list *stack, tt_list *max, i_list **instr);
int		inst_numA(tt_list *stack1, tt_list *stack2, tt_list *node, int size1, i_list **inumber);
tt_list	*find_targetA(tt_list *head, tt_list *stack2, i_list **i_target);
tt_list	*find_place3(tt_list *stack2, int target_data, int size, tt_list *max, tt_list *min);
tt_list	*find_place33(tt_list *stack2, int target_data, int size, tt_list *max, tt_list *min);
void	i_to_placeA(tt_list *target_s1, tt_list *stack2, i_list **inumber, int size, tt_list *stack1);
void	clclt_instr3(tt_list *upper_nebor, tt_list *stack2, int size, i_list **inumber);
//instructions.c
void	swap_data(tt_list *n1, tt_list *n2);
void	rrr(tt_list **stack1, tt_list **stack2);
void	rrb(tt_list **stack, tt_list **s2); //no s2
void	rra(tt_list **stack, tt_list **s2); //no s2);
void	rr(tt_list **stack1, tt_list **stack2);
void	rb(tt_list **stack, tt_list **s2); //no s2);
void	ra(tt_list **stack,  tt_list **s2); //no s2);
void	pb(tt_list **stack1, tt_list **stack2);
void	pa(tt_list **stack1, tt_list **stack2);
void	ss(tt_list **stack1, tt_list **stack2);
void	sb(tt_list **stack,  tt_list **s2); //no s2);
void	sa(tt_list **stack,  tt_list **s2); //no s2);
void	swap(tt_list **stack,  tt_list **s2); //no s2);
void	move_first(tt_list **stack1, tt_list **stack2);
tt_list	*delfirst(tt_list  *lst);
tt_list	*add_node(tt_list *nlist, int data);

#endif
