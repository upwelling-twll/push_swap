#include "push_swap.h"
// #include "list_operations.c"   //for debugger only
// #include "instructions.c"    //for debugger only
// #include "sortingB.c"    //for debugger only
// #include "sortingA.c"    //for debugger only
#include "libft/ft_atoi.c"

// int	main(void)
// {
// 	tt_list *nlist;
// 	tt_list	*head;
// 	tt_list	*stack2;
// 	i_list	*i_target;

// 	i_target = malloc(sizeof(i_list));
// 	stack2 = malloc(sizeof(stack2));
// 	stack2 = NULL;
	
// 	nlist = malloc(sizeof(tt_list));
	
// 	nlist->prev = NULL;
// 	nlist->data = -99998;
// 	nlist ->next = NULL;
// 	head = nlist;

// 	nlist -> next = add_node(nlist, -1);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, 0);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, -3);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, -10);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, 4444999);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, -44155);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, 654440);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, -33);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, 44150);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, -89559);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, 9);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, -500302);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, 45002);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, 333402);
// 	nlist = nlist -> next;

// 	nlist -> next = add_node(nlist, 32000);
// 	nlist = nlist -> next;
// 	nlist -> next = head;

// 	head->prev = nlist; 
 
// 	printf("		stack1\n");
// 	print_list(head);
// 	printf("---------------------------------\n");
// 	while (ft_llstsize(stack2) < 2)
// 	{
// 		pb(&head, &stack2);
// 		printf("---------------------------------\n");
// 		printf("		stack1\n");
// 		print_list(head);
// 		printf("		stack2\n");
// 		print_list(stack2);
// 	}
// 	while (ft_llstsize(head) > 3)
// 	{
// 		i_target = malloc(sizeof(i_list));
// 		find_target(head, stack2, &i_target);
// 		print_itarget(i_target);
// 		exec_instr(&head, &stack2, i_target);
// 		if (check_if_sorted(head))
// 			break;
// 		printf("---------------------------------\n");
// 			printf("		stack1\n");
// 			print_list(head);
// 			printf("		stack2\n");
// 			print_list(stack2);
// 		free(i_target);
// 	}
// 	sort_3(&head);
// 	printf("-----I WILL PUSH BACK TO 	A-----\n");
// 			printf("		stack1\n");
// 			print_list(head);
// 			printf("		stack2\n");
// 			print_list(stack2);
// 	while (ft_llstsize(stack2) >= 1)
// 	{
// 		i_target = malloc(sizeof(i_list));
// 		find_targetA(stack2, head, &i_target);
// 		print_itarget(i_target);
// 		//printf("fail here-instructions\n");
// 		exec_instr(&stack2, &head, i_target);
// 		printf("---------------------------------\n");
// 			printf("		stack1\n");
// 			print_list(head);
// 			//printf("fail here\n");
// 			printf("		stack2\n");
// 			print_list(stack2);
// 		free(i_target);
// 	}
// 	printf("---------------------------------\n");
// 			printf("		RESULT		\n");
// 			print_list(get_min(head, ft_llstsize(head)));
// }
// 	// while (ft_llstsize(head) > 3)
// 	// {
// 	// 	find_target(head, stack2, &i_target);
// 	// 	print_itarget(i_target);
// 		//exec_instr(head, stack2);
// 		// pa(&head, &stack2);
// 		// printf("---------------------------------\n");
// 		// printf("		stack1\n");
// 		// print_list(head);
// 		// printf("		stack2\n");
// 		// print_list(stack2);
// //	}

int	main(int argc, char *argv[])
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
	nlist->data = -99998;
	nlist ->next = NULL;
	head = nlist;
	if (argc < 2)
		return (0);
	stack2 = malloc(sizeof(stack2));
	argv++;
	while (*argv)
	{
		nlist->next = add_node(nlist, ft_atoi(*argv));
		argv++;
		nlist = nlist->next;
	}
	nlist  = head;
	head->prev = nlist; 
	//print_list(head);
	// if (check_if_sorted(head))
	// {
	// 	printf("already sorted\n");
	// 	return (0);
	// }
	// while (ft_llstsize(stack2) < 2)
	// {
	// 	pb(&head, &stack2);
	// 	printf("---------------------------------\n");
	// 	printf("		stack1\n");
	// 	print_list(head);
	// 	printf("		stack2\n");
	// 	print_list(stack2);
	// }
	// while (ft_llstsize(head) > 3)
	// {
	// 	i_target = malloc(sizeof(i_list));
	// 	find_target(head, stack2, &i_target);
	// 	print_itarget(i_target);
	// 	exec_instr(&head, &stack2, i_target);
	// 	if (check_if_sorted(head))
	// 		break;
	// 	printf("---------------------------------\n");
	// 		printf("		stack1\n");
	// 		print_list(head);
	// 		printf("		stack2\n");
	// 		print_list(stack2);
	// 	free(i_target);
	// }
	// sort_3(&head);
	// printf("-----I WILL PUSH BACK TO 	A-----\n");
	// 		printf("		stack1\n");
	// 		print_list(head);
	// 		printf("		stack2\n");
	// 		print_list(stack2);
	// while (ft_llstsize(stack2) >= 1)
	// {
	// 	i_target = malloc(sizeof(i_list));
	// 	find_targetA(stack2, head, &i_target);
	// 	print_itarget(i_target);
	// 	//printf("fail here-instructions\n");
	// 	exec_instr(&stack2, &head, i_target);
	// 	printf("---------------------------------\n");
	// 		printf("		stack1\n");
	// 		print_list(head);
	// 		//printf("fail here\n");
	// 		printf("		stack2\n");
	// 		print_list(stack2);
	// 	free(i_target);
	// }
	// printf("---------------------------------\n");
	// 		printf("		RESULT		\n");
	// 		print_list(get_min(head, ft_llstsize(head)));
}
