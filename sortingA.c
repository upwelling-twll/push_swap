#include "push_swap.h"

int	segment_sorted(tt_list *start)
{
	int	sort_len;
	tt_list	*lst;

	sort_len = 1;
	lst = start;
	while (lst->next != start) 
	{
		if (lst->data < lst->next->data)
			sort_len++;
		else
			return (sort_len);
		lst = lst->next;
	}
	return (sort_len);
}

void	sort_presorted(tt_list **lst, tt_list **st2, int sgm_str, i_list **i_trg)
{
	int	sort_len;
	int	lst_size;
	int	new_head;
	int	cp_start;
	tt_list	*cplst;

	printf("---** stack1 sort presorted**---\n");
	print_list(*lst);
	cp_start = sgm_str;
	cplst = *lst;
	printf("sgm_start = %i\n", sgm_str);
	while (cp_start)
	{
		cplst = cplst->next;
		cp_start--;
	}
	sort_len = segment_sorted(cplst);
	//printf("sort_len = %i\n", sort_len);
	lst_size = ft_llstsize(*lst);
	cplst = *lst;
	new_head = (sgm_str + sort_len) - lst_size;
	printf("sort_len = %i\n", sort_len);
	printf("sgm_start = %i\n", sgm_str);
	printf("lst_size = %i\n", lst_size);
	if ((sgm_str + sort_len) < lst_size)
		new_head = lst_size - (sgm_str + sort_len);
	else
	{
		printf("hi\n");
		new_head = sgm_str + sort_len;
	}
	printf("new_head: (%i + %i) - %i = %i\n",  sgm_str, sort_len,lst_size, new_head);
	if (new_head == 0)
		new_head = 1;
	// printf("sort_len = %i\n", sort_len);
	// printf("sgm_start = %i\n", sgm_str);
	// printf("new_head = %i\n", new_head);
	while(new_head > 0)
	{
		ra(lst, NULL);
		write(1, "rra\n", 4);
		new_head--;
	}
	printf("presorted was sorted---** stack1 **---\n");
	print_list(*lst);
	printf("lst->data=%i\n", (*lst)->data);
	//printf("sort_len = %i\n", sort_len);
	while (ft_llstsize(*lst) > sort_len)
	{
		*i_trg = malloc(sizeof(i_list));
		//print_itarget(*i_trg);
		find_target(*lst, *st2, i_trg);
		exec_instr(lst, st2, *i_trg, 1);
		free(*i_trg);
		if (check_if_sorted(*lst))
			break;
	}
}

int	 presorted(tt_list *lst)
{
	tt_list	*start;
	int		sorted_len;
	int		i;
	int		position;
	int		sorted_start;

	start = lst;
	sorted_start = 0;
	sorted_len = 0;
	position = 0;
	i = 1;
	while(lst->next != start)
	{
		if ((i = segment_sorted(lst)) > sorted_len)
		{
			sorted_len = i;
			sorted_start = position;
		}
		lst = lst->next;
		position++;
		//printf("sorted_start= %i\n", sorted_start);
	}
	//printf("sorted_len:%i\n", sorted_len);
	if (sorted_len > ft_llstsize(start) / 2)
		return (sorted_start);
	//printf("is not presorted\n");
	return (-1);
}

void	push_under_max(tt_list *stack, tt_list *max, i_list **instr)
{
	tt_list	*head;
	int i_rb;
	int	i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != max->next->data)
	{
		rb(&stack, NULL);
		i_rb++;
	}
	(*instr)->s2_rotate_up = i_rb;
	stack = head;
	while (stack->data != max->next->data)
	{
		rrb(&stack, NULL);
		i_rrb++;
	}
	(*instr)->s2_rotate_down = i_rrb;
}

void	push_on_min(tt_list *stack, tt_list *min, i_list **instr)
{
	tt_list	*head;
	int i_rb;
	int	i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != min->data)
	{
		rb(&stack, NULL); //The first element becomes the last one.
		i_rb++;
	}
	(*instr)->s2_rotate_up = i_rb;
	stack = head;
	while (stack->data != min->data)
	{
		rrb(&stack, NULL); //The last element becomes the first one.
		i_rrb++;
	}
	(*instr)->s2_rotate_down = i_rrb;
}

tt_list	*find_place3(tt_list *stack2, int target_data, int size, tt_list *max, tt_list *min)
{
	while (size)
	{
		if ((target_data > stack2->data && target_data < stack2->next->data))
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

void	clclt_instr3(tt_list *upper_nebor, tt_list *stack2, int size, i_list **inumber)
{
	int un_position;

	un_position = 1;
	while (stack2->data != upper_nebor->data)
	{
			un_position++;
			stack2 = stack2->next;
	}
	(*inumber)->s2_rotate_up = un_position;
	if (un_position == 1)
		(*inumber)->s2_rotate_down = 2;
	else
		(*inumber)->s2_rotate_down = size - un_position;
}

tt_list	*  find_place33(tt_list *stack2, int target_data, int size, tt_list *max, tt_list *min)
{
	while (size)
	{
		if ((target_data < stack2->data && target_data > stack2->prev->data))
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

void	i_to_placeA(tt_list *target_s1, tt_list *stack2, i_list **inumber, int size, tt_list *stack1)
{
	// how to find the best position for element in stack A?
	tt_list *min_s2;
	tt_list	*max_s2;
	tt_list	*upper_neighbour;
	int		inum;

	min_s2 = get_min(stack2, size);
	max_s2 = get_max(stack2, size);
	// if (ft_llstsize(stack1) == 1 && target_s1-> data < min_s2->data)
	// 	push_on_min(stack2, min_s2, inumber);
	// else if (target_s1->data < min_s2->data)
	// 	push_on_max(stack2, max_s2, inumber);
	if (target_s1-> data < min_s2->data)
		push_on_min(stack2, min_s2, inumber);
	else if (target_s1->data > max_s2->data)
		push_under_max(stack2, max_s2, inumber);
	else
	{
		if (size == 3)
		{
			upper_neighbour = find_place3(stack2, target_s1->data, size, max_s2, min_s2);
			clclt_instr3(upper_neighbour, stack2, size, inumber);
		}
		else
		{
			upper_neighbour = find_place33(stack2, target_s1->data, size, max_s2, min_s2);
			clclt_instr(upper_neighbour, stack2, size, inumber);
		}
	}
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

int		inst_numA(tt_list *stack1, tt_list *stack2, tt_list *node, int size1, i_list **inumber)
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
	i_to_placeA(node, stack2, inumber, size2, stack1);
	inst_num = optimize(inumber);
	return (inst_num+1);
}

tt_list	*find_targetA(tt_list *head, tt_list *stack2, i_list **i_target)
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
	min = inst_numA(shead, stack2, cur, list1_size, &inumber);
	update_inst(i_target, &inumber);
	target = cur;
	while(i < list1_size)
	{
		cur_inst = inst_numA(shead, stack2, cur, list1_size, &inumber);
		if (min > cur_inst)
		{
			target = cur;
			min = cur_inst;
			update_inst(i_target, &inumber);
		}
		cur = (head)->next;
		i++;
		//free(inumber);
	}
	free (inumber);
	return (target);
}

