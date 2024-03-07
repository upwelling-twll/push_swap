#include "checker.h" 

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
	if (!(*stack1) || (!(*stack2)))
		return (0);
	ra(stack1, stack2);
	rb(stack2, stack2);
	return (1);
}