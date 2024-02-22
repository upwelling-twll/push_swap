#include "push_swap.h"

tt_list *sort_2(tt_list **lst)
{
	if ((*lst)->data > (*lst)->next->data)
	{
		ra(lst, NULL);
		write(1, "ra\n", 3);
	}
	return(*lst);
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
		write(2, "Error\n", 6);
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
