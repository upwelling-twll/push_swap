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


void	print_list_ins(t_chins *lst)
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


t_chins	*add_node_ins(t_chins *lst, char *ins)
{
	t_chins	*new;

	new = malloc(sizeof(t_chins));
	new->content = strdup(ins);
	new -> next = NULL;
	return (new);
}

int	valid_ins(char *ins)
{
	int i;

	i = 0;
	//printf("instr i receive:%s\n", ins);
	while (i < 11) // 11 is a number of posible instructions;
	{
		//printf("compare instruction:%s$ and element:%s$\n", ins, pssbl_op_list[i]);
		if ((ft_strcmp(ins, pssbl_op_list[i]) == 0))
			return (i);
		i++;
	}
	printf("is  not valid valid\n");
	return (-1);
}

int	apply_ins(t_llist **stack1, t_llist **stack2, ins_func ins_recived)
{
	//printf("will apply instr\n");
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
	// printf("---** stack1 **---\n");
	// print_list(*stack1);
	// printf("====stack2=====\n");
	// print_list(*stack2);
}

void	del_instr_list(t_chins *lst)
{
	t_chins	*tmp;
	t_chins	*tmp2;

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

char	*read_stdin(int fd)
{
	char	*str;
	char	*res;
	size_t	len;

	str = get_next_line(fd);
	if (str)
	{
		if (ft_strchr(str, '\n'))
		{
			res = malloc(sizeof(char) * ft_strlen(str));
			ft_strlcpy(res, str, ft_strlen(str));
			return (res);
		}
	}
	return (str);
}

void	del_stack_lst_ch(t_llist *lst)
{
	t_llist	*tmp;
	t_llist	*tmp2;
	int		size;

	size = ft_llstsize(lst);
	while (size)
	{
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

int	ft_exit(t_llist *st1, t_llist *st2, t_chins *oper, int display)
{
	printf("\nmission aborted with flag %i\n", display);
	if (st1)
		del_stack_lst_ch(st1);
		printf("s1 deleted\n");
	if (st2)
		del_stack_lst_ch(st2);
		printf("s2 deleted\n");
	if (oper)
		del_instr_list(oper);
	if (display == 1)
		write(2, "Error\n", 6);
	else if (display == 2)
		write(1, "KO\n", 3);
	return (0);
}

int	oper_valid_apply(t_chins *oper, t_llist **head, t_llist **stack2, t_chins *hoper)
{
	int	i;

	if ((i = valid_ins(oper->content)) >= 0)
	{
		if (!(apply_ins(head, stack2, pssbl_op[i])))
			return (ft_exit(*head, *stack2, hoper, 2)); // maybe replace lst to head
	}
	else
		return (ft_exit(*head, *stack2, hoper, 1)); // maybe replace lst to head
	return (1);
}

int	split_parse_fill_argv_ch(char *argv, t_llist **stack1)
{
	char	**str;

	str = ft_split(argv, ' ');
	if (!(str))
		return (ft_exit(*stack1, NULL, NULL, 1));
	if (!(fill_stack1_argv(str, stack1)))
	{
		ft_cleanstr_ext(str, ft_splsize(str));
		return (ft_exit(*stack1, NULL, NULL, 1));
	}
	return (1);
}

int	more_args_ch(int argc, char *argv[], t_llist **stack1)
{
	argc--;
	argv++;
	while (argc >= 2)
	{
		if (!(split_parse_fill_argv_ch(*argv, stack1)))
			return (0);
		argc--;
		argv++;
	}
	return (1);
}

int	fill_num_stack(char **str, t_llist **stack1)
{
	t_llist	*head;
	char	**str_h;

	str_h = str;
	(*stack1)->prev = *stack1;
	(*stack1)->data = ft_atoi(*str);
	(*stack1)->next = *stack1;
	head = *stack1;
	str++;
	while (*str != NULL)
	{
		if ((!(verify_argv(head, *str))))
		{
			ft_cleanstr_ext(str, ft_splsize(str));
			return (ft_exit(*stack1, NULL, NULL, 1));
		}
		(*stack1)->next = add_node(*stack1, ft_atoi(*str));
		head->prev = *stack1;
		str++;
		*stack1 = (*stack1)->next;
		(*stack1)->next = head;
	}
	head->prev = *stack1;
	(*stack1)->next = head;
	*stack1 = head;
	str = str_h;
	ft_cleanstr_ext(str, ft_splsize(str));
	return (1);
}

int	ft_parse_input_ch(int argc, char *argv[], t_llist **stack1)
{
	t_llist	*head;
	char	**str;

	str = (check_frst_arg(argc, argv, stack1));
	if (!(str))
		return (0);
	if ((!(verify_argv(NULL, *str))))
	{
		ft_cleanstr_ext(str, ft_splsize(str));
		return (ft_exit(*stack1, NULL, NULL, 1));
	}
	if (!fill_num_stack(str, stack1))
		return (0);
	argv++;
	if (!(more_args_ch(argc, argv, stack1)))
		return (0);
	head = *stack1;
	return (1);
}
