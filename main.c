#include "push_swap.h"
#include "list_operations.c"   //for debugger only
#include "instructions.c"    //for debugger only
#include "sortingB.c"    //for debugger only
#include "sortingA.c"    //for debugger only
#include "libft/ft_atoi.c"

int	check_if_sorted_final(tt_list *lst)
{
	int	head;

	head = lst->data;
	while(lst->next->data != head)
	{
		if (lst->data < lst->next->data)
			lst = lst->next;
		else
		{
			if (lst->next->data == head)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	tt_list *nlist;
	tt_list	*head;
	tt_list	*stack2;
	i_list	*i_target;

	if (argc < 2)
		return (0);
	i_target = malloc(sizeof(i_list));
	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;
	
	nlist = malloc(sizeof(tt_list));
	argv++;
	nlist->prev = NULL;
	nlist->data = ft_atoi(*argv);
	nlist ->next = NULL;
	head = nlist;
	argv++;
	while (*argv)
	{
		nlist->next = add_node(nlist, ft_atoi(*argv));
		argv++;
		nlist = nlist->next;
	}
	head->prev = nlist; 
	nlist->next  = head;
//	print_list(head);
	if (check_if_sorted(head))
	{
		printf("already sorted\n");
		return (0);
	}
	// printf("stack2 size = %i\n", ft_llstsize(stack2));
	while (ft_llstsize(stack2) < 2)
	{
		pb(&head, &stack2);
		write(1, "pb\n", 3);
		// printf("---------------------------------\n");
		// printf("		stack1\n");
		// print_list(head);
		// printf("		stack2\n");
		// print_list(stack2);
	}
	// printf("---------------------------------\n");
	// 	printf("		stack1\n");
	// 	print_list(head);
	// 	printf("		stack2\n");
	// 	print_list(stack2);
	while (ft_llstsize(head) > 3)
	{
		i_target = malloc(sizeof(i_list));
		find_target(head, stack2, &i_target);
		printf("will print target\n");
		print_itarget(i_target);
		exec_instr(&head, &stack2, i_target);
		if (check_if_sorted(head))
			break;
		// printf("---------------------------------\n");
		// 	printf("		stack1\n");
		// 	print_list(head);
		// 	printf("		stack2\n");
		// 	print_list(stack2);
		free(i_target);
	}
	// printf("-----BEFORE SORTING A -----\n");
	// 		printf("		stack1\n");
	// 		print_list(head);
	sort_3(&head);
	min_to_top(&head);
	// printf("-----I WILL PUSH BACK TO 	A-----\n");
	// 		printf("		stack1\n");
	// 		print_list(head);
	// 		printf("		stack2\n");
	// 		print_list(stack2);
	while (ft_llstsize(stack2) >= 1)
	{
		i_target = malloc(sizeof(i_list));
		find_targetA(stack2, head, &i_target);
		//print_itarget(i_target);
		//printf("fail here-instructions\n");
		exec_instr(&stack2, &head, i_target);
		// printf("---------------------------------\n");
		// 	printf("		stack1\n");
		// 	print_list(head);
		// 	//printf("fail here\n");
		// 	printf("		stack2\n");
		// 	print_list(stack2);
		free(i_target);
	}
	// printf("---------------------------------\n");
	// 		printf("		before MIN TO TOP		\n");
	// 		print_list(head);
	min_to_top(&head);
	//head = get_min(head, ft_llstsize(head));
	// printf("---------------------------------\n");
	// 		printf("		RESULT		\n");
	// 		print_list(head);
	if (check_if_sorted_final(head))
	{
		// printf("already sorted\n");
		return (0);
	}
}
