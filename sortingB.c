#include "push_swap.h"

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

tt_list	*find_place(tt_list *stack2, int target_data, int size, tt_list *max, tt_list *min)
{
	while (size)
	{
		if ((target_data > stack2->data && target_data < stack2->prev->data))
			return (stack2);

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


void	i_to_place(tt_list *target_s1, tt_list *stack2, i_list **inumber, int size) // how to find the best position for element in stack B?
{
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

tt_list	*find_target(tt_list *head, tt_list *stack2, i_list **i_target, int s)
{
	tt_list	*cur;
	tt_list *target;
	i_list	*inumber;
	int		i;
	int		min;
	int		cur_inst;
	
	i = 0;
	target = head;
	inumber = malloc(sizeof(i_list));
	cur = head;
	min = inst_num(head, stack2, cur, s, &inumber);
	update_inst(i_target, &inumber);
	target = cur;
	while(i < s)
	{
		cur_inst = inst_num(head, stack2, cur, s, &inumber);
		if (min > cur_inst)
		{
			target = cur;
			min = cur_inst;
			update_inst(i_target, &inumber);
		}
		cur = cur->next;
		i++;
	}
	free (inumber);
	return (target);
}

