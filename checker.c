#include "push_swap.h"
#include "checker_inc.c"
#include "libft/ft_atoi.c"


int main(int argc, char *argv[])
{
	char *ins;
	tt_list	*lst;
	tt_list	*head;
	tt_list	*stack2;
	t_instr	*oper;
	t_instr	*hoper;
	int i;

	i = 0;
	lst = malloc(sizeof(tt_list));
	lst = NULL;
	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;
	if (argc < 2)
		return (0);
	argv++;
	if (!(verify_argv(lst, *argv)))
			return(ft_exit(lst, stack2, NULL, 1));
	else
	{
		lst = add_node(lst, ft_atoi(*argv));
		lst->next = lst;
		lst->prev = lst;
		head = lst;
		argv++;
	}
	while (*argv)
	{
		if (!(verify_argv(head, *argv)))
			return(ft_exit(head, stack2, NULL, 1));
		printf("will add\n");
		lst->next = add_node(lst, ft_atoi(*argv));
		argv++;
		lst = lst->next;
		printf("lst_size=%i\n", ft_llstsize(head));
	}
	head->prev = lst; 
	lst->next  = head;
	print_list(head);
//1) add instructions from stdin to the list instr *oper;
	oper = malloc(sizeof(t_instr));
	ins = read_stdin(0);
	oper = add_node_ins(oper,ins);
	hoper = oper;
	while (ins != NULL)
	{
		free(ins);
		ins = read_stdin(0);
		//printf("ins to search:%s$\n", ins);
		if (!ins)
			break;
		oper->next = add_node_ins(oper, ins);
		oper = oper->next;
	}
	oper = hoper;
	printf("operations list has %i elements\n", i);
//2) process instructions from the list by alidation and apply
	printf("BEFORE instructions---** stack1 **---\n");
	print_list(head);
	printf("BEFORE instructions====stack2=====\n");
	print_list(stack2);
	i = 0;
	while (oper != NULL)
	{
		if ((i = valid_ins(oper->content)) >= 0)
			apply_ins(&head, &stack2, pssbl_op[i]);
		else
			return (ft_exit(lst, stack2, oper, 1));
		oper = oper ->next;
	}
	printf("RESULT---** stack1 **---\n");
	print_list(head);
	printf("RESULT====stack2=====\n");
	print_list(stack2);
	if (!(check_if_sorted(head)) || ft_llstsize(stack2) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (0);
}