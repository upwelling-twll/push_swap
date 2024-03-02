#include "../rsc_push_swap/push_swap.h"
//#include "checker_inc.c"
//#include "checker_flag.c"
#include "../libft/ft_atoi.c"
#include "checker.h"

int main(int argc, char *argv[])
{
	char *ins;
	t_llist	*lst;
	t_llist	*head;
	t_llist	*stack2;
	t_chins	*oper;
	t_chins	*hoper;
	int i;

	i = 0;
	if (argc < 2)
		return (0);
	lst = malloc(sizeof(t_llist));
	lst = NULL;
	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;
	argv++;
	// if (is_flag(*argv))
	// {
	// 	process_flag_input(argv);
	// }
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
		lst->next = add_node(lst, ft_atoi(*argv));
		lst->next->next = head;
		argv++;
		lst = lst->next;
	}
	head->prev = lst; 
	lst->next  = head;
//1) add instructions from stdin to the list instr *oper;
	oper = malloc(sizeof(t_chins));
	ins = read_stdin(0);
	oper = add_node_ins(oper,ins);
	hoper = oper;
	while (ins != NULL)
	{
		free(ins);
		ins = read_stdin(0);
		if (!ins)
			break;
		oper->next = add_node_ins(oper, ins);
		oper = oper->next;
	}
	oper = hoper;
	i = 0;
	while (oper != NULL)
	{
		if (!(oper_valid_apply(oper, &head, &stack2, hoper)))
		{
			return (0);
		}
		oper = oper ->next;
	}
	if (!(check_if_sorted(head)) || ft_llstsize(stack2) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (0);
}
