#include "push_swap.h"
#include "libft/ft_atoi.c"

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

tt_list	*add_node(tt_list *nlist, int data)
{
	tt_list	*new;

	new = malloc(sizeof(tt_list));
	new -> prev = nlist;
	new -> data = data;
	new -> next = NULL;
	return (new);
}

tt_list	*delfirst(tt_list  *lst)
{
	tt_list	*new_head;
	tt_list	*lst_prev;

	new_head = lst->next;
	lst_prev = lst->prev;
	free (lst->next);
	free (lst);
	new_head->prev = lst_prev;
	lst_prev->next = new_head;
	return (new_head);
}

void	move_first(tt_list *stack1, tt_list *stack2)
{
	int	tmp;

	tmp = stack1->data;
	stack2 = add_node(stack2, tmp);
	stack1 = delfirst(stack1);
	printf("		stack1\n");
	print_list(stack1);
	printf("		stack2\n");
	print_list(stack2);
}
void	sorting(tt_list *stack1, tt_list *stack2)
{
	move_first(stack1, stack2);
}

void	swap_data(tt_list *n1, tt_list *n2)
{
	int	tmp;

	tmp = n1 -> data;
	n1 -> data = n2 -> data;
	n2 -> data = tmp;
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
	while(lst->next != NULL)
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

int	main(int argc, char *argv[])
{
	tt_list *nlist;
	tt_list	*head;
	tt_list	*stack2;

	if (argc > 2)
	{
		argv++;
		nlist = init_list(ft_atoi(*argv));
		argv++;
	}
	head = nlist;
	stack2 = malloc(sizeof(stack2));
	while (*argv)
	{
		nlist -> next = add_node(nlist, ft_atoi(*argv));
		argv++;
		nlist = nlist -> next;
	}
	head->prev = nlist; 
	print_list(head);
	//swap_data((head->next->next), (head->next));
	//print_list_back(nlist);
	if (check_if_sorted(head))
	{
		printf("already sorted\n");
		return (0);
	}
	sorting(nlist, stack2);
}
