#include "checker.h" 

int	swap(t_llist **stack,  t_llist **s2)
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
	return (1);
}

int	ss(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	swap(stack1, stack2);
	swap(stack2, stack1);
	return (0);
}