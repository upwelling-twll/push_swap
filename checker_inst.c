#include "checker.h" 
//#include "checker_inc.c"
 
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
	}
	*stack1 = delfirst(*stack1);
}

int	swap(tt_list **stack,  tt_list **s2) //no s2)
{
	int tmp;

	if (!(*stack))
		return (0);
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	return (1);
}

int	sa(tt_list **stack, tt_list **s2)
{
	if (!(*stack))
		return (0);
	swap(stack, s2);
	return (1);
}

int	sb(tt_list **stack, tt_list **s2)
{
	if (!(*stack))
		return (0);
	swap(stack, s2);
	return(1);
}

int	ss(tt_list **stack1, tt_list **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	swap(stack1, stack2);
	swap(stack2, stack1);
	return (0);
}

int	pa(tt_list **stack1, tt_list **stack2)
{
	if (!(*stack2))
		return (0);
	move_first(stack2, stack1);
	return (1);
}

int	pb(tt_list **stack1, tt_list **stack2)
{
	if (!(*stack1))
		return (0);
	move_first(stack1, stack2);
	return (1);
}

int	ra(tt_list **stack, tt_list **s2)
{	
	if (!(*stack))
		return (0);
	*stack = (*stack)->next;
	return (1);
}

int	rb(tt_list **stack, tt_list **s2)
{
	if (!(*stack))
		return (0);
	*stack = (*stack)->next; 
	return (1);
}

int	rr(tt_list **stack1, tt_list **stack2)
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

int	rra(tt_list **stack, tt_list **s2)
{
	if (!(*stack))
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

int	rrb(tt_list **stack, tt_list **s2)
{
	if (!(*stack))
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

int	rrr(tt_list **stack1, tt_list **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	rra(stack1, stack2);
	rrb(stack2, stack2);
	return (1);
}
