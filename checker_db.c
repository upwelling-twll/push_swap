#include "push_swap.h"
 #include "checker_inc.c"
#include "libft/ft_atoi.c"
// #include "instructions.c"
// #include "list_operations.c"
// #include "sortingA.c"
// #include "sortingB.c"
// #include "get_next_line.c"
// #include "get_next_line_utils.c"

// int main(int argc, char *argv[])
int main(void)
{
	char *ins;
	tt_list	*lst;
	tt_list	*head;
	tt_list	*stack2;
	t_instr	*oper;
	t_instr	*hoper;
	int i=0;

	char *str1 = "pb";
	char *str2 = "pb";
	char *str3 = "rr";
	char *str4 = "rrb";
	char *str5 = "pb";
	char *str6 = "pb";
	char *str7 = "sa";
	char *str8 = "ra";
	char *str9 = "sa";


	lst = malloc(sizeof(tt_list));
	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;

	// if (argc < 2)
	// 	return (0);
	//argv++;
	//lst = add_node(lst, ft_atoi("1")); //atoi(*argv)
	lst = add_node(lst, rand());
	head = lst;
	i = 9;
	while (i<15)
	{
		lst->next = add_node(lst, rand());
		i++;
		lst = lst->next;
	}
	//argv++;
	// while (*argv)
	// {
	// 	lst->next = add_node(lst, ft_atoi(*argv));
	// 	argv++;
	// 	lst = lst->next;
	// }
	head->prev = lst; 
	lst->next  = head;
	print_list(head);
//1) add instructions from stdin to the list instr *oper;
	oper = malloc(sizeof(t_instr));
	oper = add_node_ins(oper, str1);
	hoper = oper;

	oper->next = add_node_ins(oper, str2);
	oper = oper->next;
	oper->next = add_node_ins(oper, str3);
	oper = oper->next;
	oper->next = add_node_ins(oper, str4);
	oper = oper->next;
	oper->next = add_node_ins(oper, str5);
	oper = oper->next;
	oper ->next= add_node_ins(oper, str6);
	oper = oper->next;
	oper ->next= add_node_ins(oper, str7);
	oper = oper->next;
	oper ->next= add_node_ins(oper, str8);
	oper = oper->next;
	oper ->next= add_node_ins(oper, str9);
	oper = oper->next;
	oper = hoper;
	printf("here are instrs\n");
	print_list_ins(oper);
	printf("all\n");
	// while (1)
	// {
	// 	ins = get_next_line(0);
	// 	add_node_ins(oper, ins);
	// 	oper = oper->next;
	// 	free(ins);
	// }
	// oper = hoper;
	//ft_exit(head, oper, 1);
	i = 0;
	int j = 0;
	while (j < 6)
	{
		if ((i = valid_ins(oper->content)) >= 0)
			apply_ins(&lst, &stack2, pssbl_op[i]);
		else
			return (ft_exit(lst, oper, 1));
		printf("%i instruction applyed\n", i);
		oper = oper->next;
		j++;
	}

//2) process instructions from the list by alidation and apply
	// while ((ins = get_next_line(0)) != NULL)
	// {
	// 	if ((i = valid_ins(ins)) >= 0)
	// 		apply_ins(&lst, &stack2, pssbl_op[i]);
	// 	else
	// 		return (ft_exit(lst, oper, 1));
	//	oper = oper ->next;
	// }
	return (0);
}