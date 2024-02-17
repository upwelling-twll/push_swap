#include "push_swap.h"
#include "libft/ft_strdup.c"
#include "libft/ft_memcpy.c"
#include "libft/ft_strlen.c"
#include "libft/ft_strchr.c"
#include "libft/ft_strlcpy.c"
#include "libft/ft_isdigit.c"

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
typedef int	(*ins_func)(tt_list **, tt_list **);

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
	new->content = strdup(ins);
	new -> next = NULL;
	return (new);
}

int	valid_ins(char *ins)
{
	int i;

	i = 0;
	printf("instr i receive:%s\n", ins);
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

int	apply_ins(tt_list **stack1, tt_list **stack2, ins_func ins_recived)
{
	printf("will apply instr\n");
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
	size = ft_llstsize(args_lst);
	while(size)
	{
		if (args_lst->data == num)
			return (0);
		args_lst = args_lst->next;
		size--;
	}
	return(1);
}

void	del_stack_lst(tt_list *lst)
{
	tt_list	*tmp;
	tt_list	*tmp2;
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

int	ft_exit(tt_list *st1, tt_list *st2, t_instr *oper, int display)
{
	printf("\nmission aborted with flag %i\n", display);
	if (st1)
		del_stack_lst(st1);
		printf("s1 deleted\n");
	if (st2)
		del_stack_lst(st2);
		printf("s2 deleted\n");
	if (oper)
		del_instr_list(oper);
	if (display == 1)
		write(1, "Error\n", 6);
	else if (display == 2)
		write(1, "KO\n", 3);
	return (0);
}