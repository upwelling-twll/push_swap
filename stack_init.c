#include "push_swap.h"
#include "libft/ft_atoi.c"

tt_list	*add_node(tt_list *nlist, int data)
{
	tt_list	*new;

	new = malloc(sizeof(tt_list));
	new -> prev = nlist;
	new -> data = data;
	new -> next = NULL;
	return (new);
}

tt_list	*init_list(int i)
{
	tt_list	*nlist;

	nlist = malloc(sizeof(tt_list)* 1);
	nlist -> prev = NULL;
	nlist -> data = i;
	nlist ->next = NULL;
	return (nlist);
}

void	print_list(tt_list *lst)
{
	while(lst != NULL)
	{
		printf("data:%i\n", lst->data);
		lst = lst -> next;
	}
}

void	print_list_back(tt_list *lst)
{
	while(lst != NULL) 
	{
		printf("back_data:%i\n", lst->data);
		lst = lst -> prev;
	}
}

int	main(int argc, char *argv[])
{
	tt_list *nlist;
	tt_list	*head;

	if (argc > 2)
	{
		argv++;
		nlist = init_list(ft_atoi(*argv));
		argv++;
	}
	head = nlist;
	while (*argv)
	{
		nlist -> next = add_node(nlist, ft_atoi(*argv));
		argv++;
		nlist = nlist -> next;
	}
	print_list(head);
	print_list_back(nlist);
}
