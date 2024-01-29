#include "push_swap.h"
#include "list_operations.c"   //for debugger only
#include "instructions.c"    //for debugger only
#include "libft/ft_atoi.c"

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
	printf("size=%i\n", size);
	while (size>0)
	{
		if (stack->data < min->data)
			min = stack;
		stack=stack->next;
		size--;
		printf("size=%i\n", size);
	}
	printf("done min\n");
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
		rb(&stack);
		i_rb++;
	}
	(*instr)->s2_rup_inum = i_rb;
	stack = head;
	while (stack->data != max->data)
	{
		rrb(&stack);
		i_rrb++;
	}
	(*instr)->s2_rdown_inum = i_rrb;
}

void	push_on_min(tt_list *stack, tt_list *max, i_list **instr)
{
	tt_list	*head;
	int i_rb;
	int	i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != max->data)
	{
		rb(&stack);
		i_rb++;
	}
	(*instr)->s2_rup_inum = i_rb;
	stack = head;
	while (stack->data != max->data)
	{
		rrb(&stack);
		i_rrb++;
	}
	(*instr)->s2_rdown_inum = i_rrb;
}

tt_list	*find_place(tt_list *stack2, int target_data, int size)
{
	while (size)
	{
		if (target_data < stack2->data && target_data > stack2->next->data)
			return(stack2);
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
	(*inumber)->s2_rup_inum = un_position - 1;
	(*inumber)->s2_rdown_inum = size - un_position - 1;
}

void	i_to_place(tt_list *target_s1, tt_list *stack2, i_list **inumber, int size)
{
	// how to find the best position for element in stack B?
	tt_list *min_s2;
	tt_list	*max_s2;
	tt_list	*upper_nebor;
	int		inum;

	printf("is min ?\n");	
	min_s2 = get_min(stack2, size);
	max_s2 = get_max(stack2, size);
	printf("searching place\n");
	if (target_s1->data < min_s2->data)
		push_on_max(stack2, max_s2, inumber);
	else if (target_s1->data > max_s2->data)
		push_on_min(stack2, min_s2, inumber);
	else
	{
		upper_nebor = find_place(stack2, target_s1->data, size);
		clclt_instr(upper_nebor, stack2, size, inumber);
	}
}

int	gmin(int a, int b , int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	if (b < a && b < c && b < d)
		return (b);
	if (c < a && c < b && c < d)
		return (c);
	else
		return (d);
}

int	best_option(int s1us2d, int s1ds2u, int tu, int td)
{
	int	min_inst = gmin(s1us2d,s1ds2u,tu, td);
	if (s1us2d == min_inst)
		return (1);
	else if (s1ds2u == min_inst)
		return (2);
	else if (tu == min_inst)
		return (3);
	return (4);
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
	s2_up = (*inumber)->s2_rup_inum;
	s2_down = (*inumber)->s2_rdown_inum;
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
	return (gmin(s1up_s2d, s1d_s2up, ttl_up_i, ttl_down_i));
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
	printf("inst_num\n");
	(*inumber)->target = node;
	while (stack1 -> data != node->data)
	{
		position++;
		stack1 = stack1->next;
	}
	printf("---\n");
	printf("lets float\n");
	i_to_float(position, heads1, size1, inumber);
	printf("lets place\n");
	i_to_place(node, stack2, inumber, size2);
	printf("after place\n");
	inst_num = optimize(inumber);
	return (inst_num+1);
}

void	update_inst(i_list **i_target, i_list **inumber)
{
	(*i_target)-> target = (*inumber)-> target; 
	(*i_target)-> s1_rotate_up = (*inumber)-> s1_rotate_up; 
	(*i_target)-> s1_rotate_down = (*inumber)-> s1_rotate_down; 
	(*i_target)-> s2_rup_inum = (*inumber)-> s2_rup_inum; 
	(*i_target)-> s2_rdown_inum = (*inumber)-> s2_rdown_inum; 
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
	cur_inst = 0;
	inumber = malloc(sizeof(i_list));
	shead = head;
	list1_size = ft_llstsize(head);
	cur = head;
	while(i < list1_size)
	{
		printf("-\n");
		cur_inst = inst_num(shead, stack2, cur, list1_size, &inumber);
		printf("--\n");
		if (min > cur_inst)
		{
			target = cur;
			min = cur_inst;
			update_inst(i_target, &inumber);
		}
		cur = (head)->next;
		i++;
	}
	return (target);
}

int	main(void)
{
	tt_list *nlist;
	tt_list	*head;
	tt_list	*stack2;
	i_list	*i_target;

	i_target = malloc(sizeof(i_list));
	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;
	nlist = malloc(sizeof(tt_list));
	nlist->prev = NULL;
	nlist->data = 31;
	nlist ->next = NULL;
	head = nlist;

	nlist -> next = add_node(nlist, 2);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, 59);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, 0);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, 433);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, 361);
	nlist = nlist -> next;
	nlist -> next = head;

	nlist -> next = add_node(nlist, 995);
	nlist = nlist -> next;
	nlist -> next = head;

	nlist -> next = add_node(nlist, 933);
	nlist = nlist -> next;
	nlist -> next = head;

	nlist -> next = add_node(nlist, 41);
	nlist = nlist -> next;
	nlist -> next = head;

	head->prev = nlist; 
	print_list(head);
 
	sa(head);
	printf("		stack1\n");
	print_list(head);
	printf("---------------------------------\n");
	while (ft_llstsize(stack2) < 2)
	{
		pa(&head, &stack2);
		printf("---------------------------------\n");
		printf("		stack1\n");
		print_list(head);
		printf("		stack2\n");
		print_list(stack2);
	}
	find_target(head, stack2, &i_target);
	print_itarget(i_target);
	// while (ft_llstsize(head) > 3)
	// {
	// 	find_target(head, stack2, &i_target);
	// 	print_itarget(i_target);
		//exec_instr(head, stack2);
		// pa(&head, &stack2);
		// printf("---------------------------------\n");
		// printf("		stack1\n");
		// print_list(head);
		// printf("		stack2\n");
		// print_list(stack2);
//	}
}

// int	main(int argc, char *argv[])
// {
// 	tt_list *nlist;
// 	tt_list	*head;
// 	tt_list	*stack2;

// 	if (argc > 2)
// 	{
// 		argv++;
// 		nlist = init_list(ft_atoi(*argv)); 
// 		argv++;
// 	}
// 	head = nlist;
// 	stack2 = malloc(sizeof(stack2));
// 	while (*argv)
// 	{
// 		nlist -> next = add_node(nlist, ft_atoi(*argv));
// 		argv++;
// 		nlist = nlist -> next;
// 	}
// 	head->prev = nlist; 
// 	print_list(head);

// 	//swap_data((head->next->next), (head->next));
// 	//print_list_back(nlist);
// 	if (check_if_sorted(head))
// 	{
// 		printf("already sorted\n");
// 		return (0);
// 	}
// 	sorting(nlist, stack2);
// }
