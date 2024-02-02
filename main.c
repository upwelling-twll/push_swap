#include "push_swap.h"
// #include "list_operations.c"   //for debugger only
// #include "instructions.c"    //for debugger only
// #include "sorting.c"    //for debugger only
#include "libft/ft_atoi.c"

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
	nlist->data = 8;
	nlist ->next = NULL;
	head = nlist;

	nlist -> next = add_node(nlist, -1);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, 0);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, -3);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, 10);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, 9);
	nlist = nlist -> next;

	nlist -> next = add_node(nlist, -2);
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
		pb(&head, &stack2);
		printf("---------------------------------\n");
		printf("		stack1\n");
		print_list(head);
		printf("		stack2\n");
		print_list(stack2);
	}
	while (ft_llstsize(head) > 3)
	{
		i_target = malloc(sizeof(i_list));
		find_target(head, stack2, &i_target);
		print_itarget(i_target);
		exec_instr(&head, &stack2, i_target);
		printf("---------------------------------\n");
			printf("		stack1\n");
			print_list(head);
			printf("		stack2\n");
			print_list(stack2);
		free(i_target);
	}
	sort_stack1(&head)
	{
		
	}
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
