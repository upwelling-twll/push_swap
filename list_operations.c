#include "push_swap.h"

int	cmp(int a, int b)
{
	if (a < b)
		return (1);
	return(0);
}

void	sort_3(tt_list **lst)
{
	int tmp;
	tt_list	*swap;
	tt_list	*head;

	swap = *lst;
	head = *lst;
	while((*lst)->next!= head)
	{ 
		if ((*cmp)((*lst)->data, (*lst)->next->data) == 0)
		{
			tmp = (*lst)->data;
			(*lst)->data = (*lst)->next->data;
			(*lst)->next->data = tmp;
			*lst = swap;
		}
		else
			*lst = (*lst)->next;
	}
	*lst = swap;
}

void	print_itarget(i_list *lst)
{
	printf("will print target\n");
	printf("target_data:%i\n", lst->target);
	printf("s1_rotate_up:%i\n", lst->s1_rotate_up);
	printf("s1_rotate_down:%i\n", lst->s1_rotate_down);
	printf("s2_rotate_up:%i\n", lst->s2_rotate_up);
	printf("s2_rotate_down:%i\n", lst->s2_rotate_down);
	printf("mood:%i\n", lst->mood);
}

void	print_list(tt_list *lst)
{
	tt_list	*head;

	head = lst;
	if (lst == NULL)
	{
		printf("empty\n");
		return;
	}
	printf("data:%d\n", lst->data);
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
	//tt_list	*next;
	int		head;

	if (lst == NULL)
		return (0);
	head = lst->data;
	//next = lst->next;
	i = 1;
	while (lst->next->data != head)
	{
		lst = lst -> next;
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
			if (lst->next != head)
				lst = lst->next;
			else
				return (1);
		}
		else
			return (0);
	}
	return (1);
}
