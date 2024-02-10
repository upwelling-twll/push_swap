#include "push_swap.h"
#include "libft/ft_strdup.c"
#include "libft/ft_memcpy.c"
#include "libft/ft_strlen.c"
#include "libft/ft_strchr.c"
#include "libft/ft_strlcpy.c"

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
	new->content = strdup(ins);
	new -> next = NULL;
	return (new);
}

int	valid_ins(char *ins)
{
	int i;

	i = 0;
	printf("instr i receive:%s\n", ins);
	while (i < 11)
	{
		printf("compare instruction:%s$ and element:%s$\n", ins, pssbl_op_list[i]);
		if ((ft_strcmp(ins, pssbl_op_list[i]) == 0))
			return (i);
		i++;
	}
	printf("is  not valid valid\n");
	return (-1);
}

void	apply_ins(tt_list **stack1, tt_list **stack2, ins_func ins_recived)
{
	printf("will apply instr\n");
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