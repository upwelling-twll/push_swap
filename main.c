#include "push_swap.h"
// #include "list_operations.c"   //for debugger only
// #include "instructions.c"    //for debugger only
// #include "sortingB.c"    //for debugger only
// #include "sortingA.c"    //for debugger only
#include "libft/ft_atoi.c"
#include "libft/ft_isdigit.c"

void	del_stack_lst(tt_list *lst)
{
	tt_list	*tmp;
	tt_list	*tmp2;
	int		size;

	size = ft_llstsize(lst);
	printf("size=%i\n", size);
	while (size)
	{
		printf("lst->data=%i\n", lst->data);
		tmp = lst->next;
		if (!lst)
			break ;
		tmp2 = lst;
		if (lst)
			free(tmp2);
		lst = tmp;
		size--;
	}
}

int	check_overflow(const char *str, int flag, int i)
{
	long long	n;
	long long	cn;

	n = 0;
	cn = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		if (n*flag > 2147483647 || n*flag < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	verify_atoi(const char *str)
{
	long long	i;
	long long	n;
	long long	flag;

	i = 0;
	flag = 1;
	if (str[i] == '-' && str[i + 1] != '\0')
		i++;
	while(str[i])
	{
		if (!(ft_isdigit(str[i])))
			return(0);
		i++;
	}
	i = 0;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	return (check_overflow(str, flag, i));
}

int	verify_argv(tt_list *args_lst, char *argv)
{
	int	num;
	int	size;

	if(!(verify_atoi(argv)))
		return (0);
	num = ft_atoi(argv);
	if (args_lst)
	{
		size = ft_llstsize(args_lst);
		while(size)
		{
			if (args_lst->data == num)
				return (0);
			args_lst = args_lst->next;
			size--;
		}
	}
	return(1);
}

int	ft_exit_ps(tt_list *st1, tt_list *st2, int display)
{
	if (st1)
		del_stack_lst(st1);
	if (st2)
		del_stack_lst(st2);
	if (display == 1)
		write(1, "Error\n", 6);
	else if (display == 2)
		write(1, "KO\n", 3);
	return (0);
}

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
	nlist = malloc(sizeof(tt_list));
	//nlist = NULL;
	argv++;
	if ((!(verify_argv(NULL, *argv))))
		return(ft_exit_ps(NULL, NULL, 2));
	nlist->prev = nlist;
	nlist->data = ft_atoi(*argv);
	nlist ->next = nlist;
	head = nlist;
	argv++;
	while (*argv)
	{
		if ((!(verify_argv(head, *argv))))
			return(ft_exit_ps(head, NULL, 2));
		nlist->next = add_node(nlist, ft_atoi(*argv));
		head->prev = nlist;
		argv++;
		nlist = nlist->next;
		nlist->next = head;
	}
	head->prev = nlist; 
	nlist->next  = head;
	if (check_if_sorted(head))
	{
		printf("already sorted\n");
		return (0);
	}
	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;
	while (ft_llstsize(stack2) < 2)
	{
		pb(&head, &stack2);
		write(1, "pb\n", 3);
	}
	i_target = malloc(sizeof(i_list));
	while (ft_llstsize(head) > 3)
	{
		//printf("---------------------------------\n");
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
		if (check_if_sorted(head))
			break;
		free(i_target);
	}
	// printf("---------------------------------\n");
	// 	printf("		stack1\n");
	// 		print_list(head);
	// printf("-------------need to sort_3 s1--------------------\n");
	// printf("		stack1\n");
	// print_list(head);
	// printf("		stack2\n");
	// print_list(stack2);

	sort_3(&head);

	//printf("-----min to top-----\n");
	min_to_top(&head);
	printf("-----I WILL PUSH BACK TO 	A-----\n");
			printf("		stack1\n");
			print_list(head);
			printf("		stack2\n");
			print_list(stack2);
	while (ft_llstsize(stack2) >= 1)
	{
		// printf("---------------------------------\n");
		// printf("		stack1\n");
		// 	print_list(head);
		// 	//printf("fail here\n");
		// 	printf("		stack2\n");
		// 	print_list(stack2);
		i_target = malloc(sizeof(i_list));
		find_targetA(stack2, head, &i_target);
		// printf("-   ---------  ----- -\n");
		// print_itarget(i_target);
		//printf("fail here-instructions\n");
		exec_instr(&stack2, &head, i_target, 2);
		printf("---------------------------------\n");
			printf("		stack1\n");
			print_list(head);
			//printf("fail here\n");
			printf("		stack2\n");
			print_list(stack2);
		free(i_target);
	}
	// printf("---------------------------------\n");
	// 		printf("		before MIN TO TOP		\n");
	// 		print_list(head);
	min_to_top(&head);
	head = get_min(head, ft_llstsize(head));
	printf("---------------------------------\n");
			printf("		RESULT		\n");
			print_list(head);
	if (check_if_sorted_final(head))
	{
		printf("sorted -OK\n");
		return (0);
	}
	else
	{
		printf(" not sorted -KO\n");
		return (0);
	}
}
