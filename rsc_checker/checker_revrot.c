#include "checker.h" 

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
