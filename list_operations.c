#include "push_swap.h"

int	cmp(int a, int b)
{
	if (a < b)
		return (1);
	return(0);
}

void	float_to_top(tt_list **head, tt_list *new_head)
{
	//printf("min to top\n");
	tt_list	*cplist;
	int	position;

	cplist = *head;
	position = 0;
	if (new_head == *head)
		return;
	while(cplist->next != new_head)
	{
		cplist = cplist->next;
		position++;
	}
	// printf("new head= %i\n", new_head->data);
	// printf("position=%i\n", position);
	
	if (position <= (ft_llstsize(*head) / 2))
	{
		while (position) //rotating until the element which is prev to min is not on the top
		{
			ra(head, NULL);
			write(1, "ra\n", 3);
			position--;
		}
	}
	else
	{
		position = ft_llstsize(*head) - position - 1;
		while (position) //rotating until the element which is prev to min is not on the top
		{
			rra(head, NULL);
			write(1, "rra\n", 4);
			position--;
		}
	}

}

#define RA_STR (dr == 1 ? "ra\n" : "rb\n")
#define RRB_STR (dr == 1 ? "rrb\n" : "rra\n")

void	run(tt_list **lst, int opt)
{
	if (opt == 1) 
		sa(*lst, NULL);
	if (opt == 2)
		rra(*lst, NULL);
	if (opt == 3)
	{
		run(lst, 1);
		run(lst, 2);
	}
	if (opt == 4)
	{
		run(lst, 2);
		run(lst, 2);
	}
	if (opt == 5)
	{
		run(lst, 2);
		run(lst, 1);
	}
	write(1, )
}

void	sort_3(tt_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->data;
	b = (*lst)->next->data;
	c = (*lst)->prev->data;
	if (a > b && a < c)
		run(lst, 1);
	else if (a > c && a < b)
		run(lst, 2);
	else if (a > b && b > c)
		run (lst, 3);
	else if (a < b && b < c)
		run (lst, 4);
	else if (a < b && b > c)
		run (lst, 5);
	return;	
}
	// while(!(check_if_sorted(cphead)))
	// { 
	// 	if ((*cmp)((*lst)->data, (*lst)->next->data) == 0)
	// 	{
	// 		float_to_top(head_ad, (*lst)->next);
	// 		sa(head_ad, NULL);
	// 		write(1, "sa\n", 3);
	// 		// tmp = (*lst)->data;
	// 		// (*lst)->data = (*lst)->next->data;
	// 		// (*lst)->next->data = tmp;
	// 		// *lst = swap;
	// 	}
	// 	else
	// 		*lst = (*lst)->next;
	// }
// }

void	print_itarget(i_list *lst)
{
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
	lst = lst->next;
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

void	min_to_top(tt_list **lst)
{
	tt_list	*min;

	min = get_min(*lst, ft_llstsize(*lst));

	float_to_top(lst, min);
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



