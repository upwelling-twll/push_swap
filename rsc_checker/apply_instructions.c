#include "../rsc_push_swap/push_swap.h"
#include "../libft/ft_strdup.c"
#include "../libft/ft_memcpy.c"
#include "../libft/ft_strlen.c"
#include "../libft/ft_strchr.c"
#include "../libft/ft_strlcpy.c"
#include "../libft/ft_isdigit.c"
# include "../libft/ft_split.c"
#include "checker.h" 

#  define SA "sa" //1
#  define SB "sb" //2
#  define SS "ss" //3
#  define PA "pa" //4
#  define PB "pb" //5
#  define RA "ra" //6
#  define RB "rb" //7
#  define RR "rr" //8
#  define RRA "rra" //9
#  define RRB "rrb" //10
#  define RRR "rrr" //11

static char *pssbl_op_list[]={SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

// this is a new type - function pointer type which will be used for instruction functions;
typedef int	(*ins_func)(t_llist **, t_llist **);

//this a definition of arrey of function pointers to instruction finctions;
ins_func	pssbl_op[]={sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

int	apply_ins(t_llist **stack1, t_llist **stack2, ins_func ins_recived)
{
	if (ins_recived == rrb)
	{
		if (ins_recived(stack2, stack1))
			return (1);
		return (0);
	}
	else if (ins_recived == rb)
	{
		if (ins_recived(stack2, stack1))
			return (1);
		return (0);
	}
	if (ins_recived(stack1, stack2))
		return (1);
	return (0);
}

int	valid_ins(char *ins)
{
	int i;

	i = 0;
	while (i < 11)
	{
		if ((ft_strcmp(ins, pssbl_op_list[i]) == 0))
			return (i);
		i++;
	}
	return (-1);
}

int	proc_all(t_chins *oper, t_llist **head, t_llist **stack2, t_chins *hoper)
{
	int	i;

	if ((i = valid_ins(oper->content)) >= 0)
	{
		if (!(apply_ins(head, stack2, pssbl_op[i])))
			return (ft_exit(*head, *stack2, hoper, 2));
	}
	else
		return (ft_exit(*head, *stack2, hoper, 1));
	return (1);
}

int	apply_instructions(t_llist **lst, t_llist **stack2, t_chins *oper)
{
	t_chins	*hoper;
	int		i;

	i = 0;
	hoper = oper;
	while (oper != NULL)
	{
		if (!(proc_all(oper, lst, stack2, hoper)))
			return (0);
		oper = oper ->next;
	}
	if (!(check_if_sorted(*lst)) || ft_llstsize(*stack2) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return(ft_exit(*lst, *stack2, hoper, 0));
}
