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

	lst = malloc(sizeof(tt_list));
	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;
	if (argc < 2)
		return (0);
	argv++;
	lst = add_node(lst, ft_atoi(*argv));
	head = lst;
	argv++;
	while (*argv)
	{
		lst->next = add_node(lst, ft_atoi(*argv));
		argv++;
		lst = lst->next;
	}
	head->prev = lst; 
	lst->next  = head;
	print_list(head);
//1) add instructions from stdin to the list instr *oper;
	oper = malloc(sizeof(oper));
	hoper = oper;
	while ((ins = get_next_line(0)) != NULL)
	{
		add_node_ins(oper, ins);
		oper = oper->next;
		free(ins);
	}
	oper = hoper;
//2) process instructions from the list by alidation and apply
	while ((ins = get_next_line(0)) != NULL)
	{
		if ((valid_ins(ins)) != 0)
			apply_ins(&lst, &stack2, ins);
		else
			return (ft_exit(lst, oper, 1));
		free(ins);
	}
}