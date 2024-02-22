#include "push_swap.h"
// #include "list_operations.c"   //for debugger only
// #include "instructions.c"    //for debugger only
// #include "sortingB.c"    //for debugger only
// #include "sortingA.c"    //for debugger only
#include "libft/ft_atoi.c"
#include "libft/ft_isdigit.c"

int	main(int argc, char *argv[])
{
	tt_list *nlist;
	tt_list	*head;
	tt_list	*stack2;
	i_list	*i_target;
	int		p;

	if (argc < 2)
		return (0);
	nlist = malloc(sizeof(tt_list));
	//nlist = NULL;
	argv++;
	if ((!(verify_argv(NULL, *argv))))
		return(ft_exit_ps(NULL, NULL, 1));
	nlist->prev = nlist;
	nlist->data = ft_atoi(*argv);
	nlist ->next = nlist;
	head = nlist;
	argv++;
	while (*argv)
	{
		if ((!(verify_argv(head, *argv))))
			return(ft_exit_ps(head, NULL, 1));
		nlist->next = add_node(nlist, ft_atoi(*argv));
		head->prev = nlist;
		argv++;
		nlist = nlist->next;
		nlist->next = head;
	}
	head->prev = nlist; 
	nlist->next  = head;
	if (check_if_sorted(head) || ft_llstsize(head) == 1)
		return(ft_exit_ps(head, NULL, 0));
	if (ft_llstsize(head) == 2)
		return(ft_exit_ps(sort_2(&head), NULL, 0));

	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;
	while (ft_llstsize(stack2) < 2)
	{
		pb(&head, &stack2);
		write(1, "pb\n", 3);
	}
	i_target = malloc(sizeof(i_list));
	p = 0;
	while (ft_llstsize(head) > 3)
	{
		//printf("---------------------------------\n");
		// if ((p = presorted(head)) >= 0)
		// {
		// 	sort_presorted(&head, &stack2, p, &i_target);
		// 	break;
		// }
		//printf("sorting as usual\n");
		// printf("---------------------------------\n");
		// printf("		stack1\n");
		// 	print_list(head); 
		// 	//printf("fail here\n");
		// 	printf("		stack2\n");
		// 	print_list(stack2);
		i_target = malloc(sizeof(i_list));
		find_target(head, stack2, &i_target);
		//print_itarget(i_target);
		exec_instr(&head, &stack2, i_target, 1);
		// printf("---------------------------------\n");
		// printf("		stack1\n");
		// 	print_list(head);
		// 	//printf("fail here\n");
		// 	printf("		stack2\n");
		// 	print_list(stack2);
		free(i_target);
		if (check_if_sorted(head))
			break;
	}
	// printf("---------------------------------\n");
	// 	printf("		stack1\n");
	// 		print_list(head);
	// printf("-------------need to sort_3 s1--------------------\n");
	// printf("		stack1\n");
	// print_list(head);
	// printf("		stack2\n");
	// print_list(stack2);

	if (ft_llstsize(head) == 3)
	{
		sort_3(&head);
		//printf("-----min to top-----\n");
		min_to_top(&head);
	}
	// printf("-----I WILL PUSH BACK TO 	A-----\n");
	// 		printf("		stack1\n");
	// 		print_list(head);
	// 		printf("		stack2\n");
	// 		print_list(stack2);
	while (ft_llstsize(stack2) >= 1)
	{
		// printf("---------------------------------\n");
		// printf("		stack1\n");
		// 	print_list(head);
		// 	printf("		stack2\n");
		// 	print_list(stack2);
		i_target = malloc(sizeof(i_list));
		find_targetA(stack2, head, &i_target);
		// printf("-   ---------  ----- -\n");
		// print_itarget(i_target);
		exec_instr(&stack2, &head, i_target, 2);
		// printf("---------------------------------\n");
		// 	printf("		stack1\n");
		// 	print_list(head);
		// 	printf("		stack2\n");
		// 	print_list(stack2);
		free(i_target);
	}
	// printf("---------------------------------\n");
	// 		printf("		before min to top		\n");
	// 		print_list(head);
		min_to_top(&head);
			// printf("---------------------------------\n");
			// 	printf("		after min to top		\n");
			// 	print_list(head);
		head = get_min(head, ft_llstsize(head));
	// printf("---------------------------------\n");
	// 		printf("		RESULT		\n");
	// 		print_list(head);
	// 		printf("RESULT====stack2=====\n");
	// 		print_list(stack2);
	// if (check_if_sorted_final(head))
	// {
	// 	printf("sorted -OK\n");
	// 	return (0);
	// }
	// else
	// {
	// 	printf(" not sorted -KO\n");
		ft_exit_ps(head, stack2, 0);
		return (0);
//	}
}
