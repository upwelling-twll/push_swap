#include "push_swap.h"

tt_list	*add_node(tt_list *nlist, int data)
{
	tt_list	*new;

	new = malloc(sizeof(tt_list));
	new -> prev = nlist;
	new -> data = data;
	new -> next = NULL;
	return (new);
}

tt_list	*delfirst(tt_list  *lst)
{
	tt_list	*new_head;
	tt_list	*lst_prev;
	int	data;

	new_head = lst->next;
	lst_prev = lst->prev;
	new_head->prev = lst_prev;
	lst_prev->next = new_head;

	free (lst);
	return (new_head);
}

void	move_first(tt_list **stack1, tt_list **stack2) //pb
{
	int	tmp;
	tt_list	*tmp_s2;
	tt_list *new_head;
	tt_list *old_last;

	tmp = (*stack1)->data;
	if (*stack2 == NULL)
	{
		*stack2 = add_node(*stack2, tmp);
		(*stack2)->next = *stack2;
		(*stack2)->prev = (*stack2);
	}
	else
	{
		old_last = ft_llstlast(*stack2);
		new_head =  add_node(*stack2, tmp);
		old_last->next = new_head;
		new_head->next = *stack2;
		new_head->prev = old_last;
		(*stack2)->prev = new_head;
		*stack2= new_head;
		// (tmp_s2) = (*stack2);
		// (*stack2)->prev->next = add_node(*stack2, tmp);
		// (*stack2) = (*stack2)->prev->next;
		// (*stack2)->next = tmp_s2;
		// (*stack2)->prev = ft_llstlast(*stack2);
		// (ft_llstlast(*stack2))->next = (*stack2);
	}
	*stack1 = delfirst(*stack1);
	//printf("stack2_head_after_move:%d\n", (*stack2)->data);
}

void	swap(tt_list *stack)
{
	int tmp;

	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
}

void	sa(tt_list *stack)
{
	swap(stack);
}

void	sb(tt_list *stack)
{
	swap(stack);
}

void	ss(tt_list *stack1, tt_list *stack2)
{
	swap(stack1);
	swap(stack2);
}

void	pa(tt_list **stack1, tt_list **stack2)
{
	move_first(stack2, stack1);
}

void	pb(tt_list **stack1, tt_list **stack2)
{
	move_first(stack1, stack2);
}

void	ra(tt_list **stack)
{
	*stack = (*stack)->next; 
}

void	rb(tt_list **stack)
{
	*stack = (*stack)->next; 
}

void	rr(tt_list **stack1, tt_list **stack2)
{
	ra(stack1);
	rb(stack2);
}

void	rra(tt_list **stack)
{
	*stack = (*stack)->prev; 
}

void	rrb(tt_list **stack)
{
	*stack = (*stack)->prev; 
}

void	rrr(tt_list **stack1, tt_list **stack2)
{
	ra(stack1);
	rb(stack2);
}

void	swap_data(tt_list *n1, tt_list *n2)
{
	int	tmp;

	tmp = n1 -> data;
	n1 -> data = n2 -> data;
	n2 -> data = tmp;
}
