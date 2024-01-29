#include "push_swap.h"

void	print_itarget(i_list *lst)
{
	printf("will print target\n");
	//printf("target_data:%i\n", lst->target->data);
	printf("s1_rotate_up:%i\n", lst->s1_rotate_up);
	printf("s1_rotate_down:%i\n", lst->s1_rotate_down);
	printf("s2_rup_inum:%i\n", lst->s2_rup_inum);
	printf("s2_rdown_inum:%i\n", lst->s2_rdown_inum);
	printf("mood:%i\n", lst->mood);
}

void	print_list(tt_list *lst)
{
	tt_list	*head;

	head = lst;
	printf("data:%i\n", lst->data);
	lst = lst -> next;
	while(lst != head)
	{
		printf("data:%i\n", lst->data);
		lst = lst -> next;
	}
}

int	ft_llstsize(tt_list *lst)
{
	int		i;
	tt_list	*next;
	tt_list	*head;

	if (lst == NULL)
		return (0);
	head = lst;
	next = lst->next;
	i = 1;
	while (next != head)
	{
		next = next -> next;
		i++;
	}
	return (i);
}

tt_list	*ft_llstlast(tt_list *lst)
{
	int	i;

	if (!lst)
		return (lst);
	i = ft_llstsize(lst);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

tt_list	*init_list(int i)
{
	tt_list	*nlist;

	nlist = malloc(sizeof(tt_list)* 1);  //nlist = malloc(sizeof(*nlist)) - better to take sizeof(*nlist) because tt_list may be changed
	nlist -> prev = NULL;
	nlist -> data = i;
	nlist ->next = NULL;
	return (nlist);
}

int	check_if_sorted(tt_list *lst)
{
	tt_list	*head;

	head = lst;
	while(lst->next != head)
	{
		if (lst->data < lst->next->data)
		{
			if (lst->next)
				lst = lst->next;
			else
				return (1);
		}
		else
			return (0);
	}
	return (1);
}
