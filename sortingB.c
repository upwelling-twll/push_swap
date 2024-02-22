
#include "push_swap.h"

#define RA_STR (dr == 1 ? "ra\n" : "rb\n")
#define RRB_STR (dr == 1 ? "rrb\n" : "rra\n")
#define RA2_STR (d2 == 1 ? "rra\n" : "rrb\n")
#define RRA2_STR (d2 == 1 ? "rb\n" : "ra\n")

void	run_mood1(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	while (i_target->s1_rotate_up != 0)
	{
		ra(stack1, NULL);
		write(1, RA_STR, 3);
		i_target->s1_rotate_up--;
	}
	while (i_target->s2_rotate_down != 0)
	{
		rrb(stack2, NULL);
		write(1, RRB_STR, 4);
		i_target->s2_rotate_down--;
	}
	pb(stack1, stack2);
}

void	run_mood2(tt_list **stack1, tt_list **stack2, i_list *i_target, int d2)
{
	while (i_target->s1_rotate_down != 0)
	{
		rra(stack1, NULL);
		write(1, RA2_STR, 4);
		i_target->s1_rotate_down--;
	}
	while (i_target->s2_rotate_up != 0)
	{
		rb(stack2, NULL);
		write(1, RRA2_STR, 3);
		i_target->s2_rotate_up--;
	}
	pb(stack1, stack2);
}

