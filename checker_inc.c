#include "push_swap.h"

#  define SA "sa"
#  define SB "sb"
#  define SS "ss"
#  define PA "pa"
#  define PB "pb"
#  define RA "ra"
#  define RB "rb"
#  define RR "rr"
#  define RRA "rra"
#  define RRB "rrb"
#  define RRR "rrr"

static char *pssbl_op_list[]={SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

// this is a new type - function pointer type which will be used for instruction functions;
typedef void	(*ins_func)(tt_list **, tt_list **);

//this a definition of arrey of function pointers to instruction finctions;
ins_func	pssbl_op[]={sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

typedef struct in_list
{
	char			*content;
	struct in_list	*next;
}					t_instr;

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != '\0')
	{
		if (*(s1 + i) == *(s2 + i))
		{
			i++;
		}
		else if (*(s1 + i) > *(s2 + i))
			return (1);
		else if (*(s1 + i) < *(s2 + i))
			return (-1);
	}
	if (*(s1 + i) == *(s2 + i))
		return (0);
	if (*(s1 + i) > *(s2 + i))
		return (1);
	return (-1);
}


void	print_list_ins(t_instr *lst)
{
	if (lst == NULL)
	{
		printf("instr empty\n");
		return;
	}
	while(lst != NULL)
	{
		printf("instr:%s\n", lst->content);
		lst = lst -> next;
	}
}


t_instr	*add_node_ins(t_instr *lst, char *ins)
{
	t_instr	*new;

	new = malloc(sizeof(t_instr));
	new -> content = ins;
	new -> next = NULL;
	return (new);
}

int	valid_ins(char *ins)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if ((ft_strcmp(ins, pssbl_op_list[i]) == 0))
			return (i);
		i++;
	}
	return (-1);
}

void	apply_ins(tt_list **stack1, tt_list **stack2, ins_func ins_recived)
{
	ins_recived(stack1, stack2);
}

void	del_instr_list(t_instr *lst)
{
	t_instr	*tmp;
	t_instr	*tmp2;

	while (lst)
	{
		tmp = lst->next;
		if (!lst)
			break ;
		tmp2 = lst;
		if (lst)
		{
			free(tmp2->content);
			free(tmp2);
		}
		lst = tmp;
	}
}

int	ft_exit(tt_list *lst, t_instr *oper, int display)
{
	tt_list	*tmp;
	tt_list	*tmp2;

	while (lst)
	{
		tmp = lst->next;
		if (!lst)
			break ;
		tmp2 = lst;
		if (lst)
			free(tmp2);
		lst = tmp;
	}
	if (oper)
		del_instr_list(oper);
	if (display == 1)
		write(1, "instuction does not exist\n", 26);
	else if (display == 2)
		write(1, "instructions did not sort the stack\n", 36);
	return (0);
}