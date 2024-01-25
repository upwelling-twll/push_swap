#include "push_swap.h"
#include "libft/ft_atoi.c"


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

	//swap_data((head->next->next), (head->next));
	//print_list_back(nlist);
	// if (check_if_sorted(head))
	// {
	// 	printf("already sorted\n");
	// 	return (0);
	// }
	// printf("last_elem_stack1=%d\n", (ft_llstlast(head))->data);
	// printf("list1_size=%d\n", ft_llstsize(head));
	// printf("list2_size=%d\n", ft_llstsize(stack2));
	// while (ft_llstsize(head) > 3)
	// {
	// 	pb(&head, &stack2);
	// 	printf("		stack1\n");
	// 	print_list(head);
	// 	printf("		stack2\n");
	// 	print_list(stack2);
	// }

	// sa(head);
	rra(&head);
	printf("		stack1\n");
	print_list(head);
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