void	run_mood3(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	while (i_target->s1_rotate_up != 0 && i_target->s2_rotate_up != 0)
	{
		rr(stack1, stack2);
		write(1, "rr\n", 3);
		i_target->s1_rotate_up--;
		i_target->s2_rotate_up--;
	}
	while (i_target->s1_rotate_up != 0)
	{
		ra(stack1, NULL);
		if (dr == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		i_target->s1_rotate_up--;
	}
	while (i_target->s2_rotate_up != 0)
	{
		rb(stack2, NULL);
		if (dr == 1)
			write(1, "rb\n", 3);
		else
			write(1, "ra\n", 3);
		i_target->s2_rotate_up--;
	}
	pb(stack1, stack2);
}

void	run_mood4(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	while (i_target->s1_rotate_down != 0 && i_target->s2_rotate_down != 0)
	{
		rrr(stack1, stack2);
		write(1, "rrr\n", 4);
		i_target->s1_rotate_down--;
		i_target->s2_rotate_down--;
	}
	while (i_target->s1_rotate_down != 0)
	{
		rra(stack1, NULL);
		if (dr == 1)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
		i_target->s1_rotate_down--;
	}
	while (i_target->s2_rotate_down != 0)
	{
		rrb(stack2, NULL);
		if (dr == 1)
			write(1, "rrb\n", 4);
		else
			write(1, "rra\n", 4);
		i_target->s2_rotate_down--;
	}
	pb(stack1, stack2);
}

void	exec_instr(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	if (i_target->mood == 1) // run (ra and rrb) rotate stack1 up and rotate stack 2 down;
		run_mood1(stack1, stack2, i_target, dr);
	if (i_target->mood == 2) // run (rra and rb) rotate stack1 down and rotate stack 2 up;
		run_mood2(stack1, stack2, i_target, dr);
	if (i_target->mood == 3) // run (rr) rotate stack1 and stack 2 up (and some ra / rb);
		run_mood3(stack1, stack2, i_target, dr);
	if (i_target->mood == 4) // run (rrr) rotate stack1 and stack 2 down (and some rra / rrb);
		run_mood4(stack1, stack2, i_target, dr);
	if (dr == 1)
		write(1, "pb\n", 3);
	else if (dr == 2)
		write(1, "pa\n", 3);
}

void	i_to_float(int position, tt_list *stack1, int size, i_list **inumber)
{
	(*inumber) -> s1_rotate_up = position - 1; // = 2 if position is 3 : ra pa
	(*inumber) -> s1_rotate_down = size - position + 1; //rra rra rra
}

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

// tt_list	*search_for_closest(tt_list *stack2, int target_data, int size)
// {
// 	while (size)
// 	{
// 		if (stack2->data < target_data && stack2->next->data > target_data)
// 			return (stack2);
// 		size--;
// 		stack2 = stack2->next;
// 	}
// }

tt_list	*find_place(tt_list *stack2, int target_data, int size, tt_list *max, tt_list *min)
{
	while (size)
	{
		if ((target_data > stack2->data && target_data < stack2->prev->data))
		{
			return (stack2);
			// if (stack2->data == min && stack2->prev->data == max)
			// 	return (search_for_closest(stack2->next, target_data, size));
		}
		stack2 = stack2->next;
		size--;
	}
	return (stack2);
}

void	clclt_instr(tt_list *upper_nebor, tt_list *stack2, int size, i_list **inumber)
{
	int un_position;

	un_position = 1;
	while (stack2->data != upper_nebor->data)
	{
			un_position++;
			stack2 = stack2->next;
	}
	(*inumber)->s2_rotate_up = un_position - 1;
	if (un_position != size)
		(*inumber)->s2_rotate_down = size - un_position + 1;
	else
		(*inumber)->s2_rotate_down = 1;
}


void	i_to_place(tt_list *target_s1, tt_list *stack2, i_list **inumber, int size)
{
	// how to find the best position for element in stack B?
	tt_list *min_s2;
	tt_list	*max_s2;
	tt_list	*upper_nebor;
	int		inum;

	min_s2 = get_min(stack2, size);
	max_s2 = get_max(stack2, size);
	if (target_s1->data < min_s2->data)
		push_on_max(stack2, max_s2, inumber);
	else if (target_s1->data > max_s2->data)
		push_under_min(stack2, min_s2, inumber);
	else
	{
		upper_nebor = find_place(stack2, target_s1->data, size, max_s2, min_s2);
		clclt_instr(upper_nebor, stack2, size, inumber);
	}
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

int	best_option(int s1us2d, int s1ds2u, int tu, int td)
{
	char	min_inst = gmin(s1us2d,s1ds2u,tu, td);
	if (min_inst == 'a')
		return (1);
	else if (min_inst == 'b')
		return (2);
	else if (min_inst == 'c')
		return (3);
	return (4);
}

int	gmin_i(int a, int b , int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	if (b <= a && b <= c && b <= d)
		return (b);
	if (c <= a && c <= b && c <= d)
		return (c);
	else
		return (d);
}

int	optimize(i_list **inumber)
{
	int	ttl_up_i;
	int	ttl_down_i;
	int s1_up;
	int s1_down;
	int	s2_up;
	int s2_down;
	int s1up_s2d;
	int s1d_s2up;

	s1_up = (*inumber)->s1_rotate_up;
	s1_down = (*inumber)->s1_rotate_down;
	s2_up = (*inumber)->s2_rotate_up;
	s2_down = (*inumber)->s2_rotate_down;
	s1up_s2d = s1_up + s2_down;
	s1d_s2up = s1_down + s2_up;
	if (s1_up > s2_up)
		ttl_up_i = s2_up + (s1_up - s2_up);
	else if (s1_up <= s2_up)
		ttl_up_i = s1_up + (s2_up - s1_up);
	if (s1_down > s2_down)
		ttl_down_i = s2_down + (s1_down - s2_down);
	else if (s1_down <= s2_down)
		ttl_down_i = s1_down + (s2_down - s1_down);
	(*inumber)->mood = best_option(s1up_s2d, s1d_s2up, ttl_up_i, ttl_down_i);
	return (gmin_i(s1up_s2d, s1d_s2up, ttl_up_i, ttl_down_i));
}

int	inst_num(tt_list *stack1, tt_list *stack2, tt_list *node, int size1, i_list **inumber)
{
	int position;
	tt_list	*heads1;
	int	inst_num;
	int	size2;

	position = 1;
	inst_num = 0;
	heads1 = stack1;
	size2 = ft_llstsize(stack2);
	(*inumber)->target = node->data;
	while (stack1 -> data != node->data)
	{
		position++;
		stack1 = stack1->next;
	}
	i_to_float(position, heads1, size1, inumber);
	i_to_place(node, stack2, inumber, size2);
	inst_num = optimize(inumber);
	return (inst_num+1);
}

void	update_inst(i_list **i_target, i_list **inumber)
{
	(*i_target)-> target = (*inumber)-> target;
	(*i_target)-> s1_rotate_up = (*inumber)-> s1_rotate_up; 
	(*i_target)-> s1_rotate_down = (*inumber)-> s1_rotate_down; 
	(*i_target)-> s2_rotate_up = (*inumber)-> s2_rotate_up; 
	(*i_target)-> s2_rotate_down = (*inumber)-> s2_rotate_down; 
	(*i_target)-> mood = (*inumber)-> mood; 
}

tt_list	*find_target(tt_list *head, tt_list *stack2, i_list **i_target)
{
	tt_list	*shead;
	int		list1_size;
	int		i;
	tt_list	*cur;
	tt_list *target;
	int		min;
	int		cur_inst;
	i_list	*inumber;
	
	i = 0;
	target = head;
	min = 0;
	inumber = malloc(sizeof(i_list));
	shead = head;
	list1_size = ft_llstsize(head);
	cur = head;
	min = inst_num(shead, stack2, cur, list1_size, &inumber);
	update_inst(i_target, &inumber);
	target = cur;
	while(i < list1_size)
	{
		cur_inst = inst_num(shead, stack2, cur, list1_size, &inumber);
		if (min > cur_inst)
		{
			target = cur;
			min = cur_inst;
			update_inst(i_target, &inumber);
		}
		cur = cur->next;
		i++;
		//free(inumber);
	}
	free (inumber);
	return (target);
}

