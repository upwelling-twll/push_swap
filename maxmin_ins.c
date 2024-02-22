#include "push_swap.h"

tt_list	*get_min(tt_list *stack, int size)
{
	tt_list	*min;

	size++;
	min = stack;
	while (size>0)
	{
		if (stack->data < min->data)
			min = stack;
		stack=stack->next;
		size--;
	}
	return (min);
}

tt_list	*get_max(tt_list *stack, int size)
{
	tt_list	*max;

	size++;
	max = stack;
	while (size)
	{
		if (stack->data > max->data)
			max = stack;
		stack=stack->next;
		size--;
	}
	return (max);
}

void	push_on_max(tt_list *stack, tt_list *max, i_list **instr)
{
	tt_list	*head;
	int i_rb;
	int	i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != max->data)
	{
		rb(&stack, NULL);
		i_rb++;
	}
	(*instr)->s2_rotate_up = i_rb;
	stack = head;
	while (stack->data != max->data)
	{
		rrb(&stack, NULL);
		i_rrb++;
	}
	(*instr)->s2_rotate_down = i_rrb;
}

void	push_under_min(tt_list *stack, tt_list *min, i_list **instr)
{
	tt_list	*head;
	int i_rb;
	int	i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != min->next->data)
	{
		rb(&stack, NULL);
		i_rb++;
	}
	(*instr)->s2_rotate_up = i_rb;
	stack = head;
	while (stack->data != min->next->data)
	{
		rrb(&stack, NULL);
		i_rrb++;
	}
	(*instr)->s2_rotate_down = i_rrb;
}

char	gmin(int a, int b , int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return ('a');
	if (b <= a && b <= c && b <= d)
		return ('b');
	if (c <= a && c <= b && c <= d)
		return ('c');
	else
		return ('d');
}
