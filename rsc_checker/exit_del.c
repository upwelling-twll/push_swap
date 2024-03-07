#include "checker.h"

t_llist	*delfirst(t_llist *lst)
{
	t_llist	*new_head;
	t_llist	*lst_prev;

	if (ft_llstsize(lst) == 1)
	{
		free (lst);
		return (NULL);
	}
	new_head = lst->next;
	lst_prev = lst->prev;
	new_head->prev = lst_prev;
	lst_prev->next = new_head;
	free (lst);
	lst = new_head;
	return (new_head);
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
	if (st1)
		del_stack_lst_ch(st1);
	if (st2)
		del_stack_lst_ch(st2);
	if (oper)
		del_instr_list(oper);
	if (display == 1)
		write(2, "Error\n", 6);
	else if (display == 2)
		write(1, "KO\n", 3);
	else if (display == 3)
		write(1, "OK\n", 3);
	return (0);
}
