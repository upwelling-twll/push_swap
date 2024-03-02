#include "checker.h" 

t_llist	*delfirst(t_llist  *lst)
{
	t_llist	*new_head;
	t_llist	*lst_prev;
	int	data;

	if (ft_llstsize(lst) == 1)
	{
		free (lst);
		return (NULL);
	}
	new_head = lst->next;
	lst_prev = lst->prev;
	new_head->prev = lst_prev;
	lst_prev->next = new_head;

	free (lst);
	return (new_head);
}

void	move_first(t_llist **stack1, t_llist **stack2) //pb
{
	int	tmp;
	t_llist	*tmp_s2;
	t_llist *new_head;
	t_llist *old_last;

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
	}
	*stack1 = delfirst(*stack1);
}

void	pb_first_ch(t_llist **stack1, t_llist **stack2)
{
	int		tmp;

	tmp = (*stack1)->data;
	*stack2 = add_node(*stack2, tmp);
	(*stack2)->next = *stack2;
	(*stack2)->prev = (*stack2);
	*stack1 = delfirst(*stack1);
}

int	swap(t_llist **stack,  t_llist **s2) //no s2)
{
	int tmp;

	if (!(*stack))
		return (0);
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	return (1);
}

int	sa(t_llist **stack, t_llist **s2)
{
	if (!(*stack))
		return (0);
	swap(stack, s2);
	return (1);
}

int	sb(t_llist **stack, t_llist **s2)
{
	if (!(*stack))
		return (0);
	swap(stack, s2);
	return(1);
}

int	ss(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	swap(stack1, stack2);
	swap(stack2, stack1);
	return (0);
}

int	pa(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack2))
		return (0);
	move_first(stack2, stack1);
	return (1);
}

int	pb(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1))
		return (0);
	move_first(stack1, stack2);
	return (1);
}

int	ra(t_llist **stack, t_llist **s2)
{	
	if (!(*stack))
		return (0);
	*stack = (*stack)->next;
	return (1);
}

int	rb(t_llist **stack, t_llist **s2)
{
	if (!(*stack))
		return (0);
	*stack = (*stack)->next; 
	return (1);
}

int	rr(t_llist **stack1, t_llist **stack2)
{
	printf("will use rr\n");
	printf("lst->data:%d\n", (*stack1)->data);
	//printf("lst->data:%d\n, stack2->data:%d\n", (*stack1)->data, (*stack2)->data);
	if (!(*stack1) || (!(*stack2)))
		return (0);
	ra(stack1, stack2);
	rb(stack2, stack2);
	return (1);
}

int	rra(t_llist **stack, t_llist **s2)
{
	if (!(*stack))
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

int	rrb(t_llist **stack, t_llist **s2)
{
	if (!(*stack))
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

int	rrr(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	rra(stack1, stack2);
	rrb(stack2, stack2);
	return (1);
}
