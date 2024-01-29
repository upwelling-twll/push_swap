#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
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
	tt_list	*target;
	int		s1_rotate_up; 
	int		s1_rotate_down;

	int		s2_rup_inum; //  up = rb The first element becomes the last one. the number of instructions rb which are needed to place the element
	int 	s2_rdown_inum;// down = rrb The last element becomes the first one.
	int		mood; //
}					i_list;

int	check_if_sorted(tt_list *lst);
tt_list	*init_list(int i);
tt_list	*ft_llstlast(tt_list *lst);
int	ft_llstsize(tt_list *lst);
void	print_list(tt_list *lst);
void	print_itarget(i_list *lst);

void	swap_data(tt_list *n1, tt_list *n2);
void	rrr(tt_list **stack1, tt_list **stack2);
void	rrb(tt_list **stack);
void	rra(tt_list **stack);
void	rr(tt_list **stack1, tt_list **stack2);
void	rb(tt_list **stack);
void	ra(tt_list **stack);
void	pb(tt_list **stack1, tt_list **stack2);
void	pa(tt_list **stack1, tt_list **stack2);
void	ss(tt_list *stack1, tt_list *stack2);
void	sb(tt_list *stack);
void	sa(tt_list *stack);
void	swap(tt_list *stack);
void	move_first(tt_list **stack1, tt_list **stack2);
tt_list	*delfirst(tt_list  *lst);
tt_list	*add_node(tt_list *nlist, int data);



#endif