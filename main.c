#include "push_swap.h"
#include "libft/ft_atoi.c"

i_list	**i_to_float(int position, tt_list *stack1, int size, i_list **inumber)
{
	if (position <= size / 2)
	{
		(*inumber) -> up = position - 1; // = 2 if position is 3 : ra pa
	}
	else
		(*inumber) -> down = size - position + 1; //rra rra rra
	return (inumber);
}

i_list	**i_to_place(tt_list *node, tt_list *stack2, i_list **inumber)
{
	// how to find the best position for element in stack B?
	int min_element;
	int	position;
	
	min_element = get_min(stack2, &position);
	
}

int	inst_num(tt_list *stack1, tt_list *stack2, tt_list *node, int size)
{
	int position;
	tt_list	*heads1;
	int	inst_num;
	i_list	*inumber;

	position = 1;
	inst_num = 0;
	heads1 = stack1;
	inumber = malloc(sizeof(i_list));
	while (stack1 -> data != node->data)
	{
		position++;
		stack1 = stack1->next;
	}
	i_to_float(position, heads1, size, &inumber);
	i_to_place(node, stack2, &inumber);
	inst_num = optimize(inumber);
	return (inst_num+1);
}

tt_list	*find_target(tt_list *head, tt_list *stack2)
{
	tt_list	*shead;
	int		list_size;
	int		i;
	tt_list	*cur;
	tt_list *target;
	int		min;
	int		cur_inst;
	
	i = 0;
	target = head;
	min = 0;
	cur_inst = 0;
	shead = head;
	list_size = ft_llstsize(head);
	while(i < list_size)
	{
		cur_inst = inst_num(shead, stack2, cur, list_size);
		if (min > cur_inst)
		{
			target = cur;
			min = cur_inst;
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
	while (ft_llstsize(head) > 3)
	{
		find_target(head, stack2);
		//exec_instr(head, stack2);
		printf("---------------------------------\n");
		printf("		stack1\n");
		print_list(head);
		printf("		stack2\n");
		print_list(stack2);
	}
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
